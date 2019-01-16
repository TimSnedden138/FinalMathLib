#pragma once
#include "raylib.h"
class player
{
	Vector2 pos;   // Position Of Ball
	void update(float deltaTime);
	void draw();
};