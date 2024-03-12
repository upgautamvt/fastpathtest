cmake_minimum_required(VERSION 3.29)
project(FastPathTest LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

# Set the C and C++ compilers to clang
set(CMAKE_C_COMPILER "clang-18")

# Common compile flags
set(COMMON_FLAGS "-O0 -g -Wall -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS}")

# Use lld as linker
set(CMAKE_EXE_LINKER_FLAGS "--ld-path=ld.lld-18 ${CMAKE_EXE_LINKER_FLAGS}")

# version 1: hardcoded
## Define two executables: one sanitized, one not
#add_executable(HelloWorld HelloWorld.c) # Not-sanitized version
#add_executable(HelloWorld_sanitized HelloWorld.c) # Sanitized version
#
## Sanitizer flags
#set(SANITIZE_FLAGS "-fsanitize=address,undefined -fno-omit-frame-pointer")
#string(REPLACE " " ";" SANITIZE_FLAGS "${SANITIZE_FLAGS}")
## Apply sanitizer flags only to the sanitized target
#target_compile_options(HelloWorld_sanitized PRIVATE ${SANITIZE_FLAGS})
#target_link_options(HelloWorld_sanitized PRIVATE ${SANITIZE_FLAGS})

# version 2: using GLOB to include any named files
# Find all .c files in the directory
file(GLOB SOURCE_FILES "*.c")

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    # Define non-sanitized executable
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE}) # Not-sanitized version

    # Define sanitized executable
    add_executable(${EXECUTABLE_NAME}_sanitized ${SOURCE_FILE}) # Sanitized version

    # Sanitizer flags
    set(SANITIZE_FLAGS "-fsanitize=address,undefined -fno-omit-frame-pointer")
    string(REPLACE " " ";" SANITIZE_FLAGS "${SANITIZE_FLAGS}")
    # Apply sanitizer flags only to the sanitized target
    target_compile_options(${EXECUTABLE_NAME}_sanitized PRIVATE ${SANITIZE_FLAGS})
    target_link_options(${EXECUTABLE_NAME}_sanitized PRIVATE ${SANITIZE_FLAGS})
endforeach()

# after this , to configure and generate build system, do  "cmake -S . -B build"
# And to build your project, navigate to build directory and run "cmake --build ." or directly use "cmake --build build" if you are in parent (not build) directory
