cmake_minimum_required (VERSION 3.12)
project(spirit)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.62.0) 

add_definitions( -DBOOST_SPIRIT_USE_PHOENIX_V3=1)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(spirit main.cpp)
    add_library(BasicParser libs/BasicParser.hpp libs/BasicParser.cpp)
    target_link_libraries(spirit ${Boost_LIBRARIES} BasicParser) 
endif()
