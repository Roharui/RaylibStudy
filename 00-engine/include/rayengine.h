#pragma once

#include <raylib.h>

#include <vector>
#include <map>
#include <algorithm>

#include <iostream>

using std::vector, std::map;

class Game;
class Scene;
class DefaultEngineDisplay;

// main Object
class Game
{
public:
  static Game *game;

  static void init()
  {
    Game::game->_reset();
    Game::game->_init();
  }

  static void draw() { Game::game->_draw(); }
  static void update() { Game::game->_update(); }
  static void clear() { Game::game->_clear(); }
  static void appendScene(int keyCode, Scene *scene) { Game::game->_appendScene(keyCode, scene); }

  Game();

protected:
  virtual void _init() {};

private:
  void _reset();
  void _draw();
  void _update();
  void _clear();

  void _appendScene(int keyCode, Scene *scene);

  Scene *curScene;
  map<int, Scene *> mapScene;
};

//
class Scene
{
public:
  Scene() = delete;
  Scene(int sceneKeyCode);

  void update();
  void draw();

  void appendDisplay(DefaultEngineDisplay *display);
  void removeDisplay(DefaultEngineDisplay *display);

private:
  void clickEvent();

  vector<DefaultEngineDisplay *> vecOfDisplay;
};

// Default Display Class
class DefaultEngineDisplay
{
public:
  DefaultEngineDisplay() = delete;
  DefaultEngineDisplay(const char *name, Scene *scene);
  DefaultEngineDisplay(const char *name, DefaultEngineDisplay *parent);
  DefaultEngineDisplay(const char *name, Rectangle relativeRect, Scene *scene);
  DefaultEngineDisplay(const char *name, Rectangle relativeRect, DefaultEngineDisplay *parent);

  void draw();
  void clickEvent(MouseButton mouseBtn);

  void move(Vector2 loc);
  void remove();

  bool isRootDisplay();
  bool isLocInside(Vector2 loc);

  Scene *scene;

protected:
  virtual void drawCurrentDisplay() {}
  virtual bool leftClickEventCurrent() { return false; }
  virtual bool rightClickEventCurrent() { return false; }

  void removeChildDisplay(DefaultEngineDisplay *display);

  const char *name;
  Rectangle relativeRect;
  Rectangle absoluteRect;

  DefaultEngineDisplay *rootDisplay;
  DefaultEngineDisplay *parentDisplay;
  vector<DefaultEngineDisplay *> childDisplayVector;
};

// Draw Utils
void DrawTextCenter(const char *text, Rectangle rect, int fontSize, Color color);
