cmake_minimum_required(VERSION 3.30)
project(_EDD_Proyecto1_201222010_v2_0)

set(CMAKE_CXX_STANDARD 23)

add_executable(_EDD_Proyecto1_201222010_v2_0 main.cpp
        includes/MatrizDispersa.h
        includes/Menu.h
        includes/NodeAVL.h
        includes/NodeMat.h
        src/MatrizDispersa.cpp
        src/Menu.cpp
        src/NodeAVL.cpp
        src/NodeMat.cpp)
