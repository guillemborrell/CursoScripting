#include "qhull/qhull_a.h"

char qh_version[]="0.1";


int *wqdelaunay(double *points, int numpoints, int dim){
  int i,j,k;
  coordT *cpoints;
  boolT ismalloc= False;    
  char flags[]="qhull s d Tcv n Qt";
  int *ret;

  FILE *errfile= stderr;   

  int exitcode;            
  facetT *facet;	  
  vertexT *vertex, **vertexp;
  int curlong, totlong;	  
  int nf;

  /*casting the point list to the internal type*/
  cpoints = (coordT *) points;


  printf( "\ncompute %d-d Delaunay triangulation\n", dim);

  exitcode= qh_new_qhull (dim, numpoints, cpoints, ismalloc,
                      flags, NULL, errfile); 
  if (!exitcode) {
    nf=0;
    FORALLfacets{
      if (!facet->upperdelaunay) nf++;
      if (!facet->simplicial){
	printf("error: non simplicial facet");
      }
    }


    printf("Number of facets %i\n",nf);
    printf("Number of points %i\n",numpoints);

    /*Trick, the number of facets and the point numbers
      are returned in the same return value. qhull has
      a weird memory management and this was the only
      way to return a value */
    
    ret = (int *) malloc((nf*(dim+1)+1)*sizeof(int));

    /*Number of facets is the first return value*/
    ret[0]=nf;
    k=1;

    FORALLfacets{
      if (!facet->upperdelaunay){
	j=0;
	FOREACHvertex_ (facet->vertices){
	  if(j > dim){
	    printf("error delaunayn:");
	  }
	  ret[k] = qh_pointid(vertex->point);
	  k++;
	}
	i++;
      }
    }
  }
  qh_freeqhull(!qh_ALL);                 
  qh_memfreeshort (&curlong, &totlong);  
  if (curlong || totlong){
    fprintf (errfile, "qhull internal warning (user_eg, #2):\
 did not free %d bytes of long memory (%d pieces)\n",\
	     totlong, curlong);
  }

  /*recovering the triangles pointer*/


  if (exitcode) return NULL;
  if (!exitcode)return ret;
}
/*
  The following is a little program to test the function
*/

int main(int argc, char *argv[]){

  int *rc;

  double points[]={+0.659,0.329,-0.585,\
		   -0.219,-0.587,-0.728,\
		   0.478,-0.47,-0.914,\
		   0.934,0.245,0.751,\
		   0.352,-0.344,-0.26,\
		   0.977,-0.115,-0.926,\
		   0.781,-0.329,-0.903,\
		   -0.886,0.693,0.908};
  int numpoints=8;
  int dim=3;
  
  rc=wqdelaunay(points,numpoints,dim);
  printf("successful,%i\n\n",*rc);

  return 0;

}


