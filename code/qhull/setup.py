from numpy.distutils.core import (setup, Extension)

module1 = Extension('qhull',
                    libraries=['qhull'],
                    include_dirs=['/usr/include/qhull'],
                    sources=['qhullmodule.c'])

setup (name='qhull wrapper',
       version='0.1',
       description='qhull module',
       ext_modules = [module1])
