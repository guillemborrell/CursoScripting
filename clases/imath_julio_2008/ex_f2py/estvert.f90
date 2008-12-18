program estvert

implicit none

! Constantes del problema

real*8, parameter :: E=2d11
real*8, parameter :: I=6d-6
real*8, parameter :: A=0.0012d0 !A puede cambiar entre barras

! Funciones

interface

   function genmat(E,I,L,A,phi)
     real*8, dimension(6,6) :: genmat
     real*8 :: E,I,L,A,phi
   end function genmat
   
end interface

! Variables
integer, parameter :: n = 3 !Número de _nodos_
real*8, dimension(3*n,3*n) :: K=0d0 !Es importante inicializar a 0
real*8, dimension(3*n) :: b=0d0

! Variables adicionales

integer :: ii


!  Resuelve la siguiente estructura reticulada apoyada:
!        o-->p
!       / \
!      /   \
!     /     \
!    /       \
!   o---------o
!   A         A

!  Hay que recordar que los ángulos son en radianes.


call Kglobal(K,n,genmat(E,I,1d0,A,0d0),1,2)
call Kglobal(K,n,genmat(E,I,1d0,A,1.04719755119660d0),1,3)
call Kglobal(K,n,genmat(E,I,1d0,A,2.09439510239320d0),2,3)

call carga(2.5d6,b,3,3,1)

call ccapoyo(K,b,3,1,1)
call ccapoyo(K,b,3,1,2)
call ccapoyo(K,b,3,2,1)
call ccapoyo(K,b,3,2,2)

call dlusolve(K,b,3*n)

do ii=1,9
   write(*,*) b(ii)
end do

end program estvert
