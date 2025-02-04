
#include "utils.hpp"
#include "raylib.h"

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

void DrawTextCenter(const char* text, Rectangle rect, int fontSize, Color color)
{
  int textWidth = MeasureText(text, fontSize);
  int textStartX = (rect.width - textWidth) / 2;
  int textStartY = (rect.height - fontSize) / 2;

  if (textStartX < 0) {
    textStartX = 0;
  }
  if (textStartY < 0) {
    textStartY = 0;
  }

  DrawText(
      text,
      rect.x + textStartX,
      rect.y + textStartY,
      fontSize,
      BLACK
  );
}

