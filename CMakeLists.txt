cmake_minimum_required (VERSION 3.20)

project (demo)

set(CMAKE_C_COMPILER /opt/opencode/linaro/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER /opt/opencode/linaro/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -O0 -g -fprofile-arcs -ftest-coverage")

set(src_c src/test.cpp)

include_directories (./include)

add_executable(${PROJECT_NAME}_bin ${src_c})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

# install(TARGETS ${PROJECT_NAME}_bin RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)