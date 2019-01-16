#include "vec2.h"
#include "mathutil.h"
vec2::vec2()
{
}

vec2::vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

vec2 vec2::operator+(const vec2 & rhs) const
{
	return { x + rhs.x, y + rhs.y };

}

vec2 vec2::operator-(const vec2 & rhs) const
{
	return { x - rhs.x, y - rhs.y };
}

vec2 & vec2::operator+=(const vec2 & rhs)
{
	
	x += rhs.x;
	y += rhs.y;

	return *this;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{
	
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

bool vec2::operator==(const vec2 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON * 100) and x <= (rhs.x + FLT_EPSILON * 100)) and
		(y >= (rhs.y - FLT_EPSILON * 100) and y <= (rhs.y + FLT_EPSILON * 100))) {
		return true;
	}
	return false;
}

bool vec2::operator!=(const vec2 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON) and x <= (rhs.x + FLT_EPSILON)) and
		(y >= (rhs.y - FLT_EPSILON) and y <= (rhs.y + FLT_EPSILON))) {
		return false;
	}
	return true;
}

vec2 vec2::operator-() const
{
	vec2 neg2;
	neg2.x = -x;
	neg2.y = -y;
	return neg2;
}

vec2::operator float*()
{
	return &x;
}

vec2::operator const float*() const
{
	return &x;
}

float vec2::magnitude() const
{
	return sqrt(x * x + y * y);

}

vec2 & vec2::normalize()
{
	float normalizeMagnitude = magnitude();
	x /= normalizeMagnitude;
	y /= normalizeMagnitude;
	return *this;

}

vec2 vec2::getNormalized() const
{
	vec2 n;
	n.x = x;
	n.y = y;
	if (magnitude() == 0)
	{
		return n;
	}
	n.x /= magnitude();
	n.y /= magnitude();

	return n;

}

vec2 & vec2::scale(const vec2 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;

	return *this;

}

vec2 vec2::getScaled(const vec2 & rhs) const
{
	return rhs;
}

vec2 vec2::operator*(const float rhs) const
{
	vec2 v2;
	v2.x = x * rhs;
	v2.y = y * rhs;
	return v2;
}

vec2 vec2::operator/(const float rhs) const
{
	x / rhs;
	y / rhs;
	return *this;
}

vec2 & vec2::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

vec2 & vec2::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	return *this;
}

vec2 vec2::getPerpCW() const
{
	vec2 t;
	t.x = y;
	t.y = -x;
	return t;
}

vec2 vec2::getPerpCCW() const
{
	vec2 t;
	t.x = -y;
	t.y = x;
	return t;
}

float vec2::angleBetween(const vec2 & rhs) const
{
	return std::acos(dot(rhs) / magnitude() * rhs.magnitude());
}

float vec2::dot(const vec2 & rhs) const
{
	vec2 temp;
	temp.x = x * rhs.x;
	temp.y = y * rhs.y;
	float dotProduct = temp.x + temp.y;
	return dotProduct;
}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	vec2 bo;
	bo.x = lhs * rhs.x;
	bo.y = lhs * rhs.y;
	return bo;
}
