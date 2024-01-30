#include "nanobind/nanobind.h"
#include "nanobind/stl/vector.h"

std::vector<int> double_it(const std::vector<int> &in) {
    std::vector<int> out(in.size());
    for (size_t i; i < in.size(); ++i) {
        out[i] = in[i] * 2;
    }
    return out;
}

void mutate_double_it(std::vector<int> &in) {
    for (size_t i; i < in.size(); ++i)
        in[i] *= 2;
}

NB_MODULE(ext_math, m) {
    m.def("double_it", &double_it);
    m.def("mutate_double_it", &mutate_double_it);
}