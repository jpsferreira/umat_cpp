# stop configuration if cmake version is below 3.0
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# project name and enabled languages
project(MLumat CXX Fortran)

# find libtorch
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# if CMAKE_BUILD_TYPE undefined, set it to Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# compiler flags for release mode
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_Fortran_FLAGS_RELEASE "-O3")
# cxx compile flags -fPIC
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
# fortran compile flags -fPIC
set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fPIC")

# set default build paths
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/include)

# generated export header will be placed here
include_directories(${PROJECT_BINARY_DIR})

# fortran executable
#add_executable(umat.o src/umat_an_ai.f90)

# c library
add_library(dl_model SHARED src/dl_model.cpp)

# fortran library
add_library(umat SHARED src/umat_an_ai.f90)

# linked against c library
target_link_libraries(umat dl_model)
# linked against libtorch
target_link_libraries(dl_model "${TORCH_LIBRARIES}")
target_include_directories(dl_model PUBLIC "${TORCH_INCLUDE_DIRS}")
# 

add_library(${PROJECT_NAME} STATIC $<TARGET_OBJECTS:umat>
                                    $<TARGET_OBJECTS:dl_model>
                                    )
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)

#
# # we let cmake generate the export header
# include(GenerateExportHeader)
# generate_export_header(dl_model BASE_NAME call_ts)

# install(TARGETS dl_model umat LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
# install(FILES src/call_ts.h ${PROJECT_BINARY_DIR}/src/call_ts_export.h DESTINATION ${PROJECT_BINARY_DIR})


