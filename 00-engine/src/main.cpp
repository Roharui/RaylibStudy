
#include "raylib.h"

#include "rayengine.h"

#define TEST_SCENE 0

class TestDisplayOne : public DefaultEngineDisplay
{
public:
  using DefaultEngineDisplay::DefaultEngineDisplay;
  int id = 0;

protected:
  void drawCurrentDisplay() override;

  bool leftClickEventCurrent() override;
  bool rightClickEventCurrent() override;
};

void TestDisplayOne::drawCurrentDisplay()
{
  DrawRectangleRec({absoluteRect.x - 1, absoluteRect.y - 1, absoluteRect.width + 1, absoluteRect.height + 1}, BLACK);
  DrawRectangleRec(absoluteRect, BLUE);
}

bool TestDisplayOne::leftClickEventCurrent()
{
  std::cout << this->name << "\n";
  return true;
}

bool TestDisplayOne::rightClickEventCurrent()
{
  this->remove();
  return true;
}

class MyGame : public Game
{
protected:
  void _init() override
  {
    Scene *scene1 = new Scene(TEST_SCENE);

    DefaultEngineDisplay *t1 = new TestDisplayOne("First Display", {10, 10, 100, 100}, scene1);
    DefaultEngineDisplay *t2 = new TestDisplayOne("Second Display", {30, 30, 100, 100}, t1);
    DefaultEngineDisplay *t3 = new TestDisplayOne("Third Display", {30, 30, 100, 100}, t2);
  }
};

Game *Game::game = new MyGame();

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

  Game::init();

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    Game::update();

    int key = GetKeyPressed();
    if (key == KEY_R)
    {
      Game::init();
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    Game::clear();
    Game::draw();

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
