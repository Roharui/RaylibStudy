#pragma once

#include <vector>
#include <raylib.h>

#include <iostream>
#include "colors.hpp"

class Grid {
  public:
    Grid();
    void initialize();
    void print();
    void draw();
    bool IsCellOutside(int row, int col);
    bool IsCellEmpty(int row, int col);
    int ClearFullRows();

    int grid[20][10];

  private:
    bool isRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);

    int numRows;
    int numCols;
    int cellSize;

    std::vector<Color> colors;
};
