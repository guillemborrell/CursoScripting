#include "Python.h"
#include "numpy/arrayobject.h"
#include "numpy/ndarrayobject.h"
#include "numpy/noprefix.h"

#include "qhull/qhull_a.h"

#include <stdio.h>

char qh_version[]="qhullmodule.c 2007-4-6";//This is a hack

static PyObject *qhull_delaunayn(PyObject *self, PyObject *args)
{
  long i=0;
  long j=0;
  long nf=0;
  long nd;
  long dim;
  char *options;
  PyArrayObject *array;
  PyArrayObject *retarray;
  double *pt_array;
  long *simpl;

/*   Variables used for calling qhull */

  boolT ismalloc;
  int exitcode;
  char flags[] = "qhull Tv";
  facetT *facet;
  vertexT *vertex, **vertexp;
  int curlong, totlong;
  long size[2];

  printf("hola0\n");
  
  if (!PyArg_ParseTuple(args, "Ois", &array,&nd,&options))
    return NULL;

  pt_array = (double *) PyArray_BYTES(array);

  printf("%d\n",*pt_array);
  dim = PyArray_DIM(array,0);


/*   Calling qhull */

  ismalloc = False;

  exitcode = qh_new_qhull (nd,dim,pt_array,ismalloc,flags,NULL,stderr);

  if(exitcode)
    {
      printf("delaunayn: qhull failed");
      return Py_BuildValue("i",0);
    }

  printf("hola1\n");
  
  qh_triangulate();

  printf("hola2\n");

  FORALLfacets
    {
      if(!facet->upperdelaunay) nf++;
      if(!facet->simplicial)
	{
	  printf("delaunayn: Qhull returned non-simplicial facets.\n\
Try delaunayn with different options.");
	  break;
	}
    }
  size[0]=nf;
  size[1]=nd+1;

  if (!exitcode)
    {
      retarray = (PyArrayObject *)PyArray_SimpleNew(2,size,PyArray_LONG);
      FORALLfacets
	{
	  if (!facet->upperdelaunay)
	    {
	      j=0;
	      FOREACHvertex_ (facet->vertices)
		{
		  if (j > dim)
		    {
		      printf("delaunayn: internal error");
		      return Py_BuildValue("i",0);
		    }
		  simpl = (long *) PyArray_GETPTR2(retarray,i,j++);
		  *simpl = 1 + qh_pointid(vertex->point);
		}
	      i++;
	    }
	}
      return Py_BuildValue("O", retarray);
    }
  qh_freeqhull(!qh_ALL);
  qh_memfreeshort(&curlong, &totlong);
  
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
