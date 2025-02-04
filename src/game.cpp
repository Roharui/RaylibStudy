
#include "game.hpp"

#include <exception>
#include <random>

#include <raylib.h>

#include "blocks.cpp"

Game::Game() {
  grid = Grid();
  blocks = GetAllBlocks();

  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
  if (blocks.empty())
  {
    blocks = GetAllBlocks();
  }

  int randomIndex = rand() % blocks.size();
  Block block = blocks[randomIndex];
  blocks.erase(blocks.begin() + randomIndex);

  return block;
}

std::vector<Block> Game::GetAllBlocks()
{
  return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

double lastUpdateTime = 0;

bool EventTrigger(double interval)
{
  double currentTime = GetTime();
  if(currentTime - lastUpdateTime >= interval)
  {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

void Game::update()
{
  if (EventTrigger(0.4))
  {
    moveBlockDown();
  }
}

void Game::draw()
{
  ClearBackground(RAYWHITE);
  grid.draw();
  currentBlock.draw();
}

void Game::handleInput()
{
  int keyPressed = GetKeyPressed();

  switch(keyPressed) 
  {
    case KEY_LEFT:
      moveBlockLeft();
      break;
    case KEY_RIGHT:
      moveBlockRight();
      break;
    case KEY_DOWN:
      moveBlockDown();
      break;
    case KEY_UP:
      rotateBlock();
      break;
  }
}

void Game::moveBlockLeft()
{
  currentBlock.move(0, -1);
  if (IsBlockOutside() || blockFits() == false)
  {
    currentBlock.move(0, 1);
  }
}

void Game::moveBlockRight()
{
  currentBlock.move(0, 1);
  if (IsBlockOutside() || blockFits() == false)
  {
    currentBlock.move(0, -1);
  }
}

void Game::moveBlockDown()
{
  currentBlock.move(1, 0);
  if (IsBlockOutside() || blockFits() == false)
  {
    currentBlock.move(-1, 0);
    lockBlock();
  }
}

void Game::rotateBlock()
{
  currentBlock.rotate();
  if (IsBlockOutside() || blockFits() == false)
  {
    currentBlock.undoRotation();
  }
}

void Game::lockBlock()
{
  std::vector<Position> tiles = currentBlock.GetCellPositions();
  for(Position item : tiles)
  {
    grid.grid[item.row][item.col] = currentBlock.id;
  }
  currentBlock = nextBlock;
  nextBlock = GetRandomBlock();
  grid.ClearFullRows();
}

bool Game::IsBlockOutside()
{
  std::vector<Position> tiles = currentBlock.GetCellPositions();

  for(Position item: tiles) 
  {
    if (grid.IsCellOutside(item.row, item.col))
    {
      return true;
    }
  }
  return false;
}

bool Game::blockFits()
{
  std::vector<Position> tiles = currentBlock.GetCellPositions();
  for(Position item: tiles)
  {
    if (grid.IsCellEmpty(item.row, item.col) == false)
    {
      return false;
    }
  }
  return true;
}
