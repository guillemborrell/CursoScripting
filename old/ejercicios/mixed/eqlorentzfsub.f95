subroutine eqlorentzfsub(x,xdot)
  real(8),dimension(:),intent(in) :: x
  real(8),dimension(:),intent(out) :: xdot

  real(8) :: a=10d0,b=28d0
  real(8) :: c

  c=8d0/3d0

  xdot(1)= a*(x(2)-x(1))
  xdot(2)= x(1)*(b-x(3)-x(2))
  xdot(3)= x(1)*x(2)-c*x(3)
end subroutine eqlorentzfsub
