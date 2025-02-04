
#include "rayengine.h"

#include "raylib.h"

DefaultEngineDisplay::DefaultEngineDisplay()
  : DefaultEngineDisplay({0, 0}, nullptr)
{
}

DefaultEngineDisplay::DefaultEngineDisplay(Vector2 rect) 
  : DefaultEngineDisplay(rect, nullptr)
{
}

DefaultEngineDisplay::DefaultEngineDisplay(DefaultEngineDisplay *parentDisplay)
  : DefaultEngineDisplay({0, 0}, parentDisplay)
{
}

DefaultEngineDisplay::DefaultEngineDisplay(Vector2 offset, DefaultEngineDisplay *parentDisplay)
{
  this->parentDisplay = parentDisplay;
  this->childDisplayVector = {};
  this->offset = offset;

  if (parentDisplay != nullptr) {
    this->parentDisplay->childDisplayVector.push_back(this);
    this->offset.x += this->parentDisplay->offset.x;
    this->offset.y += this->parentDisplay->offset.y;
  }
}

void DefaultEngineDisplay::draw()
{
  this->drawCurrentDisplay();

  for (DefaultEngineDisplay* item : this->childDisplayVector)
  {
    item->draw();
  }
}

void DefaultEngineDisplay::move(Vector2 loc)
{
  this->offset.x += loc.x;
  this->offset.y += loc.y;

  for (DefaultEngineDisplay* item : this->childDisplayVector)
  {
    item->move(loc);
  }
}
