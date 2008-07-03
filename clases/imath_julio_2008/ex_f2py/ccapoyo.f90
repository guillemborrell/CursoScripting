subroutine ccapoyo(K,b,n,nnodo,componente)

! Esta subrutina modifica la matriz de rigidez del sistema y el
! vector de cargas para introducir condiciones de contorno de
! apoyo en un nodo según una dirección.  Los argumentos son:

! K: Matriz de rigidez
! b: vector de cargas
! n: número de nodos de la estructura
! componente: componente sobre la que se ejecuta la carga
!   1: dirección según x
!   2: dirección según y
!   3: momento según z

integer, intent(in) :: n,nnodo,componente
real*8, dimension(3*n,3*n), intent(inout) :: K
real*8, dimension(3*n), intent(inout) :: b

K(3*(nnodo-1)+componente,:)=0
K(:,3*(nnodo-1)+componente)=0
K(3*(nnodo-1)+componente,3*(nnodo-1)+componente)=1
b(3*(nnodo-1)+componente)=0

end subroutine ccapoyo
