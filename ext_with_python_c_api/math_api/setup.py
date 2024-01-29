from setuptools import setup,Extension
setup(name="my_math",ext_modules=[Extension(name="my_math",sources=["math.cc"])])