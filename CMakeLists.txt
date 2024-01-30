cmake_minimum_required(VERSION 3.15...3.27)
project(ext_nanobind LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(Python_EXECUTABLE "/root/miniconda3/envs/extend/bin/python")
# set(CMAKE_CUDA_USE_RESPONSE_FILE_FOR_INCLUDES 0)
# set(CMAKE_COLOR_DIAGNOSTICS ON)

find_package(Python 3.8 COMPONENTS Interpreter Development.Module REQUIRED)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party/nanobind)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ext_with_nanobind)