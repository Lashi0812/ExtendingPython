#include "nanobind/nanobind.h"
#include "nanobind/ndarray.h"
#include <cstddef>
#include <cstdint>
#include <cstdio>

namespace nb = nanobind;

const float data[] = {1, 2, 3, 4, 5, 6, 7, 8};

template<typename T>
__global__ void mul_5(T *data){
  data[0] = data[0] * 5; 
}

void gpu_process(nb::ndarray<uint8_t, nb::shape<nb::any, nb::any>, nb::device::cuda> data) {
  mul_5<<<1,1>>>(data.data());
}

NB_MODULE(narray, m) {
    m.def("inspect", [](nb::ndarray<> a) {
        printf("Array data pointer : %p\n", a.data());
        printf("Array dimension : %zu\n", a.ndim());
        for (size_t i = 0; i < a.ndim(); ++i) {
            printf("Array shape [%zu] : %zu\n", i, a.shape(i));
            printf("Array stride [%zu] : %zu\n", i, a.stride(i));
        }
        printf(
          "Device Id = %u (cpu=%i,gpu = %i)\n",
          a.device_id(),
          int(a.device_type() == nb::device::cpu::value),
          int(a.device_type() == nb::device::cuda::value));
        printf(
          "Array dtype : int16=%i , uint32=%i ,float=%i\n",
          int(a.dtype() == nb::dtype<int16_t>()),
          int(a.dtype() == nb::dtype<uint32_t>()),
          int(a.dtype() == nb::dtype<float>()));
        
        printf("Array num of bytes : %zu\n",a.nbytes());
    });

    m.def(
      "cpu_process", [](nb::ndarray<uint8_t, nb::shape<nb::any, nb::any>, nb::device::cpu> data) {
          data(0, 0) = (uint8_t)data(0, 0) * 5;
      });

    m.def("gpu_process", &gpu_process);

    m.def("ret_numpy", []() {
        size_t shape[2] = {2, 4};
        return nb::ndarray<nb::pytorch, const float, nb::shape<2, nb::any>>(
          data, /* ndim = */ 2, shape);
    });
}