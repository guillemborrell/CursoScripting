from os.path import walk,realpath,join
from os import system,chdir
from sys import argv

def executeinkscape(format,dir,fnames):

    for file in fnames:
        if 'svg' in file:
            root = realpath('.')
            chdir(join(root,dir))
            system('inkscape %s --export-%s=%s'%(file,
                                                 format,
                                                 file.replace('svg',format))
                   )
            chdir(root)


if __name__ == '__main__':
    print "Convirtiendo figuras a %s \n"%(argv[1])
    walk('.',executeinkscape,argv[1])
                   
                  
