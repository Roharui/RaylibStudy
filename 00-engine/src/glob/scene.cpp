
#include "rayengine.h"

// constructor
Scene::Scene(int keyCode)
{
  this->vecOfDisplay = {};

  Game::appendScene(keyCode, this);
}

// public
void Scene::update()
{
  this->clickEvent();
}

void Scene::draw()
{
  for (DefaultEngineDisplay *item : this->vecOfDisplay)
  {
    item->draw();
  }
}

void Scene::appendDisplay(DefaultEngineDisplay *display)
{
  this->vecOfDisplay.push_back(display);
}

void Scene::removeDisplay(DefaultEngineDisplay *display)
{
  vector<DefaultEngineDisplay *> &vec = this->vecOfDisplay;
  vec.erase(std::remove(vec.begin(), vec.end(), display), vec.end());
}

// private
void Scene::clickEvent()
{
  bool isLeftClick = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
  bool isRightClick = IsMouseButtonPressed(MOUSE_BUTTON_RIGHT);

  if (!(isLeftClick || isRightClick))
  {
    return;
  }

  MouseButton mouseBtn = {};
  mouseBtn = isLeftClick ? MOUSE_BUTTON_LEFT : mouseBtn;
  mouseBtn = isRightClick ? MOUSE_BUTTON_RIGHT : mouseBtn;

  Vector2 clickPos = GetMousePosition();

  for (int i = this->vecOfDisplay.size() - 1; i >= 0; i--)
  {
    DefaultEngineDisplay *item = this->vecOfDisplay.at(i);

    if (item->isLocInside(clickPos))
    {
      item->clickEvent(mouseBtn);
      return;
    }
  }
}
