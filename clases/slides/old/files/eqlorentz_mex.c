# include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[],int nrhs,
                 const mxArray *prhs[]){

  int a=10;
  int b=28;
  double c=8./3;
  double *x, *xdot;

  xdot = malloc(3*sizeof(double));

  x = mxGetPr(prhs[0]);
  xdot = mxGetPr(plhs[0]);

  xdot[0] = a*(x[1]-x[0]);
  xdot[1] = x[0]*(b-x[2])-x[1];
  xdot[2] = x[0]*x[1]-c*x[2];
}
