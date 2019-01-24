<<<<<<< HEAD
﻿#pragma once
#include<iostream>
#include"vec2.h"
#include"vec3.h"
#include"vec4.h"
#include"mat3.h"
#include<string>
#ifndef PI
#define PI 3.14159265358979323846f
#endif
namespace mathbois {
	//Returns a + b
	int sum(int a, int b);
	//Returns the smaller of the two values
	int min(int valA, int valB);
	//Returns the larger of the two values
	int max(int valA, int valB);
	//Returns a value no smaller than min and no larger than max
	int clamp(int val, int min, int max);
	//Multiply this with a angle measure expressed in radians to get its equivalent in degrees.
	double RAD_TO_DEG(float rad);
	//Multiply this with a angle measure expressed in degrees to get its equivalent in radians.
	double DEG_TO_RAD(float deg);
	//Returns the absolute value of val.
	int abs(int val);
	//Returns base to the power of exp (i.e. basepower).
	unsigned long long int pow(int base, int power);
	//Returns true if the value is a power of two, otherwise returns false.
	bool isPowerOfTwo(int val);
	//Returns the next power of two after the given value.
	int nextPowerOfTwo(int val);
	//Moves the current value towards the target value. The maximum change should not exceed maxDelta.
	float moveTowards(float current, float target, float maxDelta);
}
	//Assert True
	bool assert(const char * testName, bool expression);
	//Assert Equal

	bool assert(const char * testName, int expected, int actual);
	template <typename T>
	bool assert(const char * testName, T expected, T actual) {
		if (expected == actual) {
			std::cout << "[PASS BOI] " << testName << std::endl;
			return true;
		}
		std::cout << "[FAIL BOI] " << testName << std::endl;
		return false;
	}
	//Assert Near Equal
	bool assert(const char * testName, float expected, float actual, float tolerance);
	// returns a random value between min and max
	namespace mathbois {
		int  rand(int min, int max);
		// returns a random value between min and max
		//  - the value may contain decimal components
		float randDecimal(float min, float max);
		// seed the random numb`er generator
		void seedRand(int seedValue);
		// returns the seed used for the random number generator
		int getRandSeed();
	}
	//LERP
	// implementation one
	template <typename T>
	T lerp1(const T& a, const T& b, float t)
	{
		return a * (1 - t) + b * t;
	}

	// implementation two
	template <typename T>
	T lerp2(const T& a, const T& b, float t)
	{
		return a + (b - a) * t;
	}
	// implementation three
	template <typename T>
	T lerp3(const T& a, const T& b, float t)
	{
		return a + b * t;
	}
=======
﻿#pragma once
#include<iostream>
#include"vec2.h"
#include"vec3.h"
#include"vec4.h"
#include"mat3.h"
#include<string>
#ifndef PI
#define PI 3.14159265358979323846f
#endif
namespace mathbois {
	//Returns a + b
	int sum(int a, int b);
	//Returns the smaller of the two values
	int min(int valA, int valB);
	//Returns the larger of the two values
	int max(int valA, int valB);
	//Returns a value no smaller than min and no larger than max
	int clamp(int val, int min, int max);
	//Multiply this with a angle measure expressed in radians to get its equivalent in degrees.
	double RAD_TO_DEG(float rad);
	//Multiply this with a angle measure expressed in degrees to get its equivalent in radians.
	double DEG_TO_RAD(float deg);
	//Returns the absolute value of val.
	int abs(int val);
	//Returns base to the power of exp (i.e. basepower).
	unsigned long long int pow(int base, int power);
	//Returns true if the value is a power of two, otherwise returns false.
	bool isPowerOfTwo(int val);
	//Returns the next power of two after the given value.
	int nextPowerOfTwo(int val);
	//Moves the current value towards the target value. The maximum change should not exceed maxDelta.
	float moveTowards(float current, float target, float maxDelta);
}
	//Assert True
	bool assert(const char * testName, bool expression);
	//Assert Equal

	bool assert(const char * testName, int expected, int actual);
	template <typename T>
	bool assert(const char * testName, T expected, T actual) {
		if (expected == actual) {
			std::cout << "[PASS BOI] " << testName << std::endl;
			return true;
		}
		std::cout << "[FAIL BOI] " << testName << std::endl;
		return false;
	}
	//Assert Near Equal
	bool assert(const char * testName, float expected, float actual, float tolerance);
	// returns a random value between min and max
	namespace mathbois {
		int  rand(int min, int max);
		// returns a random value between min and max
		//  - the value may contain decimal components
		float randDecimal(float min, float max);
		// seed the random numb`er generator
		void seedRand(int seedValue);
		// returns the seed used for the random number generator
		int getRandSeed();
	}
	//LERP
	// implementation one
	template <typename T>
	T lerp1(const T& a, const T& b, float t)
	{
		return a * (1 - t) + b * t;
	}

	// implementation two
	template <typename T>
	T lerp2(const T& a, const T& b, float t)
	{
		return a + (b - a) * t;
	}
	// implementation three
	template <typename T>
	T lerp3(const T& a, const T& b, float t)
	{
		return a + b * t;
	}
>>>>>>> 7e36e498667ef64f17f89994ad4b5955f3a43392
