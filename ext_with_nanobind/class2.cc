#include "nanobind/nanobind.h"
#include "nanobind/stl/string.h"

namespace nb = nanobind;

struct Dog2 {
    Dog2(const std::string &name) : name(name) {}
    void        setName(const std::string &name_) { name = name_; }
    std::string getName() { return name; }
    std::string bark() const { return name + " : woof!"; }

  private:
    std::string name;
};

void init_class2(nb::module_ &m) {
    nb::class_<Dog2>(m, "Dog2")
      .def(nb::init<const std::string &>())
      .def("bark", &Dog2::bark)
      .def_prop_rw("name", &Dog2::getName, &Dog2::setName);
}
