from numpy.distutils.core import (setup, Extension)

module1 = Extension('test',sources=['testmodule.c'])

setup (name='test module package',
       version='0.1',
       description='test module',
       ext_modules = [module1])
