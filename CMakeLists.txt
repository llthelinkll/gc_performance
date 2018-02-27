cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

project (GCPerformance)

include_directories(include)

set(SOURCES src/object.cpp src/array.cpp src/dictionary.cpp src/value.cpp src/integer.cpp src/string.cpp)

add_library(gc_performance SHARED ${SOURCES})

add_executable(main src/main.cpp)

target_link_libraries(main gc_performance gc)

