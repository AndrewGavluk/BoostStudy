cmake_minimum_required (VERSION 3.12)
project(lexical_cast)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.45.0 COMPONENTS) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(string_algoritms main.cpp) 
    target_link_libraries(string_algoritms ${Boost_LIBRARIES})
endif()