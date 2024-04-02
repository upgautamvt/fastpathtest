cmake_minimum_required(VERSION 3.29)
project(FastPathTest LANGUAGES C)

# If the binary directory is the same as the source directory,
# create a separate build directory
if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
endif()

# Create the build directory if it doesn't exist
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR})

# Set the output directory for build artifacts
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Set compiler and linker flags
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER "clang-18")
set(CMAKE_CXX_COMPILER "clang-18++")
set(COMMON_FLAGS "-O0 -g -Wall -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "--ld-path=ld.lld-18 ${CMAKE_EXE_LINKER_FLAGS}")

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

# Custom target for compiling and building
add_custom_target(build
        COMMAND cmake --build ${CMAKE_BINARY_DIR}
        COMMENT "Compiling and building the project"
)

# Custom target for cleaning
add_custom_target(clean_all
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
        COMMENT "Cleaning the project"
)


# cmake -S . -B build
# cmake --build build

#Now, new steps are in c_src do "cmake ." and then "make" and "make clean_all"

