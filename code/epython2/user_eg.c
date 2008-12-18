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


#include "qhull/qhull_a.h"

char qh_version[]="0.1";


#define DIM 3     /* dimension of points, must be < 31 for SIZEcube */
#define SIZEcube (1<<DIM)
#define SIZEdiamond (2*DIM)
#define TOTpoints (SIZEcube + SIZEdiamond)


int main (int argc, char *argv[]) {
  long i,j;
  long nf;
  int dim= DIM;	            /* dimension of points */
  long numpoints;            /* number of points */
  coordT points[(DIM+1)*TOTpoints]={+0.659,0.329,-0.585,-0.219,-0.587,-0.728,0.478,-0.47,-0.914,0.934,0.245,0.751,0.352,-0.344,-0.26,0.977,-0.115,-0.926,0.781,-0.329,-0.903,-0.886,0.693,0.908}; /* array of coordinates for each point */
  coordT *rows[TOTpoints];
  boolT ismalloc= False;    /* True if qhull should free points in qh_freeqhull() or reallocation */
  char flags[]="qhull s d Tcv n Qt";          /* option flags for qhull, see qh_opt.htm */
  FILE *outfile= stdout;    /* output from qh_produce_output()
			       use NULL to skip qh_produce_output() */
  FILE *errfile= stderr;    /* error messages from qhull code */
  int exitcode;             /* 0 if no error from qhull */
  facetT *facet;	    /* set by FORALLfacets */
  vertexT *vertex, **vertexp;
  int curlong, totlong;	    /* memory remaining after qh_memfreeshort */
  long *triangles;


  printf( "\ncompute %d-d Delaunay triangulation\n", dim);
  numpoints= SIZEcube;
  printf("numpoints,%i\n",numpoints);

/*   for (i=numpoints; i--; ) */
/*     rows[i]= points+dim*i; */
/*   qh_printmatrix (outfile, "input", rows, numpoints, dim); */
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

    printf("Number of facets %i\n",nf);
    printf("Number of points %i\n",SIZEcube);
    
    triangles = (long *) malloc(nf*(dim+1)*sizeof(long));

    FORALLfacets{
      if (!facet->upperdelaunay){
	j=0;
	FOREACHvertex_ (facet->vertices){
	  if(j > dim){
	    printf("error delaunayn:");
	  }
	  *triangles = qh_pointid(vertex->point);
	  printf("%i\n",*triangles);
	  triangles++;
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
