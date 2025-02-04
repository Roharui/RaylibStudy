#pragma once

#include <vector>
#include <map>
#include <raylib.h>

#include "position.hpp"
#include "colors.hpp"

class Block {
  public:
    Block();

    void draw(int offsetX, int offsetY);

    void move(int rows, int cols);

    void rotate();
    void undoRotation();

    std::vector<Position> GetCellPositions();
    
    int id;
    std::map<int, std::vector<Position>> cells;
  private:
    int cellSize;
    int rotationState;

    int rowOffset;
    int colOffset;

    std::vector<Color> colors;
};
