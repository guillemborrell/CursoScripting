from numpy.distutils.core import (setup, Extension)

module1 = Extension('testarray',sources=['testarraymodule.c'])

setup (name='Test array module package',
       version='0.1',
       description='testarray module',
       ext_modules = [module1])
