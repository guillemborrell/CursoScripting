subroutine genmat(K,E,I,L,A,phi)

  ! Esta rutina genera la matriz de rigidez para una sección de barra
  ! reticulada en ejes globales.  Sus argumentos son:
  
  ! E: Módulo Elástico
  ! I: Momento de Inercia de la sección de la barra
  ! L: Longitud de la barra
  ! A: Área de la barra
  ! phi: Ángulo de la barra respecto a la horizontal medido contrahorariamente
  
  real*8, dimension(6,6), intent(out) :: K
  real*8, intent(in) :: E,I,L,A,phi
  
  K(1,1) = (12d0*E*I/L**3)*sin(phi)**2+(E*A/L)*cos(phi)**2
  K(1,2) = (E*A/L)*cos(phi)*sin(phi)-(12d0*E*I/L**3)*cos(phi)*sin(phi)
  K(1,3) = -(6d0*E*I/L**2)*sin(phi)
  K(1,4) = -(12d0*E*I/L**3)*sin(phi)**2-(E*A/L)*cos(phi)**2
  K(1,5) = (12d0*E*I/L**3)*cos(phi)*sin(phi)-(E*A/L)*cos(phi)*sin(phi)
  K(1,6) = -(6d0*E*I/L**2)*sin(phi)
  K(2,1) = (E*A/L)*cos(phi)*sin(phi)-(12d0*E*I/L**3)*cos(phi)*sin(phi)
  K(2,2) = (E*A/L)*sin(phi)**2+(12d0*E*I/L**3)*cos(phi)**2
  K(2,3) = (6d0*E*I/L**2)*cos(phi)
  K(2,4) = (12d0*E*I/L**3)*cos(phi)*sin(phi)-(E*A/L)*cos(phi)*sin(phi)
  K(2,5) = -(E*A/L)*sin(phi)**2-(12d0*E*I/L**3)*cos(phi)**2
  K(2,6) = (6d0*E*I/L**2)*cos(phi)
  K(3,1) = -(6d0*E*I/L**2)*sin(phi)
  K(3,2) = (6d0*E*I/L**2)*cos(phi)
  K(3,3) = (4d0*E*I/L)
  K(3,4) = (6d0*E*I/L**2)*sin(phi)
  K(3,5) = -(6d0*E*I/L**2)*cos(phi)
  K(3,6) = 2d0*E*I/L
  K(4,1) = -(12d0*E*I/L**3)*sin(phi)**2-(E*A/L)*cos(phi)**2
  K(4,2) = (12d0*E*I/L**3)*cos(phi)*sin(phi)-(E*A/L)*cos(phi)*sin(phi)
  K(4,3) = (6d0*E*I/L**2)*sin(phi)
  K(4,4) = (12d0*E*I/L**3)*sin(phi)**2+(E*A/L)*cos(phi)**2
  K(4,5) = (E*A/L)*cos(phi)*sin(phi)-(12d0*E*I/L**3)*cos(phi)*sin(phi)
  K(4,6) = (6d0*E*I/L**2)*sin(phi)
  K(5,1) = (12d0*E*I/L**3)*cos(phi)*sin(phi)-(E*A/L)*cos(phi)*sin(phi)
  K(5,2) = -(E*A/L)*sin(phi)**2-(12d0*E*I/L**3)*cos(phi)**2
  K(5,3) = -(6d0*E*I/L**2)*cos(phi)
  K(5,4) = (E*A/L)*cos(phi)*sin(phi)-(12d0*E*I/L**3)*cos(phi)*sin(phi)
  K(5,5) = (E*A/L)*sin(phi)**2+(12d0*E*I/L**3)*cos(phi)**2
  K(5,6) = -(6d0*E*I/L**2)*cos(phi)
  K(6,1) = -(6d0*E*I/L**2)*sin(phi)
  K(6,2) = (6d0*E*I/L**2)*cos(phi)
  K(6,3) = 2d0*E*I/L
  K(6,4) = (6d0*E*I/L**2)*sin(phi)
  K(6,5) = -(6d0*E*I/L**2)*cos(phi)
  K(6,6) = (4d0*E*I/L)

  ! Y llegados aquí todos se preguntan... Guillem. ¿Cómo haces para escribir
  ! estos cipotes y no equivocarte? Pues no escribiendolos

end subroutine genmat

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


!*****************

subroutine lubksb(a,indx,b,n)
  implicit none
  integer, intent(in) :: n
  real*8, dimension(n,n), intent(in) ::a
  integer, dimension(n), intent(in) :: indx
  real*8, dimension(n), intent(inout) :: b
  
  integer :: i,ii,ll
  real*8:: summ
  
  ii=0
  do i=1,n
     ll=indx(i)
     summ=b(ll)
     b(ll)=b(i)
     if (ii /= 0) then
        summ = summ-dot_product(a(i,ii:i-1),b(ii:i-1))
     else if (summ /= 0d0) then
        ii=i
     end if
     b(i)=summ
  end do
  do i=n,1,-1
     b(i)=(b(i)-dot_product(a(i,i+1:n),b(i+1:n)))/a(i,i)
  end do
  
end subroutine lubksb

!***************

subroutine ludcmp(a,indx,d,n)
  
  implicit none
  
  integer, intent(in) :: n
  real*8, dimension(n,n), intent(inout) :: a
  integer, dimension(n), intent(out) :: indx
  real*8, intent(out) :: d
  
  real*8, dimension(n) :: vv
  integer :: j,imax
  
  d=1d0
  vv=maxval(abs(a),dim=2)
  do j=1,n
     imax=(j-1)+maxloc(vv(j:n)*abs(a(j:n,j)),1)
     
     if (j /= imax) then
        call swap(a(imax,:),a(j,:),n)
        d=-d
        vv(imax)=vv(j)
     end if
     indx(j)=imax
     a(j+1:n,j)=a(j+1:n,j)/a(j,j)
     a(j+1:n,j+1:n)=a(j+1:n,j+1:n)-spread(a(j+1:n,j),dim=2,ncopies=n-j)*&
          spread(a(j,j+1:n),dim=1,ncopies=n-j)
  end do
  
end subroutine ludcmp

!**********************

subroutine swap(a,b,n)
  implicit none
  integer, intent(in) :: n
  real*8, dimension(n), intent(inout) :: a,b
  
  real*8 :: sav
  integer :: i
  
  do i=1,n
     sav=a(i)
     a(i)=b(i)
     b(i)=sav
  end do
  
end subroutine swap

subroutine dlusolve(a,b,n)
  integer, intent(in) :: n
  real*8, dimension(n,n), intent(inout) :: a
  real*8, dimension(n), intent(inout) :: b
  
  integer, dimension(n) :: indx
  real*8 :: d
  
  call ludcmp(a,indx,d,n)
  call lubksb(a,indx,b,n)
  
end subroutine dlusolve

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
  

