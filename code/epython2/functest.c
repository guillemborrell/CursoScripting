void qdelaunay(int DIM,const double *points,long *triangles)
{
  long SIZEcube, SIZEdiamond, TOTpoints;
  long i,j,ng,numpoints;
  coordT *coordpoints;
  coordT *rows;

  boolT ismalloc=False;
  char flags[]="qhull s d Tcv n Qt";
  FILE *outfile = stdout;
  FILE *errfile = stderr;

  int exitcode;

  facetT *facet;
  vertexT *vertex, **vertexp;
  long curlong,totlong;

  printf( "\ncompute %d-d Delaunay triangulation\n", dim);

/*   First step. configure the qhull setting the constants properly. */
/*   The bit shifting for setting SIZEcube is odd, I don't know what */
/*   does so I just don't touch it.  Most of the macros are turned into */
/*   expressions so it may brake things up. */

  SIZEcube = 1<<DIM;
  numpoints = SIZEcube;
  SIZEdiamond = 2*DIM;
  TOTpoints = SIZEcube+ SIZEdiamond;

  exitcode = qh_new_qhull(DIM, numpoints, points, ismalloc,
			  flags, NULL, errfile);

  if (!exitcode){
    nf=0;
    FORALLfacets{
      if (!facet->upperdelaunay) nf++;
      if (!facet->simplicial){
	printf("error qhull: non simplicial facet");
      }
    }

    printf("nf= %i\n",nf);

    triangles = (long *) malloc(numpoints*DIM*sizeof(long));

    FORALLfacets{
      if (!facet->upperdelaunay){
	j=0;
	FOREACHvertex_ (facet->vertices){
	  if(j > DIM){
	    printf("error qhull:");
	  }
	  *triangles  = qh_pointid(vertex->point);
	  triangles++;
	}
	i++;
      }
    }

    qh_freeqhull(!qh_ALL);
    qh_memfreeshort(&curlong,&totlong);

}

