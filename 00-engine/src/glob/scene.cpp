
#include "rayengine.h"

Scene::Scene()
{
    this->vecOfDisplay = {};
}

Scene::Scene(vector<DefaultEngineDisplay *> vecOfDisplay)
{
    this->vecOfDisplay = vecOfDisplay;
}

void Scene::draw()
{
    for (DefaultEngineDisplay *item : this->vecOfDisplay)
    {
        item->draw();
    }
}