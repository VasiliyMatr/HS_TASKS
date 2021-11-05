
cmake_minimum_required( VERSION 3.11 )

project( risc-v-core VERSION 0.1 )

set( EXEC_NAME "core" )
add_executable( ${EXEC_NAME} )

target_compile_features( ${EXEC_NAME} PRIVATE cxx_std_20 )

target_include_directories( ${EXEC_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/headers" )
target_sources( ${EXEC_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/sources/core-main.cc"
    "${CMAKE_SOURCE_DIR}/sources/core.cc"
    "${CMAKE_SOURCE_DIR}/codegen/dec.cc"
)

set( COMMON_COMPILE_FLAGS -Wall -Wpedantic -Wextra -Werror )
set( DEBUG_COMPILE_FLAGS -g -O0 )

target_compile_options( ${EXEC_NAME} PRIVATE
    ${COMMON_COMPILE_FLAGS}
    ${DEBUG_COMPILE_FLAGS}
)
