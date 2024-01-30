#include "nanobind/nanobind.h"
#include "nanobind/stl/string.h"

namespace nb = nanobind;

struct Dog {
    std::string name;
    int64_t     age;
    std::string bark() const { return name + " : woof!"; }
};

void init_class1(nb::module_ &m) {
    nb::class_<Dog>(m, "Dog1")
      .def(nb::init<>())
      .def(nb::init<const std::string &, const int64_t>())
      .def("bark", &Dog::bark)
      .def_rw("name", &Dog::name)
      .def_rw("age", &Dog::age);
}
