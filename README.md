# umat_cpp

## Requirements
- cmake (https://cmake.org/install/)
- libtorch (https://pytorch.org/get-started/locally/)
    * download libtorch and extract to ~/libtorch
    * linux cpu version
        ```zsh
        wget https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-1.13.1%2Bcpu.zip
        unzip libtorch-shared-with-deps-latest.zip
        mv libtorch ~/libtorch
        ```
- g++ (https://gcc.gnu.org/install/)
    * g++ version >= 7.0
    * add g++ path to PATH
- gfortran (https://gcc.gnu.org/wiki/GFortranBinaries)
    * add gfortran path to PATH
- python3 (https://www.python.org/downloads/)
    * create venv and activate
    ```zsh
    python3 -m venv venv
    source venv/bin/activate
    pip install --upgrade pip
    pip install torch
    ```
- pip install [other dependencies]

## Optional
- nvidia-cuda-toolkit (nvcc)
- nvidia-cudnn

# directory tree
- dummy_umat_ts (WORKING DI)
    * dummy umat fortran and cpp code
- umat_ts (WORKING DI)
    * umat fortran and cpp code
- cube_ts (WIP, WITH COMPILE PROBLEM)
    * cube example to run Abaqus

## build executable
- go to folder directory (dummy_umat_ts, umat_ts, or cube_ts) and run cmake through CMakeLists.txt
    * add libtorch path to CMAKE_PREFIX_PATH
    * add fortran_compiler path to CMAKE_Fortran_COMPILER
    * make
```zsh
CMAKE_PREFIX_PATH=~/libtorch
cmake -DCMAKE_PREFIX_PATH=path/to/libtorch -DCMAKE_Fortran_COMPILER=/path/to/fortran_compiler ..
make
```

- bin file will be generated in bin directory
- libraries will be generated in lib directory


## compile umat

```zsh
cd cube_ts
g++ -c -fPIC dl_model.cpp -I ~/libtorch/include
IFORT_COMPILER=/path/to/fortran_compiler
ifort -c -fPIC -shared umat_an_ai.f90
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/libtorch/lib
ar -cr umat.o umat_an_ai.o dl_model.o ~/libtorch/lib/*
```
