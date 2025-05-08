cmake_minimum_required(VERSION 3.30)
project(Book_cpp)

set(CMAKE_CXX_STANDARD 26)

add_executable(entrainement_cpp
        main.cpp
        livres.cpp
        membres.cpp
        emprunts.cpp
)
