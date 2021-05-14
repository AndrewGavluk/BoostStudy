project( sole_ownership)

add_library( complex STATIC Complex.hpp Complex.cpp)

if(MSVC)
	target_compile_options(complex PRIVATE /W4)
else()
	target_compile_options(complex PRIVATE -Wall -Wextra -Werror)
endif()

add_executable(sole_ownership main.cpp)

target_link_libraries(sole_ownership PRIVATE complex)

if(MSVC)
	target_compile_options(sole_ownership PRIVATE /W4)
else()
	target_compile_options(sole_ownership PRIVATE -Wall -Wextra -Werror)
endif()
