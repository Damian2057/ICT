cmake_minimum_required(VERSION 3.17)

project(Tele_com)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tele_com main.cpp
        include/FileFactory.h
        source/FileFactory.cpp
        include/CodeWord.h
        source/CodeWord.cpp
        include/Matrix.h
        source/Matrix.cpp
        include/DecodeWord.h
        source/DecodeWord.cpp
        include/FileService.h
        source/FileService.cpp
        )

