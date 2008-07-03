subroutine kglobal(K,n,Klocal,nnode1,nnode2)

! Esta subrutina toma la matriz de rigidez en ejes globales calculada
! con la rutina genmat y la añade a la matriz de rigidez de la
! estructura completa.

! Los argumentos son:

! K: Matriz de rigidez de la estructura completa
! n: Número de nodos de la estructura
! Klocal: Matriz de rigidez de la barra (el sufijo local no significa 
! que esté en ejes locales
! nnode1: número del nodo de un extremo de la barra
! nnode2: número del nodo del otro extremo de la barra

  integer, intent(in) :: n
  integer, intent(in) :: nnode1,nnode2
  real*8, dimension(6,6), intent(in) :: Klocal
  real*8, dimension(3*n,3*n), intent(inout):: K
  
  K(3*(nnode1-1)+1:3*(nnode1-1)+3,3*(nnode1-1)+1:3*(nnode1-1)+3)=&
       K(3*(nnode1-1)+1:3*(nnode1-1)+3,3*(nnode1-1)+1:3*(nnode1-1)+3)&
       +Klocal(1:3,1:3)
  K(3*(nnode2-1)+1:3*(nnode2-1)+3,3*(nnode2-1)+1:3*(nnode2-1)+3)=&
       K(3*(nnode2-1)+1:3*(nnode2-1)+3,3*(nnode2-1)+1:3*(nnode2-1)+3)&
       +Klocal(4:6,4:6)
  K(3*(nnode2-1)+1:3*(nnode2-1)+3,3*(nnode1-1)+1:3*(nnode1-1)+3)=&
       K(3*(nnode2-1)+1:3*(nnode2-1)+3,3*(nnode1-1)+1:3*(nnode1-1)+3)&
       +Klocal(4:6,1:3)
  K(3*(nnode1-1)+1:3*(nnode1-1)+3,3*(nnode2-1)+1:3*(nnode2-1)+3)=&
       K(3*(nnode1-1)+1:3*(nnode1-1)+3,3*(nnode2-1)+1:3*(nnode2-1)+3)&
       +Klocal(1:3,4:6)


end subroutine kglobal
