g++ -c detc.cpp -o detc.o &
gfortran -c umat_an_ai.f90 -o umat_an_ai.o &
gfortran -c an_ai.f90 -o an_ai.o &
gfortran detc.o umat_an_ai.o an_ai.o  -o an_ai  -lstdc++