#include <Python.h>

int add(int x, int y) { return x + y; }

// 1. Create the func
static PyObject *py_add_two_num(PyObject *self, PyObject *args) {
    int x, y, res;
    if (!PyArg_ParseTuple(args, "ii", &x, &y))
        return NULL;
    res = add(x, y);
    return PyLong_FromLong(res);
}

static PyObject *py_add_with_default(PyObject *self, PyObject *args) {
    int x, y = 10, res;
    if (!PyArg_ParseTuple(args, "i|i", &x, &y))
        return NULL;
    res = add(x, y);
    return PyLong_FromLong(res);
}

// 2. collect all the func
static PyMethodDef py_funcs[] = {
  {"add_two_num", py_add_two_num, METH_VARARGS, "Add two numbers"},
  {"add_with_default", py_add_with_default, METH_VARARGS, "Add two numbers"},
  {NULL}};

// Define the module
static struct PyModuleDef my_math_module = {
  PyModuleDef_HEAD_INIT, "my_math", "Demo math module", -1, py_funcs};

// initialize and create module
PyMODINIT_FUNC PyInit_my_math(void) { return PyModule_Create(&my_math_module); }