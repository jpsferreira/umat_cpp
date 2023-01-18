# umat_cpp


## Requirements

- libtorch
- nvidia-cuda-toolkit (nvcc)
- nvidia-cudnn

## build executable

```zsh
cmake -DCMAKE_PREFIX_PATH=path/to/libtorch ..
cmake --build . --config Release
```

## run example

```zsh
./example-app /path/to/traced_model.pt
```
