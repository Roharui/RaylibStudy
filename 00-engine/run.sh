
export LIBRARY_PATH=/home/roharui/Projects/raylib/raylib-library

BUILD_PATH=
EXEC=rayengine

if [ "test" == $1 ]; then
  BUILD_PATH=/test
  EXEC=rayengine-test
fi

./build${BUILD_PATH}/${EXEC}
