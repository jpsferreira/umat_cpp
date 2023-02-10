# umat_cpp


## Requirements

- libtorch (https://pytorch.org/get-started/locally/)
- nvidia-cuda-toolkit (nvcc)
- nvidia-cudnn

## build executable
go to build directory and run cmake

```zsh
cmake -DCMAKE_PREFIX_PATH=path/to/libtorch ..
cmake --build . --config Release
```

## run example

```zsh
./example-app /path/to/traced_model.pt
```
