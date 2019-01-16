#include "tankBody.h"
tankBody::tankBody()
{
	frames = 5;
	body.localPos = { 100,100 };
}

tankBody::~tankBody()
{
}

void tankBody::draw()
{

	Rectangle sourceRect = { 0, 0, tankBod.width, tankBod.height };
	Rectangle destRect = { body.worldPosition().x, body.worldPosition().y, tankBod.width, tankBod.width };

	DrawTexturePro(tankBod, sourceRect, destRect, { (float)tankBod.width / 2, (float)tankBod.height / 2 }, body.worldRotation() * 180 / PI - 90, WHITE);
}

void tankBody::move()
{
	if (IsKeyDown(KEY_W)) {
		body.localPos.y -= frames;
	}
	if (IsKeyDown(KEY_S)) {
		body.localPos.y += frames;
	}
	if (IsKeyDown(KEY_A)) {
		body.localPos.x -= frames;
	}
	if (IsKeyDown(KEY_D)) {
		body.localPos.x += frames;
	}
	if (IsKeyDown(KEY_Q)) {
		body.rotate(-PI / 180 * 2);
	}
	if (IsKeyDown(KEY_E)) {
		body.rotate(PI / 180 * 2);
	}
}