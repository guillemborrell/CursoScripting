subroutine f95sub2(din,dout)
type              ::        mytype
  real*8          ::        mydouble
  integer*4       ::        myint
end type mytype
type (mytype)     ::        din , dout
dout%mydouble = din%mydouble ** float( din%myint )
dout%myint = din%myint * din%myint
end subroutine f95sub2