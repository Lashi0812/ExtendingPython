#include <Python.h>

// Creating the function in C++ using the python C API
static PyObject *hello(PyObject *self) {
    return Py_BuildValue("s", "Hello from the C++ through Python C API");
}

// Collect All Fuction on That need to expose to Python via module
static PyMethodDef hello_funcs[] = {
  {"helloWorld", (PyCFunction)hello, METH_NOARGS, "Says Hello"}, {NULL}};

// Define the module
static struct PyModuleDef hello_module = {
  PyModuleDef_HEAD_INIT,
  "hello",                        // Name of module
  "Hello module has one func : ", // doc of module
  -1,                             // size of the module or -1 for module keep in global state
  hello_funcs                     // array of func that this module has
};

// initialize the module
PyMODINIT_FUNC PyInit_hello(void) { return PyModule_Create(&hello_module); }
