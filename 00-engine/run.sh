
export LIBRARY_PATH=/home/roharui/Projects/raylib/raylib-library

if [ "exec" == $1 ]; then
  BUILD_PATH=
  EXEC=rayengine
elif [ "test" == $1 ]; then
  BUILD_PATH=/test
  EXEC=rayengine-test
fi

./build${BUILD_PATH}/${EXEC}
