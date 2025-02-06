
#include "rayengine.h"

// constructor
DefaultEngineDisplay::DefaultEngineDisplay(const char *name, Scene *scene)
    : DefaultEngineDisplay(name, {0, 0}, scene)
{
}

DefaultEngineDisplay::DefaultEngineDisplay(const char *name, DefaultEngineDisplay *parentDisplay)
    : DefaultEngineDisplay(name, {0, 0}, parentDisplay)
{
}

DefaultEngineDisplay::DefaultEngineDisplay(const char *name, Rectangle relativeRect, DefaultEngineDisplay *parentDisplay)
{
  this->childDisplayVector = {};

  this->name = name;
  this->relativeRect = relativeRect;
  this->absoluteRect = relativeRect;

  this->parentDisplay = parentDisplay;
  this->rootDisplay = parentDisplay->rootDisplay;
  this->scene = parentDisplay->scene;

  if (parentDisplay != nullptr)
  {
    this->parentDisplay->childDisplayVector.push_back(this);

    this->absoluteRect.x += parentDisplay->absoluteRect.x;
    this->absoluteRect.y += parentDisplay->absoluteRect.y;
  }

  this->scene->appendDisplay((DefaultEngineDisplay *)this);
}

DefaultEngineDisplay::DefaultEngineDisplay(const char *name, Rectangle relativeRect, Scene *scene)
{
  this->childDisplayVector = {};

  this->name = name;
  this->relativeRect = relativeRect;
  this->absoluteRect = relativeRect;

  this->parentDisplay = nullptr;
  this->rootDisplay = this;
  this->scene = scene;

  this->scene->appendDisplay((DefaultEngineDisplay *)this);
}

// public
void DefaultEngineDisplay::draw()
{
  this->drawCurrentDisplay();
}

void DefaultEngineDisplay::clickEvent(MouseButton mouseBtn)
{
  bool isClickEventActive = false;

  switch (mouseBtn)
  {
  case MOUSE_BUTTON_LEFT:
    isClickEventActive = this->leftClickEventCurrent();
    break;
  case MOUSE_BUTTON_RIGHT:
    isClickEventActive = this->rightClickEventCurrent();
    break;
  default:
    break;
  }

  if (isClickEventActive)
    return;

  if (this->isRootDisplay())
    return;

  this->parentDisplay->clickEvent(mouseBtn);
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

void DefaultEngineDisplay::remove()
{
  for (DefaultEngineDisplay *item : this->childDisplayVector)
  {
    item->remove();
  }

  this->scene->removeDisplay(this);

  if (!this->isRootDisplay())
  {
    this->parentDisplay->removeChildDisplay(this);
  }
}

bool DefaultEngineDisplay::isRootDisplay()
{
  return this->parentDisplay == nullptr;
}

bool DefaultEngineDisplay::isLocInside(Vector2 loc)
{
  const int displayPosX = this->absoluteRect.x;
  const int displayWidthX = this->absoluteRect.x + this->absoluteRect.width;

  const int displayPosY = this->absoluteRect.y;
  const int displayHeightY = this->absoluteRect.y + this->absoluteRect.height;

  return displayPosX <= loc.x && loc.x <= displayWidthX && displayPosY <= loc.y && loc.y <= displayHeightY;
}

// private
void DefaultEngineDisplay::removeChildDisplay(DefaultEngineDisplay *display)
{
  vector<DefaultEngineDisplay *> &vec = this->childDisplayVector;
  vec.erase(std::remove(vec.begin(), vec.end(), display), vec.end());
  delete display;
}
