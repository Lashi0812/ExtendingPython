#include <pybind11/pybind11.h>
#include <string>

int add_two_num(int x, int y) { return x + y; }

struct Human {
    std::string name;
    Human(const std::string &name) : name(name) {}
    void              setName(const std::string &name_) { name = name_; }
    const std::string getName() { return name; }
};

PYBIND11_MODULE(ext_module, m) {
    m.doc() = "Extending python using pybind11";
    m.def("add", &add_two_num, "Add Two integer");

    pybind11::class_<Human>(m, "Human")
      .def(pybind11::init<const std::string &>()) //? constructor
      .def(
        "setName",
        &Human::setName) //? Exposing the setName and getName member function
      .def("getName", &Human::getName)
      .def_readwrite("name", &Human::name); //? Exposing member variable
}