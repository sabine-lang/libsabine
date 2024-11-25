cmake_minimum_required(VERSION 3.26)
project(libsabine C)

include_directories(./include)

set(CMAKE_C_STANDARD 23)

file(GLOB SABINE_SRC CONFIGURE_DEPENDS "include/*.h" "src/*.c")

add_library(sabine STATIC ${SABINE_SRC})

set(CMAKE_BUILD_TYPE Debug)

install(TARGETS sabine DESTINATION lib)

file(GLOB SABINE_HDRS CONFIGURE_DEPENDS "include/*.h")

install(FILES ${SABINE_HDRS} DESTINATION include)
