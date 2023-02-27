# g++ -c -fPIC dl_model.cpp -I ~/libtorch/include -L ~/libtorch/lib -lc10 -ltorch -ltorch_cpu -ltorch_python -Wl,-rpath ~/libtorch/lib
# ifort -c -fPIC -shared umat_an_ai.f90
# ar -cr umat.o umat_an_ai.o dl_model.o ~/libtorch/lib/*
# # use archive to create umat.o object. include .o files and libtorch library
# # then link to create libdl_model.so
# g++ -shared -fPIC -o libdl_model.so umat.o -L ~/libtorch/lib -lc10 -ltorch -ltorch_cpu -ltorch_python -Wl,-rpath ~/libtorch/lib
# mv umat.o ..
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/libtorch/lib
#compile dl_model.cpp. rpath is needed to find libtorch library
g++ -c -fPIC dl_model.cpp -I ~/libtorch/include -L ~/libtorch/lib #-Wl,-rpath ~/libtorch/lib # -lc10 -ltorch -ltorch_cpu -ltorch_python  
#compile fortran code. -shared is needed to create a shared library
ifort -c -fPIC -shared umat_an_ai.f90
#use archive to create umat.o object. include .o files and libtorch library
ar -cr umat.o umat_an_ai.o dl_model.o ~/libtorch/lib/*
#then link to create object file
#g++ -shared -fPIC -o libdl_model.so umat.o -L ~/libtorch/lib -lc10 -ltorch -ltorch_cpu -ltorch_python -Wl,-rpath ~/libtorch/lib
#move umat.o to parent directory
mv umat.o ..

