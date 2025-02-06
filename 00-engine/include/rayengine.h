#pragma once

#include <raylib.h>

#include <vector>
#include <map>

#include <iostream>

using std::vector, std::map;

class Game;
class Scene;
class Vault;
class DefaultEngineDisplay;

//
class Game
{
public:
  Game();

  void draw();
  void update();
  void clear();

  void appendScene(int keyScene, Scene *scene);

private:
  Scene *curScene;
  map<int, Scene *> mapScene;
};

//
class Scene
{
public:
  Scene();
  Scene(vector<DefaultEngineDisplay *> vecOfDisplay);

  void draw();

private:
  vector<DefaultEngineDisplay *> vecOfDisplay;
};

class Vault
{
public:
  Vault();
  ~Vault() {}

  map<int, Scene> sceneMap;
};

// Default Class
class DefaultEngineDisplay
{
public:
  static Vault *vault;

  DefaultEngineDisplay();
  DefaultEngineDisplay(Rectangle relativeRect);
  DefaultEngineDisplay(DefaultEngineDisplay *parent);
  DefaultEngineDisplay(Rectangle relativeRect, DefaultEngineDisplay *parent);

  void draw();
  void move(Vector2 loc);

  Rectangle relativeRect;
  Rectangle absoluteRect;

protected:
  virtual void drawCurrentDisplay() {}

private:
  DefaultEngineDisplay *parentDisplay;
  vector<DefaultEngineDisplay *> childDisplayVector;
};

// Draw Utils
void DrawTextCenter(const char *text, Rectangle rect, int fontSize, Color color);
