
#include "rayengine.h"

Game::Game()
{
  this->curScene = nullptr;
}

void Game::draw()
{
  this->curScene->draw();
}

void Game::update()
{
}

void Game::clear()
{
  ClearBackground(RAYWHITE);
}

void Game::appendScene(int keyScene, Scene *scene)
{
  if (this->curScene == nullptr)
    this->curScene = scene;

  this->mapScene[keyScene] = scene;
}