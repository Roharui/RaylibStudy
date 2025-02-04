#pragma once

#include <vector>

#include "block.hpp"
#include "grid.hpp"
#include "position.hpp"

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

  private:
    bool IsBlockOutside();
    void rotateBlock();
    void lockBlock();
    bool blockFits();

    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;

};
