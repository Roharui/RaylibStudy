
#include "rayengine.h"

// constructor
Game::Game()
{
}

// private
void Game::_reset()
{
  this->curScene = nullptr;
  this->mapScene.clear();
}

void Game::_draw()
{
  this->curScene->draw();
}

void Game::_update()
{
  this->curScene->update();
}

void Game::_clear()
{
  ClearBackground(RAYWHITE);
}

void Game::_appendScene(int keyScene, Scene *scene)
{
  if (this->curScene == nullptr)
    this->curScene = scene;

  this->mapScene[keyScene] = scene;
}