# Set the project name
project (SingletonWithThread)

# Add a library with the above sources
add_library(${PROJECT_NAME} src/SingletonWithThread.cpp src/SingletonWithThread.h src/dllexport.h)
add_library(sub::SingletonWithThread ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
