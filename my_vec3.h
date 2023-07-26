#pragma once
#include <iostream>
#include <cmath>

//using namespace std;

class Vec3
{
public:
	float x, y, z;

public:
    //inline friend std::ostream& operator<<(std::ostream& os, const Vec3& v);
    Vec3() {}
    Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    inline Vec3 operator-();
    inline void Set(float _x, float _y, float _z);
    inline void Normalize();
    inline float Length();
    inline float Dot_product(Vec3& v);
    inline Vec3 Cross_product(Vec3& v);
    inline void Lerp(Vec3& v1, Vec3& v2, float t);

    inline bool operator==(Vec3& v)
    {
        return (x == v.x && y == v.y && z == v.z);
    }

    inline Vec3& operator=(const Vec3& v1)
    {
        x = v1.x;
        y = v1.y;
        z = v1.z;
        return *this;
    }
};
inline void Vec3::Lerp(Vec3& v1, Vec3& v2, float t) {
    x = v1.x + (v2.x - v1.x) * t;
    y = v1.y + (v2.y - v1.y) * t;
    z = v1.z + (v2.z - v1.y) * t;
}

inline void Vec3::Set(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}

inline Vec3 Vec3::operator-()
{
    return Vec3(-x, -y, -z);
}

inline float Vec3::Dot_product(Vec3& v)
{
    return (x * v.x + y * v.y + z * v.z);
}

inline Vec3 Vec3::Cross_product(Vec3& v)
{
    return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

inline float Vec3::Length()
{
    return sqrt(x * x + y * y + z * z);
}

inline void Vec3::Normalize()
{
    float r = sqrt(x * x + y * y + z * z);
    x = x / r;
    y = y / r;
    z = z / r;
}
namespace std {
    inline ostream& operator<<(ostream& os, const Vec3& v)
    {
        os << "x=" << v.x << " ";
        os << "y=" << v.y << " ";
        os << "z=" << v.z;
        os << endl;
        return os;
    }
}

inline Vec3 operator+(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline Vec3 operator+(const Vec3& v1, float v2)
{
    return Vec3(v1.x + v2, v1.y + v2, v1.z + v2);
}

inline Vec3 operator+(float v1, const Vec3& v2)
{
    return Vec3(v1 + v2.x, v1 + v2.y, v1 + v2.z);
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline Vec3 operator-(const Vec3& v1, float v2)
{
    return Vec3(v1.x - v2, v1.y - v2, v1.z - v2);
}

inline Vec3 operator-(float v1, const Vec3& v2)
{
    return Vec3(v1 - v2.x, v1 - v2.y, v1 - v2.z);
}

inline Vec3 operator*(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

inline Vec3 operator*(const Vec3& v1, float v2)
{
    return Vec3(v1.x * v2, v1.y * v2, v1.z * v2);
}

inline Vec3 operator*(float v1, const Vec3& v2)
{
    return Vec3(v1 * v2.x, v1 * v2.y, v1 * v2.z);
}