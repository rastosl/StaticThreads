# CMakeList.txt : CMake project for App, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(StaticThreads)

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME}
	sub::SingletonWithThread
)

# TODO: Add tests and install targets if needed.
