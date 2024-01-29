#include <pybind11/pybind11.h>

template <typename T>
T add(T x, T y) {
    return x + y;
}

PYBIND11_MODULE(tmp_module, m) {
    m.doc() = "Exposing template function to python.";
    m.def("add", &add<int>);
    m.def("add", &add<float>);
    m.def("add", &add<std::string>);
}