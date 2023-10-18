cmake_minimum_required(VERSION 3.26)
project(siaod3)

set(CMAKE_CXX_STANDARD 17)

add_executable(siaod3 main.cpp
        Specialization.cpp
        Specialization.h
        HashTable.cpp
        HashTable.h
        Bucket.cpp
        Bucket.h
        FileManager.cpp
        FileManager.h
        Item.cpp
        Item.h)
