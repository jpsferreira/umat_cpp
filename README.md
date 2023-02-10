# umat_cpp


## Requirements
- cmake (https://cmake.org/install/)
- libtorch (https://pytorch.org/get-started/locally/)
- nvidia-cuda-toolkit (nvcc)
- nvidia-cudnn
- g++ (https://gcc.gnu.org/install/)
- gfortran (https://gcc.gnu.org/wiki/GFortranBinaries)


## build executable
go to build directory and run cmake

```zsh
CMAKE_PREFIX_PATH = ~/libtorch
cmake -DCMAKE_PREFIX_PATH=path/to/libtorch -DCMAKE_Fortran_COMPILER=gfortran ..
cmake --build . --config Release
```

## run example

```zsh
./example-app /path/to/traced_model.pt
```
