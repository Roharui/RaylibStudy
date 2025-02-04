#pragma once

#include <raylib.h>
#include <string.h>

class Score {
  public:
    Score();
    void draw();
    void addScore(int score);
  private:
    int scoreNum;

};
