g++ -c addf.cpp -o addf.o &
gfortran -c umat_an_ai.f90 -o umat_an_ai.o &
gfortran -c an_ai.f90 -o an_ai.o &
gfortran addf.o umat_an_ai.o an_ai.o  -o an_ai  -lstdc++