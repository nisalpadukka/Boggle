cmake_minimum_required(VERSION 3.22)
project(Boggle)

set(CMAKE_CXX_STANDARD 14)

include_directories(boggle_lib/src)
enable_testing()
add_subdirectory(boggle_lib/src)
add_subdirectory(boggle_lib/test)
add_subdirectory(boggle_ex/src)
add_subdirectory(external_lib/googletest)
