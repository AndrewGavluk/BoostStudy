cmake_minimum_required (VERSION 3.12)

project(pointer_vontainer)

add_library( complex STATIC Complex.hpp Complex.cpp)

if(MSVC)
	target_compile_options(complex PRIVATE /W4)
else()
	target_compile_options(complex PRIVATE -Wall -Wextra -Werror)
endif()

add_executable(pointer_vontainer main.cpp)

target_link_libraries(pointer_vontainer PRIVATE complex)

if(MSVC)
	target_compile_options(pointer_vontainer PRIVATE /W4)
else()
	target_compile_options(pointer_vontainer PRIVATE -Wall -Wextra -Werror)
endif()
