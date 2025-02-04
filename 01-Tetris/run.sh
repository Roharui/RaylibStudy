
export LIBRARY_PATH=/home/roharui/Projects/raylib/raylib-library

cmake -S . -B build -G Ninja
cmake --build build

./build/raylib-study
