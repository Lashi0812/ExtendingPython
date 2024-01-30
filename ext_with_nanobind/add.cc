#include "nanobind/nanobind.h"

namespace nb = nanobind;
using namespace nb::literals;

int add(int a, int b = 1) { return a + b; }

NB_MODULE(ext_nano, m) {
    m.def("add", &add, "a"_a, "b"_a = 1);
    m.attr("export_value") = 42;
}