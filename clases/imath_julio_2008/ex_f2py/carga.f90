subroutine carga(p,b,n,nnodo,componente)

! Esta subrutina modifica el vector de cargas dadas los siguientes
! argumentos:

! p: valor de la carga
! b: vector de cargas
! n: número de nodos de la estructura
! nnodo: número del nodo al que se aplica la carga
! componente: componente a la que se aplica la carga
!   1: componente x
!   2: componente y
!   3: Momento en z

integer, intent(in) :: n,nnodo,componente
real*8, intent(in) :: p
real*8, dimension(3*n), intent(inout) :: b

b(3*(nnodo-1)+componente)=p

end subroutine carga
