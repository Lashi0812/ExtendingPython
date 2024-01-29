# Content
- [Content](#content)
- [Extending the python with pybind](#extending-the-python-with-pybind)
  - [Defining the module](#defining-the-module)
  - [Binding C++](#binding-c)
  - [Compile Code to Shared library](#compile-code-to-shared-library)
  - [Using the Compiled Shared Library in Python](#using-the-compiled-shared-library-in-python)

# Extending the python with pybind

The pybind11 library simplifies the process of creating Python bindings for C++ code. One of the key macros provided by pybind11 is `PYBIND11_MODULE`, which is used to define Python modules and expose C++ functionality to Python.

## Defining the module

Use the PYBIND11_MODULE macro to define the Python module and provide a block for defining the bindings.

```cpp
PYBIND11_MODULE(ext_module, m) {
    // Module definition goes here
}
```
`ext_module`: The name of the Python module that will be created.

`m`: An instance of the py::module class, used to define the bindings within the module.

## Binding C++ 

Inside the PYBIND11_MODULE block, use pybind11 functions and macros to expose your C++ code to Python.

Example:

```cpp
int add(int x, int y) { return x + y; }

PYBIND11_MODULE(ext_module, m) {
    m.def("add", &add, "Add Two integer");
}
```

## Compile Code to Shared library

>[!TIP]
>pybind module provide helper fn that give the flags for compiling the c++ code. 

```zsh
❯ python -m pybind11 --includes
-I/root/miniconda3/envs/extend/include/python3.10 -I/root/miniconda3/envs/extend/lib/python3.10/site-packages/pybind11/include
```
```bash
❯ python3-config --ldflags
-L/root/miniconda3/envs/extend/lib/python3.10/config-3.10-x86_64-linux-gnu -L/root/miniconda3/envs/extend/lib  -lcrypt -lpthread -ldl  -lutil -lm -lm 
```

```zsh
clang++ -shared -fPIC -std=c++17 `python -m pybind11 --includes` ext_module.cc -o ext_module.so `python3-config --ldflags`
```

## Using the Compiled Shared Library in Python

```python
❯ conda activate extend                                                  
❯ python               
Python 3.10.13 (main, Sep 11 2023, 13:44:35) [GCC 11.2.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import ext_module
>>> ext_module.add(3,2)
5 
>>> human = ext_module.Human("test")
>>> human.name
'test'
>>> human.getName()
'test'
>>> human.setName("changed")
>>> human.name
'changed'
>>> human.getName()
'changed'
```