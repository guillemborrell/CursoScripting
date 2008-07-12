from numpy import *

def gendata():
    f=lambda x:1/(1+2*exp(-x))
    return (linspace(-4,4,100),
            f(linspace(-4,4,100))+0.2*random.rand(100))
