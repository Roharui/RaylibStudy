
#include "next_block.hpp"

#include "block.hpp"
#include "utils.hpp"

#include <raylib.h>

const char* NEXT_TEXT = "Next";

const int NEXT_POSX = 345;
const int NEXT_POSY = 200;
const int NEXT_SIZE_X = 120;

const int NEXT_SIZE = 40;

const int NEXT_BOX_POS_X = 345;
const int NEXT_BOX_POS_Y = 240;
const int NEXT_BOX_SIZE_X = 120;
const int NEXT_BOX_SIZE_Y = 120;

const float NEXT_BOX_ROUND = 0.2f;

NextBlock::NextBlock()
{
}

void NextBlock::draw()
{
  DrawTextCenter(NEXT_TEXT, {NEXT_POSX, NEXT_POSY, NEXT_SIZE_X, NEXT_SIZE}, NEXT_SIZE, BLACK);
  DrawRectangleRounded({NEXT_BOX_POS_X, NEXT_BOX_POS_Y, NEXT_BOX_SIZE_X, NEXT_BOX_SIZE_Y}, NEXT_BOX_ROUND, 0, DARKBLUE);
}
