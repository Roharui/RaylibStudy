
#include "raylib.h"

#include "rayengine.h"

class TestDisplayOne : public DefaultEngineDisplay {
  public:
    TestDisplayOne() : DefaultEngineDisplay() {}
    TestDisplayOne(Vector2 offset) : DefaultEngineDisplay(offset) {};
    TestDisplayOne(DefaultEngineDisplay* parentDisplay) : DefaultEngineDisplay(parentDisplay) {}
    TestDisplayOne(Vector2 offset, DefaultEngineDisplay *parent) : DefaultEngineDisplay(offset, parent) {}
  
  protected:
    virtual void drawCurrentDisplay() override
    {
      DrawRectangleRec({offset.x, offset.y, 100, 100}, BLUE);
    }
};

class TestDisplayTwo : public DefaultEngineDisplay {
  public:
    TestDisplayTwo() : DefaultEngineDisplay() {}
    TestDisplayTwo(Vector2 offset) : DefaultEngineDisplay(offset) {};
    TestDisplayTwo(DefaultEngineDisplay* parentDisplay) : DefaultEngineDisplay(parentDisplay) {}
    TestDisplayTwo(Vector2 offset, DefaultEngineDisplay *parent) : DefaultEngineDisplay(offset, parent) {}

  protected:
    virtual void drawCurrentDisplay() override
    {
      DrawRectangleRec({offset.x, offset.y, 20, 20}, RED);
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

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    TestDisplayOne t1 = TestDisplayOne({10, 20});
    TestDisplayTwo t2 = TestDisplayTwo({10, 20}, (DefaultEngineDisplay *) &t1); 

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        int key = GetKeyPressed();

        if (key == KEY_RIGHT)
        {
          t1.move({20, 0});
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangleRec({190, 200, 600, 100}, RED);
            DrawTextCenter("Congrats! You created your first window!", {190, 200, 600, 100}, 20, LIGHTGRAY);
            t1.draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
