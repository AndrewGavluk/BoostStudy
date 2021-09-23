cmake_minimum_required (VERSION 3.12)
project(array14)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(array14 main.cpp) 
    target_link_libraries(array14  ${Boost_LIBRARIES}) 
endif()
