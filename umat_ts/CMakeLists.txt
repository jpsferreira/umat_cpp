# stop configuration if cmake version is below 3.0
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# project name and enabled languages
project(umat_calls_ts CXX Fortran)

# find libtorch
find_package(Torch REQUIRED)

# if CMAKE_BUILD_TYPE undefined, set it to Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# compiler flags for release mode
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# set default build paths
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# generated export header will be placed here
include_directories(${PROJECT_BINARY_DIR})

# c library
add_library(dl_model SHARED src/dl_model.cpp)
add_library(umat SHARED src/umat_an_ai.f90)
# fortran executable
add_executable(umat_calls_ts.o src/an_ai.f90 src/umat_an_ai.f90)

# linked against c library
target_link_libraries(umat_calls_ts.o dl_model)
target_link_libraries(dl_model "${TORCH_LIBRARIES}")

# we let cmake generate the export header
include(GenerateExportHeader)
generate_export_header(dl_model BASE_NAME call_ts)

install(TARGETS dl_model LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

install(FILES src/call_ts.h ${PROJECT_BINARY_DIR}/call_ts_export.h DESTINATION include)

set_property(TARGET umat_calls_ts.o PROPERTY CXX_STANDARD 14)