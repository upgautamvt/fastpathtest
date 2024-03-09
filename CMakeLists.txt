cmake_minimum_required(VERSION 3.29)
project(FastPathTest LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

# Define a variable for your custom toolchain path
set(MY_LLVM_TOOLCHAIN "/opt/llvm-18.1.0-rc4/bin")

# Set the C and C++ compilers to clang
set(CMAKE_C_COMPILER "${MY_LLVM_TOOLCHAIN}/clang")

# Common compile flags
set(COMMON_FLAGS "-O0 -g -Wall -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS}")

# Use lld as linker
# Replace -fuse-ld=${MY_LLVM_TOOLCHAIN}/lld with the correct -fuse-ld=ld.lld option
set(CMAKE_EXE_LINKER_FLAGS "--ld-path=${MY_LLVM_TOOLCHAIN}/ld.lld ${CMAKE_EXE_LINKER_FLAGS}")

# Define two executables: one sanitized, one not
add_executable(HelloWorld HelloWorld.c) # Not-sanitized version
add_executable(HelloWorld_sanitized HelloWorld.c) # Sanitized version

# Sanitizer flags
set(SANITIZE_FLAGS "-fsanitize=address,undefined -fno-omit-frame-pointer")
string(REPLACE " " ";" SANITIZE_FLAGS "${SANITIZE_FLAGS}")
# Apply sanitizer flags only to the sanitized target
target_compile_options(HelloWorld_sanitized PRIVATE ${SANITIZE_FLAGS})
target_link_options(HelloWorld_sanitized PRIVATE ${SANITIZE_FLAGS})

# after this , to configure and generate build system, do  "cmake -S . -B build"
# And to build your project, navigate to build directory and run "cmake --build ." or directly use "cmake --build build" if you are in parent (not build) directory