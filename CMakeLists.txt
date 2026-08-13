cmake_minimum_required(VERSION 4.2)
project(Profiler)

set(CMAKE_CXX_STANDARD 20)

add_library(profiler
        src/Timer.cpp
        src/ScopedTimer.cpp
        src/Profiler.cpp
        src/ConsoleSink.cpp)

target_include_directories(profiler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(Profiler main.cpp)

target_link_libraries(Profiler PRIVATE profiler)
