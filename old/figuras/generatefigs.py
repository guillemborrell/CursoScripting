from os import system

octave=['figuraejemplo1','figuraejemplo2']#sin la extension
python=['figuraejemplo3','figuraejemplo4']

for script in octave:
    system('octave %s.m'%(script))
    system('epstopdf %s.eps'%(script))
    system('rm %s.eps'%(script))
    print('*****************')
    print('figure generated for %s'%(script))
    print('*****************')

for script in python:
    system('python %s.py'%(script))
    print('*****************')
    print('figure generated for %s'%(script))
    print('*****************')

