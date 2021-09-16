cmake_minimum_required (VERSION 3.12)
project(multiIndex13)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(bimap13 main.cpp)
    add_library(animal libs/animal.hpp libs/animal.cpp)
    target_link_libraries(bimap13  ${Boost_LIBRARIES} animal)
endif()
