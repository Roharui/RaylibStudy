
#include "rayengine.h"

DefaultEngineDisplay::DefaultEngineDisplay()
    : DefaultEngineDisplay({0, 0}, nullptr)
{
}

DefaultEngineDisplay::DefaultEngineDisplay(Rectangle relativeRect)
    : DefaultEngineDisplay(relativeRect, nullptr)
{
}

DefaultEngineDisplay::DefaultEngineDisplay(DefaultEngineDisplay *parentDisplay)
    : DefaultEngineDisplay({0, 0}, parentDisplay)
{
}

DefaultEngineDisplay::DefaultEngineDisplay(Rectangle relativeRect, DefaultEngineDisplay *parentDisplay)
{
  this->parentDisplay = parentDisplay;
  this->childDisplayVector = {};
  this->relativeRect = relativeRect;
  this->absoluteRect = relativeRect;

  if (parentDisplay != nullptr)
  {
    this->parentDisplay->childDisplayVector.push_back(this);

    this->absoluteRect.x += this->parentDisplay->absoluteRect.x;
    this->absoluteRect.y += this->parentDisplay->absoluteRect.y;
  }
}

void DefaultEngineDisplay::draw()
{
  this->drawCurrentDisplay();

  for (DefaultEngineDisplay *item : this->childDisplayVector)
  {
    item->draw();
  }
}

void DefaultEngineDisplay::move(Vector2 loc)
{
  this->absoluteRect.x += loc.x;
  this->absoluteRect.y += loc.y;

  for (DefaultEngineDisplay *item : this->childDisplayVector)
  {
    item->move(loc);
  }
}
