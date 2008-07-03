subroutine dlusolve(a,b,n)
integer, intent(in) :: n
real*8, dimension(n,n), intent(inout) :: a
real*8, dimension(n), intent(inout) :: b

integer, dimension(n) :: indx
real*8 :: d

call ludcmp(a,indx,d,n)
call lubksb(a,indx,b,n)

end subroutine dlusolve


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
