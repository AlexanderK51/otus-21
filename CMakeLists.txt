cmake_minimum_required(VERSION 3.5)

project (ipsort)

add_executable(
    ipsort
    main.cpp
    ipsort.hpp
)
set_target_properties(ipsort PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)