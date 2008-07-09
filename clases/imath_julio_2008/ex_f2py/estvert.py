from numpy import zeros
from scipy.linalg import solve
import ret

(E,I,A)=(2E11,6E-6,0.0012)
n=3

K=zeros((3*n,3*n),'d',order='FORTRAN')
b=zeros((3*n),'d',order='FORTRAN')

ret.kglobal(K,ret.genmat(E,I,1.0,A,0.0),1,2)
ret.kglobal(K,ret.genmat(E,I,1.0,A,1.04719755119660),1,3)
ret.kglobal(K,ret.genmat(E,I,1.0,A,2.09439510239320),2,3)

ret.carga(2.5E6,b,3,3,1)

ret.ccapoyo(K,b,1,1)
ret.ccapoyo(K,b,1,2)
ret.ccapoyo(K,b,2,1)
ret.ccapoyo(K,b,2,2)

print solve(K,b)
