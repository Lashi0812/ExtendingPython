#include "nanobind/nanobind.h"
#include "nanobind/stl/bind_vector.h"
#include <vector>

namespace nb = nanobind;

std::vector<int> double_it(std::vector<int> &in) {
    for (size_t i; i < in.size(); ++i)
        in[i] *= 2;
    return in;
}

NB_MODULE(ei_binding, m) {
    nb::bind_vector<std::vector<int>>(m, "IntVector");
    m.def("double_it", &double_it);
}