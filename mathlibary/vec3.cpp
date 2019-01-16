#include "vec3.h"

vec3::vec3()
{
}

vec3::vec3(float x, float y,float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

vec3 vec3::operator+(const vec3 & rhs) const
{
	vec3 v3;
	v3.x = x + rhs.x;
	v3.y = y + rhs.y;
	v3.z = z + rhs.z;

	return v3;
}

vec3 vec3::operator-(const vec3 & rhs) const
{
	vec3 v3;
	v3.x = x - rhs.x;
	v3.y = y - rhs.y;
	v3.z = z - rhs.z;

	return v3;
}

vec3 & vec3::operator+=(const vec3 & rhs)
{
	vec3 v3;
	v3.x = x += rhs.x;
	v3.y = y += rhs.y;
	v3.z = z += rhs.z;

	return v3;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	vec3 v3;
	v3.x = x -= rhs.x;
	v3.y = y -= rhs.y;
	v3.z = z -= rhs.z;

	return v3;
}

bool vec3::operator==(const vec3 & rhs) const
{
	
	vec3 temp;
	temp.x = x - rhs.x;
	temp.y = y - rhs.y;
	temp.z = z - rhs.z;

	if (abs(temp.x) < FLT_EPSILON * 100 && abs(temp.y) < FLT_EPSILON * 100 && abs(temp.z) < FLT_EPSILON * 100) {
		return true;
	}
	return false;
}

bool vec3::operator!=(const vec3 & rhs) const
{
	vec3 temp;
	temp.x = x - rhs.x;
	temp.y = y - rhs.y;
	temp.z = z - rhs.z;

	if (abs(temp.x) < FLT_EPSILON * 100 && abs(temp.y) < FLT_EPSILON * 100 && abs(temp.z) < FLT_EPSILON * 100) {
		return false;
	}
	return true;
}

vec3 vec3::operator-() const
{
	vec3 neg3;
	neg3.x = -x;
	neg3.y = -y;
	neg3.z = -z;
	return neg3;
}

vec3::operator float*()
{
	return &x;
}

vec3::operator const float*() const
{
	return &x;
}

float vec3::magnitude() const
{
	return sqrt(x * x + y * y + z * z);

}

float vec3::dot(const vec3 & rhs) const
{
	vec3 temp;
	temp.x = x * rhs.x;
	temp.y = y * rhs.y;
	temp.z = z * rhs.z;
	float dotProduct = temp.x + temp.y + temp.z;
	return dotProduct;
}

vec3 vec3::cross(const vec3 & rhs) const
{
	return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x};
}

vec3 & vec3::normalize()
{
	float normalizeMagnitude = magnitude();
	x /= normalizeMagnitude;
	y /= normalizeMagnitude;
	z /= normalizeMagnitude;
	return *this;
}

vec3 vec3::getNormalised() const
{

	vec3 n;
	n.x = x;
	n.y = y;
	n.z = z;
	if (magnitude() == 0)
	{
		return n;
	}
	n.x /= magnitude();
	n.y /= magnitude();
	n.z /= magnitude();

	return n;
}
vec3 & vec3::scale(const vec3 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;

	return *this;
}

vec3 vec3::getScaled(const vec3 & rhs) const
{
	return rhs;
}

vec3 vec3::operator*(const float rhs) const
{
	vec3 v3;
	v3.x = x * rhs;
	v3.y = y * rhs;
	v3.z = z * rhs;
	return v3;
}

vec3 vec3::operator/(const float rhs) const
{

	x / rhs;
	y / rhs;
	z / rhs;
	return *this;
}

vec3 & vec3::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

vec3 & vec3::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	vec3 bo;
	bo.x = lhs * rhs.x;
	bo.y = lhs * rhs.y;
	bo.z = lhs * rhs.z;
	return bo;
}
