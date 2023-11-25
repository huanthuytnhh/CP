cmake_minimum_required(VERSION 3.26)
project(CP)

set(CMAKE_CXX_STANDARD 14)

include_directories(reCode)

add_executable(CP
        reCode/Bao.cpp
        reCode/Bao.h
        reCode/hamKhac.cpp
        reCode/hamKhac.h
        reCode/List.cpp
        reCode/List.h
        reCode/main.cpp
        reCode/menu.cpp
        reCode/menu.h
        reCode/NXB.cpp
        reCode/NXB.h
        reCode/TacGia.cpp
        reCode/TacGia.h
        reCode/TapChi.cpp
        reCode/TapChi.h
        reCode/tempCodeRunnerFile.cpp)
