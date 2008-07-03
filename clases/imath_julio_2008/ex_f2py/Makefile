FC = gfortran
CFLAGS = -c -g

all: estvert.o carga.o ccapoyo.o kglobal.o genmat.o dlusolve.o
	$(FC) -g -o a.out estvert.o carga.o ccapoyo.o kglobal.o genmat.o dlusolve.o

estvert.o: estvert.f90
	$(FC) $(CFLAGS) estvert.f90

carga.o: carga.f90
	$(FC) $(CFLAGS) carga.f90
 
kglobal.o: kglobal.f90
	$(FC) $(CFLAGS) kglobal.f90

ccapoyo.o: ccapoyo.f90
	$(FC) $(CFLAGS) ccapoyo.f90

genmat.o: genmat.f90
	$(FC) $(CFLAGS) genmat.f90

dlusolve.o: dlusolve.f90
	$(FC) $(CFLAGS) dlusolve.f90

clean:
	rm *.o
