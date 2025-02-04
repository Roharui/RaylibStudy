
#include "grid.hpp"

// init

Grid::Grid() {
  numRows = 20;
  numCols = 10;
  cellSize = 30;
  
  // func
  initialize();
  colors = GetCellColors();
}

// public

void Grid::initialize() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      this->grid[row][col] = 0;
    }
  }
}

void Grid::print()
{
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      std::cout << grid[row][col] << " ";
    }

    std::cout << std::endl;
  }
}

void Grid::draw(){
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      int cellValue = grid[row][col];

      DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
    }
  }
}

bool Grid::IsCellOutside(int row, int col)
{
  if (row >= 0 && row < numRows && col >= 0 && col < numCols)
  {
    return false;
  }
  return true;
}

bool Grid::IsCellEmpty(int row, int col)
{
  if (grid[row][col] == 0) {
    return true;
  }
  return false;
}

int Grid::ClearFullRows()
{
  int complete = 0;
  for (int row = numRows - 1; row >= 0; row --)
  {
    if(isRowFull(row))
    {
      ClearRow(row);
      complete ++;
    }
    else if (complete > 0)
    {
      MoveRowDown(row, complete);
    }
  }
  return complete;
}

bool Grid::isRowFull(int row)
{
  for(int col = 0; col < numCols; col ++)
  {
    if(grid[row][col] == 0)
    {
      return false;
    }
  }
  return true;
}

void Grid::ClearRow(int row)
{
  for(int col = 0; col < numCols; col++)
  {
    grid[row][col] = 0;
  }
}

void Grid::MoveRowDown(int row, int numRows)
{
  for(int col = 0; col < numCols; col++)
  {
    grid[row + numRows][col] = grid[row][col];
    grid[row][col] = 0;
  }

}
