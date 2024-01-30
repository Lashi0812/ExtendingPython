#include "nanobind/nanobind.h"

namespace nb = nanobind;

nb::list double_it(nb::list l) {
    nb::list res;
    for (nb::handle h:l) {
        res.append(h * nb::int_(2));
    }
    return res;
}

NB_MODULE(ei_wrapper, m) {
    m.def("double_it", &double_it);
}