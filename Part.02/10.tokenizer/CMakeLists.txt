cmake_minimum_required (VERSION 3.12)
project(tokenizer10)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.45.0 COMPONENTS regex) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(tokenizer10 main.cpp) 
    target_link_libraries(tokenizer10 ${Boost_LIBRARIES})
endif()
