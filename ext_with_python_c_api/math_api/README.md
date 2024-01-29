# PyArg_ParseTuple Documentation

The `PyArg_ParseTuple` function is a part of the Python C API and is used for parsing arguments passed to a C extension module's function from a Python tuple. It allows you to extract values from the tuple based on a specified format string.

```c
int PyArg_ParseTuple(PyObject *args, const char *format, ...);
```

## Parameters

- `args`: The input tuple containing the function arguments.
- `format`: A format string specifying the expected types of the arguments.
- `...`: Pointers to variables where the parsed values will be stored.

## Format Units

The `format` string consists of one or more format units, each representing the expected type of an argument. Some commonly used format units include:

- `"i"`: Integer
- `"f"`: Float
- `"s"`: String
- `"O"`: Generic Python object
- `"|"`: Indicates that the following arguments are optional.

## Usage Example

```c
PyArg_ParseTuple(args, "ii", &x, &y) // int ,int
PyArg_ParseTuple(args, "i|i", &x, &y) // int , int : second arg optional
```
