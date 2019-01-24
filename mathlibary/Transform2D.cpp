#include "Transform2D.h"
#include"mathutil.h"
#include <cmath>
#include <iostream>
transform2d::transform2d()
{
	localPos = { 0,0 };
	localScale = { 1,1 };
	localRot = 0;
	parent = nullptr;
}

void transform2d::translate(const vec2 & offset)
{
	localPos = offset;
}

void transform2d::rotate(const float angle)
{

	localRot += angle;
}

void transform2d::lookAt(const transform2d & target)
{
	vec2 r = target.localPos - localPos;

	r.getNormalized();

	localRot = atan2(r.y,r.x);
}

vec2 transform2d::forward() const
{
	return vec2(cos(localRot),sin(localRot));
}

void transform2d::setForward(const vec2 & newFwd)
{
	vec2 r = newFwd - localPos;

	r.getNormalized();

	localRot = atan2(r.y, r.x);
}

mat3 transform2d::getTRSMatrix() const
{
	return mat3(
		localPos.x, localPos.y, 0,
		cos(localRot), sin(localRot), 0,
		localScale.x, localScale.y, 0);
}

mat3 transform2d::getTSMatrix() const
{
	return mat3(
		localScale.x, 0, localPos.x,
		0, localScale.y, localPos.y,
		0, 0, 1);
}

vec2 transform2d::worldPosition() const
{
	if (parent != nullptr)
	{
		mat3 concat = getTSMatrix() * parent->getTSMatrix();
		return vec2(concat.m3, concat.m6);
	}

	return localPos;
}

float transform2d::worldRotation() const
{
	if (parent != nullptr)
	{
		return localRot * parent->localRot;
	}

	return localRot;
}
vec2 transform2d::worldScale() const
{
	if (parent != nullptr)
	{
		mat3 concat = getTSMatrix() * parent->getTSMatrix();
		return vec2(concat.m3, concat.m6);
	}

	return localScale;
}

void transform2d::setParent(transform2d * _parent)
{
	parent = _parent;
	parent->children.push_back(this);
}

transform2d * transform2d::getParent()
{
	return parent;
}

transform2d const * transform2d::getParent() const
{
	return parent;
}
transform2d * transform2d::getChildren()
{
	if (children.size() > 0)
	{
	return children[0];
	}
	return nullptr;
}

transform2d * const * transform2d::getChildren() const
{
	if (children.size() > 0)
	{
		return &children[0];
	}
	return nullptr;
}

size_t transform2d::getChildrenCount() const
{
	return children.size();
