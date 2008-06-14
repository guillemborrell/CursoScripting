#!/bin/bash

i686-pc-linux-gnu-gcc -I/usr/include/qhull -I/usr/lib/python2.4/site-packages/numpy/core/include -I/usr/include/python2.4 -pthread -lqhull -lpython2.4 -o qhullmodule.so qhullmodule.c
