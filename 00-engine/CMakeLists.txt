cmake_minimum_required(VERSION 3.14)

project(rayengine VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)

SET(CMAKE_CXX_STANDARD 17)

file(GLOB MY_SRCS ${PROJECT_SOURCE_DIR}/src/**/*.cpp)
set(MY_SRCS ${MY_SRCS} ${PROJECT_SOURCE_DIR}/src/main.cpp)
set(MY_INCLUDES ${PROJECT_SOURCE_DIR}/include)
set(MY_LINK_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(MY_LIBS raylib)

# srcs
add_executable(${PROJECT_NAME} ${MY_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC ${MY_INCLUDES})

target_link_directories(${PROJECT_NAME} PUBLIC ${MY_LINK_DIRECTORY})
target_link_libraries(${PROJECT_NAME} ${MY_LIBS})

# lib
if(RUNTIME_LIB)
  set(MY_SRCS_MINUS_MAIN ${MY_SRCS})
  list(REMOVE_ITEM MY_SRCS_MINUS_MAIN ${PROJECT_SOURCE_DIR}/src/main.cpp)

  add_library(
    ${PROJECT_NAME}
    ${MY_SRCS_MINUS_MAIN}
  )

  target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${MY_INCLUDES}
  )

  target_link_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${MY_LINK_DIRECTORY}
  )

  target_link_libraries(
    ${PROJECT_NAME}
    ${MY_LIBS}
  )

# tests
elseif(RUNTIME_TEST)
  set(MY_SRCS_MINUS_MAIN ${MY_SRCS})
  list(REMOVE_ITEM MY_SRCS_MINUS_MAIN ${PROJECT_SOURCE_DIR}/src/main.cpp)

  file(GLOB MY_TEST_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
  file(GLOB MY_TEST_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

  set(MY_TEST_NAME ${PROJECT_NAME}-test)

  add_executable(
    ${MY_TEST_NAME}
    ${MY_TEST_SRCS}
    ${MY_SRCS_MINUS_MAIN}
  )

  target_include_directories(
    ${MY_TEST_NAME}
    PUBLIC
    ${MY_INCLUDES}
    ${MY_TEST_INCLUDES}
  )

  target_link_directories(
    ${MY_TEST_NAME}
    PUBLIC
    ${MY_LINK_DIRECTORY}
  )

  target_link_libraries(
    ${MY_TEST_NAME}
    ${MY_LIBS}
  )
endif()
