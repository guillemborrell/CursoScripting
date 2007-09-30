#include <iostream>
#include <oct.h>
int main(void)
{
  Matrix a = Matrix (2,2);
  ColumnVector b = ColumnVector(2);
  a(0,0)=2.;a(1,0)=5.;
  a(0,1)=-6.;a(1,1)=3.;
  b(0)=1.;b(1)=0.;

  std::cout  << a.solve(b);
  return 0;
}
