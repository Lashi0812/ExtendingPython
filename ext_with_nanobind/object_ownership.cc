#include "nanobind/nanobind.h"

namespace nb = nanobind;

struct Data {};
Data  data;
Data *getData() { return &data; };

NB_MODULE(oo_prob, m) {
    nb::class_<Data>(m, "Data");
    m.def("get_data", &getData);
}