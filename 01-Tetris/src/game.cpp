
#include "game.hpp"

#include <exception>
#include <random>

#include <raylib.h>

#include "blocks.cpp"

const int GRID_OFFSET_X = 20;
const int GRID_OFFSET_Y = 20;

const int NEXT_BOX_POS_X = 345;
const int NEXT_BOX_POS_Y = 240;

Game::Game() {
  grid = Grid();
  score = Score();
  nextBlockBox = NextBlock();

  isGameOver = false;

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

void Game::update()
{
  if (EventTrigger(0.4) && !isGameOver)
  {
    moveBlockDown();
  }
}

void Game::draw()
{
  ClearBackground(RAYWHITE);
  grid.draw();
  score.draw();
  nextBlockBox.draw();

  currentBlock.draw(GRID_OFFSET_X, GRID_OFFSET_Y);

  switch(nextBlock.id)
  {
    case 3:
      nextBlock.draw(NEXT_BOX_POS_X -  90, NEXT_BOX_POS_Y + 45);
      break;
    case 4:
      nextBlock.draw(NEXT_BOX_POS_X - 120 + 30, NEXT_BOX_POS_Y + 30);
      break;
    default:
      nextBlock.draw(NEXT_BOX_POS_X -  90 + 15, NEXT_BOX_POS_Y + 30);
      break;
  }
}

void Game::handleInput()
{
  int keyPressed = GetKeyPressed();

  if (isGameOver) {
    return;
  }

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

  isGameOver = grid.isGameOver();

  int scoreNum = grid.ClearFullRows();

  score.addScore(scoreNum);
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
