cmake_minimum_required(VERSION 3.13)  # CMake version check
project(myCar)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp Brake.cpp Car.cpp Engine.cpp Transmission.cpp Wheel.cpp APart.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(myCar ${SOURCE_FILES})