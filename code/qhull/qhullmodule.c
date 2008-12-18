#include "Python.h"
#include "numpy/arrayobject.h"
#include "numpy/ndarrayobject.h"
#include "numpy/noprefix.h"


#include "qhull_a.h"

char qh_version[]="0.1";


static PyObject *qhull_delaunayn(PyObject *self, PyObject *args) {
  long i,j;
  long nf;
  int dim;	            /* dimension of points */
  long numpoints;            /* number of points */
  coordT *points; /* array of coordinates for each point */
  boolT ismalloc= False;    /* True if qhull should free points in qh_freeqhull() or reallocation */
  char flags[]="qhull s d Tcv n Qt";          /* option flags for qhull, see qh_opt.htm */
  FILE *outfile= stdout;    /* output from qh_produce_output()
			       use NULL to skip qh_produce_output() */
  FILE *errfile= stderr;    /* error messages from qhull code */
  int exitcode;             /* 0 if no error from qhull */
  facetT *facet;	    /* set by FORALLfacets */
  vertexT *vertex, **vertexp;
  int curlong, totlong;	    /* memory remaining after qh_memfreeshort */

  char options[20];
  PyArrayObject *array;
  PyArrayObject *retarray;
  intp size[2];
  long *simpl;
  long *triangles;


  //testing
  double *test;

  if (!PyArg_ParseTuple(args,"Ois",&array,&dim,&options))
    return NULL;
  
  points=(coordT *) PyArray_DATA(array);

  printf( "\ncompute %d-d Delaunay triangulation\n\n", dim);
  numpoints= PyArray_DIM(array,0);

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
    
    size[0]=nf;
    size[1]=dim+1;

    printf("There are %i facets\n",nf);

    retarray = (PyArrayObject *) PyArray_SimpleNew(2,size,PyArray_LONG);

    printf("here?");

    FORALLfacets{
      if (!facet->upperdelaunay){
	j=0;
	FOREACHvertex_ (facet->vertices){
	  if(j > dim){
	    printf("error delaunayn:");
	  }
	  simpl = PyArray_GETPTR2(retarray,i,j);
	  *simpl = qh_pointid(vertex->point);
	  printf("%i",*simpl);
	  j++;
	}
	i++;
      }
    }
  }

  return Py_BuildValue("s","done");
  qh_freeqhull(!qh_ALL);                 
  qh_memfreeshort (&curlong, &totlong);  
  if (curlong || totlong){
    fprintf (errfile, "qhull internal warning (user_eg, #2): did not free %d bytes of long memory (%d pieces)\n", totlong, curlong);
  }
  else return Py_BuildValue("s","qhull failed");
}

static PyMethodDef QhullMethods[] = {
  {"delaunayn",  qhull_delaunayn, METH_VARARGS,
   "Perform delaunay triangulation"},
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initqhull(void)
{
  PyObject *m;

  m = Py_InitModule("qhull", QhullMethods);

}
