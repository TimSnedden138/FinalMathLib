<<<<<<< HEAD
#include"raylib.h"
#include"tankBody.h"
#include"tankBarrel.h"
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "F.A.I.L-S.A.F.E II");
	tankBody pa;
	tankBarrel boi;
	Texture2D tankBod = LoadTexture("Resources/tankBlue.png");
	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	int offset = 20;
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		
		// Update
		//----------------------------------------------------------------------------------
		boi.setParent2(&pa.body);
		boi.rotate();
		//----------------------------------------------------------------------------------
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText("F.A.I.L-S.A.F.E II", 190, 200, 20, GRAY);
		pa.move();
		pa.draw();
		boi.draw();
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
=======
#include"raylib.h"
#include"tankBody.h"
#include"tankBarrel.h"
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "F.A.I.L-S.A.F.E II");
	tankBody pa;
	tankBarrel boi;
	Texture2D tankBod = LoadTexture("Resources/tankBlue.png");
	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	int offset = 20;
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		
		// Update
		//----------------------------------------------------------------------------------
		boi.setParent2(&pa.body);
		boi.rotate();
		//----------------------------------------------------------------------------------
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText("F.A.I.L-S.A.F.E II", 190, 200, 20, GRAY);
		pa.move();
		pa.draw();
		boi.draw();
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
>>>>>>> 7e36e498667ef64f17f89994ad4b5955f3a43392
