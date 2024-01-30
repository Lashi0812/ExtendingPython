nanobind_add_module(ext_nano NOMINSIZE add.cc)
nanobind_add_module(nano_class NOMINSIZE class.cc class1.cc class2.cc)
nanobind_add_module(ext_math NOMINSIZE type_caster.cc)