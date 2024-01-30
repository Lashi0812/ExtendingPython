#include "nanobind/nanobind.h"
#include "nanobind/stl/string.h"

namespace nb = nanobind;

struct Dog {
    std::string name;
    int64_t age;
    std::string bark() const { return name + " : woof!"; }
};

NB_MODULE(nano_class, m) {
    nb::class_<Dog>(m, "Dog")
      .def(nb::init<>())
      .def(nb::init<const std::string &,const int64_t>())
      .def("bark", &Dog::bark)
      .def_rw("name", &Dog::name)
      .def_rw("age", &Dog::age);
}

