#include "nanobind/nanobind.h"
namespace nb = nanobind;

void init_class1(nb::module_ &);
void init_class2(nb::module_ &);

NB_MODULE(nano_class, m) {
    init_class1(m);
    init_class2(m);
}