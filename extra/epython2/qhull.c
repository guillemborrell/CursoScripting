/*
  user_eg.c
  sample code for calling qhull() from an application
  
  call with:

     user_eg "cube/diamond options" "delaunay options" "halfspace options"

  for example:

     user_eg                             # return summaries

     user_eg "n" "o" "Fp"                # return normals, OFF, points

     user_eg "n Qt" "o" "Fp"             # triangulated cube

     user_eg "QR0 p" "QR0 v p" "QR0 Fp"  # rotate input and return points
                                         # 'v' returns Voronoi
					 # transform is rotated for halfspaces

   main() makes three runs of qhull.

     a) compute the Delaunay triangulation of random points

     b) find the Delaunay triangle closest to a point.
*/


#include "qhull_a.h"

char qh_version[]="0.1";


void delaunayn (long dim,long numpoints,double *points,int *nf,long *triangles ) {
  long i,j;
  long nf;
  coordT pointst;
  boolT ismalloc= False;    /* True if qhull should free points in qh_freeqhull() or reallocation */
  char flags[]="qhull s d Tcv n Qt";          /* option flags for qhull, see qh_opt.htm */
  FILE *outfile= stdout;    /* output from qh_produce_output()
			       use NULL to skip qh_produce_output() */
  FILE *errfile= stderr;    /* error messages from qhull code */
  int exitcode;             /* 0 if no error from qhull */
  facetT *facet;	    /* set by FORALLfacets */
  vertexT *vertex, **vertexp;
  int curlong, totlong;	    /* memory remaining after qh_memfreeshort */


  pointst = (coordT *) points;
  printf( "\ncompute %d-d Delaunay triangulation\n", dim);
  numpoints= SIZEcube;


  exitcode= qh_new_qhull (dim, numpoints, points, ismalloc,
                      flags, NULL, errfile); 
  if (!exitcode) {
    nf=0;
    FORALLfacets{
      if (!facet->upperdelaunay) nf++;
      if (!facet->simplicial){
	printf("error: non simplicial facet");
      }
    }

    triangles = (long *)malloc(nf*dim*sizeof(long));

    FORALLfacets{
      if (!facet->upperdelaunay){
	j=0;
	FOREACHvertex_ (facet->vertices){
	  if(j > dim){
	    printf("error delaunayn:");
	  }
	  triangles++ = qh_pointid(vertex->point);
	}
	i++;
      }
    }
  }
  qh_freeqhull(!qh_ALL);                 
  qh_memfreeshort (&curlong, &totlong);  
  if (curlong || totlong){
    fprintf (errfile, "qhull internal warning (user_eg, #2): did not free %d bytes of long memory (%d pieces)\n", totlong, curlong);
  }
}
