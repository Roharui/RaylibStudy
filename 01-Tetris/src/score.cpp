
#include "score.hpp"

#include "raylib.h"
#include "utils.hpp"

#include <string>

const char* SCORE_TEXT = "Score";

const int SCORE_POSX = 345;
const int SCORE_POSY = 30;
const int SCORE_SIZE = 40;

const int SCORE_BOX_POS_X = 345;
const int SCORE_BOX_POS_Y = 80;
const int SCORE_BOX_SIZE_X = 120;
const int SCORE_BOX_SIZE_Y = 80;
const float SCORE_BOX_ROUND = 0.2f;

Score::Score()
{
  scoreNum = 0;
}

void Score::draw()
{
  DrawText(SCORE_TEXT, SCORE_POSX, SCORE_POSY, SCORE_SIZE, BLACK);
  DrawRectangleRounded({SCORE_BOX_POS_X, SCORE_BOX_POS_Y, SCORE_BOX_SIZE_X, SCORE_BOX_SIZE_Y}, SCORE_BOX_ROUND, 0, DARKBLUE);

  DrawTextCenter(std::to_string(scoreNum).c_str(), {SCORE_BOX_POS_X, SCORE_BOX_POS_Y, SCORE_BOX_SIZE_X, SCORE_BOX_SIZE_Y}, SCORE_SIZE, BLACK);
}

void Score::addScore(int score)
{
  scoreNum += score;
}
