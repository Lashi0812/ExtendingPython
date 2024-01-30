#include "nanobind/nanobind.h"

int add(int a, int b) { return a + b; }

NB_MODULE(ext_nano, m){
    m.def("add",&add);
}