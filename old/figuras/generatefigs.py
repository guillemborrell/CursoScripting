from os import system

dia=['Diagram1','Diagram2','Diagram3','Diagram4','Diagram6',
     'Diagram7','Diagram8','Diagram9','Diagram10','Diagram12',
     'Diagram13']
octave=['figuraejemplo1','figuraejemplo2','calor','calorevol']
python=['figuraejemplo3','figuraejemplo4']

for diagram in dia:
    try:
        system('dia --export=%s.eps --filter=eps %s.dia'%(diagram,diagram))
        system('epstopdf %s.eps'%(diagram))
        system('rm %s.eps'%(diagram))
        print('*****************')
        print('diagram generated for %s'%(diagram))
        print('*****************')
    except:
        print('diagram %s failed, check that dia is installed'%(diagram))

for script in octave:
    try:
        system('octave %s.m'%(script))
        system('epstopdf %s.eps'%(script))
        system('rm %s.eps'%(script))
        print('*****************')
        print('figure generated for %s'%(script))
        print('*****************')
    except:
        print('figure %s failed, check that octave is installed'%(script))

for script in python:
    try:
        system('python %s.py'%(script))
        print('*****************')
        print('figure generated for %s'%(script))
        print('*****************')
    except:
        print('figure %s failed, check that matplotlib is installed'%(script))
