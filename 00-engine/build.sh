
export LIBRARY_PATH=/home/roharui/Projects/raylib/raylib-library

if [ "exec" == $1 ]; then
  CMAKE_ARG=RUNTIME_EXEC
  BUILD_PATH=
elif [ "lib" == $1 ]; then
  CMAKE_ARG=RUNTIME_LIB
  BUILD_PATH=lib
elif [ "test" == $1 ]; then
  CMAKE_ARG=RUNTIME_TEST
  BUILD_PATH=test
fi

cmake -S . -B build/$BUILD_PATH -G Ninja -D${CMAKE_ARG}=1
cmake --build build/$BUILD_PATH
