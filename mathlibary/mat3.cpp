#include "mat3.h"
#include"vec2.h"
#include <cmath>
mat3::mat3()
{
}

mat3::mat3(float * ptr)
{
	for (int i = 0; i < 9; i++) // cords
	{
		m[i] = ptr[i];
	}
}

mat3::mat3(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
	m5 = _m5;
	m6 = _m6;
	m7 = _m7;
	m8 = _m8;
	m9 = _m9;
}

void mat3::transpose()
{
	/*for (int i = 0; i < 2; i++)
	{
	float temp;
	temp = m[i + 1];
	m[i + 1] = m[i * 3];
	m[i * 3] = temp;
	}
	float temp;
	temp = m[5];
	m[5] = m[7];
	m[7] = temp;*/

	float temp;

	temp = m[3];
	m[3] = m[1];
	m[1] = temp;

	temp = m[2];
	m[2] = m[6];
	m[6] = temp;

	temp = m[5];
	m[5] = m[7];
	m[7] = temp;
}

mat3 mat3::getTranspose() const
{
	mat3 r;

	for (int i = 0; i < 9; i++)
	{
		r.m[i] = m[i];
	}

	float temp;

	temp = r.m[3];
	r.m[3] = r.m[1];
	r.m[1] = temp;

	temp = r.m[2];
	r.m[2] = r.m[6];
	r.m[6] = temp;

	temp = r.m[5];
	r.m[5] = r.m[7];
	r.m[7] = temp;

	return r;
}

mat3::operator float*()
{
	return m;
}

vec3 & mat3::operator[](const int index)
{
	// TODO: insert return statement here
	return axis[index];
}

mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 r = getTranspose();
	mat3 e;

	e.m[0] = r.xAxis.dot(rhs.xAxis);
	e.m[1] = r.yAxis.dot(rhs.xAxis);
	e.m[2] = r.zAxis.dot(rhs.xAxis);
	e.m[3] = r.xAxis.dot(rhs.yAxis);
	e.m[4] = r.yAxis.dot(rhs.yAxis);
	e.m[5] = r.zAxis.dot(rhs.yAxis);
	e.m[6] = r.xAxis.dot(rhs.zAxis);
	e.m[7] = r.yAxis.dot(rhs.zAxis);
	e.m[8] = r.zAxis.dot(rhs.zAxis);

	return e;
}

mat3 & mat3::operator*=(const mat3 & rhs)
{
	// TODO: insert return statement here
	(*this) = (*this) * rhs;

	return *this;
}

bool mat3::operator==(const mat3 & rhs) const
{
	for (int i = 0; i < 9; i++)
	{
		m[i] == rhs.m[i];
		if (m[i] != rhs.m[i])
		{
			return false;
		}
	}
	return true;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	for (int i = 0; i < 9; i++)
	{
		m[i] == rhs.m[i];
		if (m[i] == rhs.m[i])
		{
			return false;
		}
	}
	return true;
}

mat3 mat3::identity() // ! need to fix
{
	mat3 r;

	for (int i = 0; i < 9; i++)
	{
		if (i == 0 || i == 4 || i == 8)
		{
			r.m[i] = 1;
		}
		else
		{
			r.m[i] = 0;
		}
	}

	return r;
}

void mat3::set(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
	m5 = _m5;
	m6 = _m6;
	m7 = _m7;
	m8 = _m8;
	m9 = _m9;
}

void mat3::set(float * ptr)
{
	for (int i = 0; i < 9; i++)
	{
		m[i] = ptr[i];
	}
}

mat3 mat3::translation(float x, float y)
{
	mat3 r;
	r = r.identity();
	r.zAxis.x = x;
	r.zAxis.y = y;
	return r;
}

mat3 mat3::translation(const vec2 & vec)
{
	mat3 r;
	r = r.translation(vec.x, vec.y);
	return r;
}

mat3 mat3::rotation(float rot)
{
	mat3 r;

	for (int i = 0; i < 9; i++)
	{
		r.m[i] = 0;
	}

	r.m[0] = cos(rot);
	r.m[3] = sin(rot);
	r.m[1] = -sin(rot);
	r.m[4] = cos(rot);
	r.m[8] = 1;

	return r;
}

mat3 mat3::scale(float xScale, float yScale)
{
	mat3 r;
	for (int i = 0; i < 3; i++)
	{
		r.axis[i].x = xScale;
		r.axis[i].y = yScale;
		r.axis[i].z = 0;
	}

	return r;
}

vec3 mat3::operator*(const vec3 & rhs) const // 3x3 x 3x1
{
	mat3 r;
	vec3 e;

	r = getTranspose();

	e.x = r.xAxis.dot(rhs);
	e.y = r.yAxis.dot(rhs);
	e.z = r.zAxis.dot(rhs);

	return e;
}

vec2 mat3::operator*(const vec2 & rhs) const // 3x3 x 2x1
{
	mat3 r;
	vec2 e;
	vec3 d;

	d.x = rhs.x;
	d.y = rhs.y;
	d.z = 0;

	r = getTranspose();

	e.x = r.xAxis.dot(d);
	e.y = r.yAxis.dot(d);

	return e;
}