cmake_minimum_required(VERSION 3.6)
project(Algorithm)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
aux_source_directory(./Ksort Ksort_dir)
aux_source_directory(./BinaryTree BinaryTree_dir)
aux_source_directory(./BinaryTree/AVLTree AVLTree_dir)
aux_source_directory(./BinaryTree/BRTree BRTree_dir)

set(SOURCE_FILES main.cpp ${Ksort_dir} ${BinaryTree_dir} ${AVLTree_dir} ${BRTree_dir})
add_executable(Algorithm ${SOURCE_FILES})