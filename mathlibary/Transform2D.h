<<<<<<< HEAD
#pragma once
#include "mat3.h"
#include"vec2.h"
#include<cmath>
#include<iostream>
#include<vector>
struct transform2d
{
	transform2d();

	vec2 localPos;
	float localRot;
	vec2 localScale;
	void translate(const vec2 &offset);
	void rotate(const float angle);
	void lookAt(const transform2d &target);
	vec2 forward() const;
	void setForward(const vec2 &newFwd);
	mat3 getTRSMatrix() const;
	mat3 getTSMatrix() const;
	vec2 worldPosition() const;               // world position of this object
	float worldRotation() const;              // world rotation of this object
	vec2 worldScale() const;                  // world scale of this object (lossy)

	void setParent(transform2d *parent);      // assigns a parent to this object
	transform2d *getParent();                 // returns a pointer to its parent
	transform2d const *getParent() const;     // returns a pointer to its parent (const-qualified)

	transform2d *getChildren();               // returns a pointer to the first child
	transform2d *const* getChildren() const;  // returns a pointer to the first child (const-qualified)
	size_t getChildrenCount() const;          // returns the number of children available

private:
	transform2d * parent;                   // pointer to parent
	std::vector<transform2d *> children;    // vector containing pointers to all children

};
=======
#pragma once
#include "mat3.h"
#include"vec2.h"
#include<cmath>
#include<iostream>
#include<vector>
struct transform2d
{
	transform2d();

	vec2 localPos;
	float localRot;
	vec2 localScale;
	void translate(const vec2 &offset);
	void rotate(const float angle);
	void lookAt(const transform2d &target);
	vec2 forward() const;
	void setForward(const vec2 &newFwd);
	mat3 getTRSMatrix() const;
	mat3 getTSMatrix() const;
	vec2 worldPosition() const;               // world position of this object
	float worldRotation() const;              // world rotation of this object
	vec2 worldScale() const;                  // world scale of this object (lossy)

	void setParent(transform2d *parent);      // assigns a parent to this object
	transform2d *getParent();                 // returns a pointer to its parent
	transform2d const *getParent() const;     // returns a pointer to its parent (const-qualified)

	transform2d *getChildren();               // returns a pointer to the first child
	transform2d *const* getChildren() const;  // returns a pointer to the first child (const-qualified)
	size_t getChildrenCount() const;          // returns the number of children available

private:
	transform2d * parent;                   // pointer to parent
	std::vector<transform2d *> children;    // vector containing pointers to all children

};
>>>>>>> 7e36e498667ef64f17f89994ad4b5955f3a43392
