
#include "raylib.h"

#include "rayengine.h"

#define TEST_SCENE 0

Vault *DefaultEngineDisplay::vault = new Vault();

class TestDisplayOne : public DefaultEngineDisplay
{
public:
  using DefaultEngineDisplay::DefaultEngineDisplay;

protected:
  void drawCurrentDisplay() override
  {
    DrawRectangleRec(absoluteRect, BLUE);
  }
};

class TestDisplayTwo : public DefaultEngineDisplay
{
public:
  using DefaultEngineDisplay::DefaultEngineDisplay;

protected:
  void drawCurrentDisplay() override
  {
    DrawRectangleRec(absoluteRect, RED);
  }
};

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Engine Test");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  DefaultEngineDisplay *t1 = new TestDisplayOne({10, 20, 100, 30});
  DefaultEngineDisplay *t2 = new TestDisplayTwo({10, 20, 30, 20}, t1);

  Scene *scene1 = new Scene({t1});

  Game game;

  game.appendScene(TEST_SCENE, scene1);

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    game.update();
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    game.clear();
    game.draw();

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
