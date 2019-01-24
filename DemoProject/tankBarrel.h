<<<<<<< HEAD
#pragma once
#include "raylib.h"
#include "Transform2D.h"
#include "mathutil.h"
class tankBarrel
{
public:
	tankBarrel();
	~tankBarrel();
	void setParent2(transform2d * obj);
	int frames;
	transform2d bar;
	Texture2D tankBar = LoadTexture("Resources/barrelBlack.png");
	void draw();
	void rotate();
=======
#pragma once
#include"raylib.h"
#include"Transform2D.h"
#include"mathutil.h"
class tankBarrel
{
public:
	tankBarrel();
	~tankBarrel();
	void setParent2(transform2d * obj);
	int frames;
	transform2d bar;
	Texture2D tankBar = LoadTexture("Resources/barrelBlack.png");
	void draw();
	void rotate();
>>>>>>> 7e36e498667ef64f17f89994ad4b5955f3a43392
};