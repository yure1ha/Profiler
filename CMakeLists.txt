cmake_minimum_required(VERSION 4.2)
project(Profiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(Profiler
        src/Profiler.cpp
        include/Profiler/Timer.h
        include/Profiler/ScopedTimer.h
        include/Profiler/ProfileEvents.h
        include/Profiler/Profiler.h
        include/Profiler/ISink.h
        include/Profiler/ConsoleSink.h
)

target_include_directories(Profiler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE Profiler)
