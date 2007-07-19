from ctypes import c_int, POINTER
import numpy as np
from numpy.ctypeslib import load_library,ndpointer

def dgesv(N,A,B):
    A = np.asfortranarray(A.astype(np.float64))
    B = np.asfortranarray(B.astype(np.float64))
    
    cN=c_int(N)
    NRHS=c_int(1)
    LDA=c_int(N)
    IPIV=(c_int * N)()
    LDB=c_int(N)
    INFO=c_int(1)

    lapack=load_library('liblapack.so','/usr/lib/')

    lapack.dgesv_.argtypes=[POINTER(c_int),POINTER(c_int),
                            ndpointer(dtype=np.float64,
                            ndim=2,
                            flags='FORTRAN'),
                            POINTER(c_int), POINTER(c_int),
                     
                            ndpointer(dtype=np.float64,
                                      ndim=2,
                                      flags='FORTRAN'),
                            POINTER(c_int),POINTER(c_int)]
                     
                     
    lapack.dgesv_(cN,NRHS,A,LDA,IPIV,B,LDB,INFO)
    return B

print dgesv(2,np.array([[2,5],[-6,3]]),np.array([[1,0]]))
