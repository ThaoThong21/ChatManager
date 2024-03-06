# Add httplib library directory
link_directories(${HTTPLIB_LIBRARY_DIR})
# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.12)
# Specify the project name
project(AT)

set(CMAKE_CXX_STANDARD 14)
set(SOURCES
    src/main.cpp
    src/renderHTML.h
)
add_executable(ChatManager 
                ${SOURCES})


# Add the lib/httplib directory to the CMake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/lib/httplib")

# Find httplib package
find_package(httplib REQUIRED)

# Link the httplib library to your backend executable
target_link_libraries(ChatManager PRIVATE httplib::httplib)
