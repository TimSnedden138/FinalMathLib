#pragma once
#include"raylib.h"
#include"mathutil.h"
#include "tankBarrel.h"
#include"Transform2D.h"
class tankBody 
{
public:
	tankBody();
	~tankBody();
	int frames;
	transform2d body;
	Texture2D tankBod = LoadTexture("Resources/tankBlack.png");
	void draw();
	void move();
};