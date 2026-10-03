#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Snake");
    int score = 0;
    const int CellSize = 50;
    int directionX = 0;
    int directionY = 0;

    Vector2 snake[3] =
    {
        {10, 10},
        {9, 10},
        {8, 10}
    };

    float moveTimer = 0.0f;
    float moveDelay = 0.15f;

    while (!WindowShouldClose())
    {

    moveTimer += GetFrameTime();

    if (IsKeyPressed(KEY_W))
        {
         directionX = 0;
         directionY = -1;
        }

    if (IsKeyPressed(KEY_S))
        {
            directionX = 0;
            directionY = 1;
        }

    if (IsKeyPressed(KEY_A))
        {
            directionX = -1;
            directionY = 0;
        }

    if (IsKeyPressed(KEY_D))
        {
            directionX = 1;
            directionY = 0;
        }

    if (moveTimer >= moveDelay)
        {
            for (int i = 2; i > 0; i--)
                {
                    snake[i] = snake[i - 1];
                }

        snake[0].x += directionX;
        snake[0].y += directionY;

        moveTimer = 0.0f;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);

        for(int x = 50; x <= 750; x+= CellSize) // on Y axis |
        {
            DrawLine(x, 50, x, 550, LIGHTGRAY);
        }
        for(int y = 50; y <= 550; y+= CellSize) //on X axis  -
        {
            DrawLine(50, y, 750, y, LIGHTGRAY);
        }
        
        for(int i = 0; i < 3; i++)
        {

        Color color;

        if (i == 0)
        {
            color = RED;
        }
        else
        {
            color = GREEN;
        }

        DrawRectangle(
            snake[i].x * CellSize,
            snake[i].y * CellSize,
            CellSize,
            CellSize,
            color
        );
    }



        EndDrawing();
    }

    CloseWindow();

    return 0;
}