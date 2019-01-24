<<<<<<< HEAD
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
=======
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
>>>>>>> 7e36e498667ef64f17f89994ad4b5955f3a43392
};