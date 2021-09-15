cmake_minimum_required (VERSION 3.12)
project(multiIndex12)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(multiIndex12 main.cpp) 
    target_link_libraries(multiIndex12  ${Boost_LIBRARIES})
endif()
