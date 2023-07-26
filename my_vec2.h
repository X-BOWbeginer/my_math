#pragma once
#include <iostream>
#include<cmath>
class Vec2
{
public:
	float x, y;

	//inline friend std::ostream& operator<<(std::ostream& os, const Vec2& v);
	Vec2() {}
	Vec2(float _x, float _y) :x(_x), y(_y) {}

	inline Vec2 operator -();
	inline void Set(float _x, float _y);
	inline void Normalize();
	inline float Length();
	inline float Dot_product(Vec2& v);
	inline float Cross_product(Vec2& v);
	inline void Lerp(Vec2& v1, Vec2& v2, float t);

	inline bool operator==(Vec2& v) {
		return(x == v.x && y == v.y);
	}
	inline Vec2& operator = (const Vec2& v1) {
		x = v1.x;
		y = v1.y;
		return *this;
	}
};
inline float Vec2::Cross_product(Vec2& v) {
	return x * v.y - y * v.x;
}
inline void Vec2::Lerp(Vec2& v1, Vec2& v2, float t)
{
	x = v1.x + (v2.x - v1.x) * t;
	y = v1.y + (v2.y - v1.y) * t;
}
inline float Vec2::Dot_product(Vec2& v)
{
	return x * v.x + y * v.y;
}
inline float Vec2::Length() {
	return sqrt(x * x + y * y);
}
inline void Vec2::Normalize() {
	float r = sqrtf(x * x + y * y);
	x = x / r;
	y = y / r;
}
inline void Vec2::Set(float _x, float _y) {
	x = _x;
	y = _y;
}
inline Vec2 Vec2::operator -() {
	return Vec2(-x, -y);
}

//----------------------------------------------------------------
namespace std {
	inline ostream& operator<<(ostream& os, Vec2& v)
	{
		os << "x=" << v.x << " ";
		os << "y=" << v.y;
		os << endl;
		return os;
	}
}
//----------------------------------------------------------------


inline Vec2 operator + (const Vec2& v1, const Vec2& v2) {
	return Vec2(v1.x + v2.x, v1.y + v2.y);
}
inline Vec2 operator + (const Vec2& v1, float v2) {
	return Vec2(v1.x + v2, v1.y + v2);
}
inline Vec2 operator + (float v1, const Vec2& v2) {
	return Vec2(v1 + v2.x, v1 + v2.y);
}

inline Vec2 operator - (const Vec2& v1, const Vec2& v2) {
	return Vec2(v1.x - v2.x, v1.y - v2.y);
}
inline Vec2 operator - (const Vec2& v1, float v2) {
	return Vec2(v1.x - v2, v1.y - v2);
}
inline Vec2 operator - (float v1, const Vec2& v2) {
	return Vec2(v1 - v2.x, v1 - v2.y);
}

inline Vec2 operator * (const Vec2& v1, const Vec2& v2) {
	return Vec2(v1.x * v2.x, v1.y * v2.y);
}
inline Vec2 operator * (const Vec2& v1, float v2) {
	return Vec2(v1.x * v2, v1.y * v2);
}
inline Vec2 operator * (float v1, const Vec2& v2) {
	return Vec2(v1 * v2.x, v1 * v2.y);
}
