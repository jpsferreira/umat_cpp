g++ -c addf.cpp -o addf.o &
#g++ -c detc.cpp -o detc.o &
gfortran -c umat_dummy.f90 -o umat_dummy.o &
gfortran -c main_dummy.f90 -o main_dummy.o &
gfortran addf.o main_dummy.o umat_dummy.o  -o main  -lstdc++