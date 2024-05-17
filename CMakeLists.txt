cmake_minimum_required(VERSION 3.27)
project(AssetClass)

set(CMAKE_CXX_STANDARD 17)

add_executable(AssetClass main.cpp
        Assets.cpp
        Assets.h
)
