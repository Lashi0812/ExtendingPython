# Compile ext_module
clang++ -shared -fPIC -std=c++17 `python -m pybind11 --includes` ext_module.cc -o ext_module.so `python3-config --ldflags`

# Compile template_module
clang++ -shared -fPIC -std=c++17 `python -m pybind11 --includes` template_module.cc -o tmp_module.so `python3-config --ldflags`
