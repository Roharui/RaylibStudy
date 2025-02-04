#pragma once

#include <vector>

#include "grid.hpp"
#include "next_block.hpp"
#include "score.hpp"

#include "block.hpp"
#include "position.hpp"
#include "utils.hpp"

class Game {
  public:
    Game();
    
    void update();
    void draw();
    void handleInput();

    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();

    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();

    Grid grid;
    Score score;
    NextBlock nextBlockBox;

    bool isGameOver;

  private:
    bool IsBlockOutside();
    void rotateBlock();
    void lockBlock();
    bool blockFits();

    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;

};
