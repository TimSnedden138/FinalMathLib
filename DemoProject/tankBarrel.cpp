#include "tankBarrel.h"
#include "tankBody.h"
tankBarrel::tankBarrel()
{
	int frames = 5;
	bar.localPos = {0,0};

}
tankBarrel::~tankBarrel()
{
}

void tankBarrel::setParent2(transform2d * obj)
{
	bar.setParent(obj);
}

void tankBarrel::draw()
{
	Rectangle sourceRect = { 0, 0, tankBar.width, tankBar.height };
	Rectangle destRect = { bar.worldPosition().x, bar.worldPosition().y, tankBar.width, tankBar.width };

	DrawTexturePro(tankBar, sourceRect, destRect, { (float)tankBar.width / 2, (float)tankBar.height / 2 }, bar.worldRotation() * 180 / PI - 90, WHITE);
}

void tankBarrel::rotate()
{
	if (IsKeyDown(KEY_RIGHT))
	{
		bar.rotate(PI / 180 * 2);
	}
	if (IsKeyDown(KEY_LEFT))
	{
		bar.rotate(PI / -180 * 2);
	}

}
