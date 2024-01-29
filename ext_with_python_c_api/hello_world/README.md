# Content

- [Content](#content)
  - [Extending Python through Python C API](#extending-python-through-python-c-api)
    - [Creating the Function](#creating-the-function)
    - [Collecting All Functions to Expose](#collecting-all-functions-to-expose)
    - [Defining the Module](#defining-the-module)
    - [Creating and Initializing the Module](#creating-and-initializing-the-module)

## Extending Python through Python C API

### Creating the Function

When creating functions to be exposed to Python using the Python C API, it's essential to understand the function signature and how arguments are handled. Functions should have a signature compatible with `PyObject*`, which represents a Python object.

A typical function signature might look like this:

```c
static PyObject *hello(PyObject *self) {
    return Py_BuildValue("s", "Hello from the C++ through Python C API");
}
```

### Collecting All Functions to Expose

To expose C functions to Python, you need to collect them and define their mapping to Python functions. This involves creating an array of `PyMethodDef` structures, where each structure represents a function to be exposed. Each `PyMethodDef` structure includes information such as the Python function name, C function pointer, and any additional flags or documentation.

This array serves as a blueprint for defining the module's functions, allowing Python to access them seamlessly.

```c
static PyMethodDef hello_funcs[] = {
  {"helloWorld", (PyCFunction)hello, METH_NOARGS, "Says Hello"}, {NULL}};
```

### Defining the Module

Once you have collected all the functions to expose, the next step is to create a `PyModuleDef` structure. This structure encapsulates the module's metadata, including the module name, documentation, and the array of `PyMethodDef` structures. The `PyModuleDef` structure acts as a container for organizing and defining the module's components.

```c
static struct PyModuleDef hello_module = {
  PyModuleDef_HEAD_INIT,
  "hello",                        // Name of module
  "Hello module has one func : ", // doc of module
  -1,                             // size of the module or -1 for module keep in global state
  hello_funcs                     // array of func that this module has
};
```

### Creating and Initializing the Module

After defining the `PyModuleDef` structure, the final step is to create and initialize the module. The initialization function has a specific naming convention: it should be in the format of `PyInit_modulename`. For example, if your module is named "mymodule," the initialization function would be `PyInit_mymodule`.

This initialization function should return the `PYMODINIT_FUNC` type. The `PYMODINIT_FUNC` is a macro used to declare the correct function signature for the initialization function.

Here is an example:

```c
PyMODINIT_FUNC PyInit_hello(void) { return PyModule_Create(&hello_module); }

```
