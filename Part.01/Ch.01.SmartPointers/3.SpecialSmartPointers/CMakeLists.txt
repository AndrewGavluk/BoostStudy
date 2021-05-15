cmake_minimum_required (VERSION 3.12)

project( special_pointes)

add_library( complex STATIC Complex.hpp Complex.cpp)

if(MSVC)
	target_compile_options(complex PRIVATE /W4)
else()
	target_compile_options(complex PRIVATE -Wall -Wextra -Werror)
endif()

add_executable(special_pointes main.cpp)

target_link_libraries(special_pointes PRIVATE pthread complex)

if(MSVC)
	target_compile_options(special_pointes PRIVATE /W4)
else()
	target_compile_options(special_pointes PRIVATE -Wall -Wextra -Werror)
endif()
