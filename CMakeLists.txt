cmake_minimum_required(VERSION 3.15)

project(counseling-project LANGUAGES CXX)

add_executable(counseling_exe
            "source/main.cpp"
            "source/Course.hpp"
            "source/Major.hpp"
            "source/University.hpp"
)

target_compile_features(counseling_exe PUBLIC cxx_std_17)

target_include_directories(counseling_exe PUBLIC src)

