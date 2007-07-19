from distutils.core import (setup, Extension)

module1 = Extension('spam',sources=['spammodule.c'])

setup (name='Spam module package',
       version='0.1',
       description='spam module',
       ext_modules = [module1])
