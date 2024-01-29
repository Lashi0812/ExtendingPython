from setuptools import setup, Extension

setup(name="hello", ext_modules=[Extension(name="hello", sources=["hello.cc"])])
