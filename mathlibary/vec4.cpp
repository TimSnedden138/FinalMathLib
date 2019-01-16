#include "vec4.h"

vec4::vec4()
{
}

vec4::vec4(float x, float y, float z,float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

vec4 vec4::operator+(const vec4 & rhs) const
{
	return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w };
}

vec4  vec4::operator-(const vec4 & rhs) const
{
	return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w };

}

vec4 & vec4::operator+=(const vec4 & rhs)
{
	vec4 v4;
	v4.x = x += rhs.x;
	v4.y = y += rhs.y;
	v4.z = z += rhs.z;

	return v4;
}

vec4 & vec4::operator-=(const vec4 & rhs)
{
	vec4 v4;
	v4.x = x -= rhs.x;
	v4.y = y -= rhs.y;
	v4.z = z -= rhs.z;

	return v4;
}

bool vec4::operator==(const vec4 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON *100) and x <= (rhs.x + FLT_EPSILON * 100)) and
		(y >= (rhs.y - FLT_EPSILON * 100) and y <= (rhs.y + FLT_EPSILON * 100)) and
		(z >= (rhs.z - FLT_EPSILON * 100) and z <= (rhs.z + FLT_EPSILON * 100)) and
		(w >= (rhs.w - FLT_EPSILON * 100) and w <= (rhs.w + FLT_EPSILON * 100))) {
		return true;
	}
	return false;
}

bool vec4::operator!=(const vec4 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON * 100) and x <= (rhs.x + FLT_EPSILON * 100)) and
		(y >= (rhs.y - FLT_EPSILON * 100) and y <= (rhs.y + FLT_EPSILON * 100)) and
		(z >= (rhs.z - FLT_EPSILON * 100) and z <= (rhs.z + FLT_EPSILON * 100)) and
		(w >= (rhs.w - FLT_EPSILON * 100) and w <= (rhs.w + FLT_EPSILON * 100))) {
		return false;
	}
	return true;
}

vec4 vec4::operator-() const
{
	vec4 neg4;
	neg4.x = -x;
	neg4.y = -y;
	neg4.z = -z;
	neg4.w = -w;
	return neg4;
}

vec4::operator float*()
{
	return &x;
}

vec4::operator const float*() const
{
	return &x;
}

float vec4::magnitude() const
{
	return sqrt(x * x + y * y + z * z + w * w);

}

float vec4::dot(const vec4 & rhs) const
{
	return { x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w };
}

vec4 vec4::cross(const vec4 & rhs) const
{
	return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x, 0 };
}

vec4 & vec4::normalize()
{
	float normalizeMagnitude = magnitude();
	x /= normalizeMagnitude;
	y /= normalizeMagnitude;
	z /= normalizeMagnitude;
	w /= normalizeMagnitude;
	return *this;

}

vec4 vec4::getNormalised() const
{
	vec4 n;
	n.x = x;
	n.y = y;
	n.z = z;
	n.w = w;
	if (magnitude() == 0)
	{
		return n;
	}
	n.x /= magnitude();
	n.y /= magnitude();
	n.z /= magnitude();
	n.w /= magnitude();

	return n;
}
vec4 & vec4::scale(const vec4 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;
	return *this;
}

vec4 vec4::getScaled(const vec4 & rhs) const
{
	return rhs;
}

vec4 vec4::operator*(const float rhs) const
{
	vec4 v4;
	v4.x = x * rhs;
	v4.y = y * rhs;
	v4.z = z * rhs;
	v4.w = w * rhs;
	return v4;
}

vec4 vec4::operator/(const float rhs) const
{
	return vec4();
}

vec4 & vec4::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	w *= rhs;
	return *this;
}

vec4 & vec4::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	w /= rhs;
	return *this;
}

vec4 operator*(const float lhs, const vec4 & rhs)
{
	vec4 bo;
	bo.x = lhs * rhs.x;
	bo.y = lhs * rhs.y;
	bo.z = lhs * rhs.z;
	bo.w = lhs * rhs.w;
	return bo;
}