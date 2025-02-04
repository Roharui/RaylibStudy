#pragma once

#include <raylib.h>
#include <vector>

// Default Class
class DefaultEngineDisplay {
  public:
    DefaultEngineDisplay();
    DefaultEngineDisplay(Vector2 offset);
    DefaultEngineDisplay(DefaultEngineDisplay *parent);
    DefaultEngineDisplay(Vector2 offset, DefaultEngineDisplay *parent);

    void draw();
    void move(Vector2 loc);
    
    Vector2 offset;

  protected:
    virtual void drawCurrentDisplay() {}
    

  private:
    DefaultEngineDisplay *parentDisplay;
    std::vector<DefaultEngineDisplay *> childDisplayVector; 
};

// Draw Utils
void DrawTextCenter(const char* text, Rectangle rect, int fontSize, Color color);
