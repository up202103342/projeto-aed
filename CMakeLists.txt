cmake_minimum_required(VERSION 3.23)
project(AED)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AED
        Aula.cpp
        Aula.h
        Class.cpp
        Class.h
        main.cpp
        Student.cpp
        Student.h
        UC.cpp
        UC.h)
