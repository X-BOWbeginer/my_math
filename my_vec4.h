#pragma once
#include <iostream>
#include <cmath>

//using namespace std;

class Vec4
{
public:
    float x, y, z, w;

public:
    //friend ostream& operator<<(ostream& os, const Vec4& v);
    //Vec4() {}
    Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    Vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}

    inline Vec4 operator-();
    inline void Set(float _x, float _y, float _z, float _w);
    inline void Normalize();
    inline float Length();
    inline float Dot_product(Vec4& v);
    inline Vec4 Cross_product(Vec4& v);
    inline void Lerp(Vec4& v1, Vec4& v2, float t);

    inline bool operator==(Vec4& v)
    {
        return (x == v.x && y == v.y && z == v.z && w == v.w);
    }

    inline Vec4& operator=(const Vec4& v1)
    {
        x = v1.x;
        y = v1.y;
        z = v1.z;
        w = v1.w;
        return *this;
    }
};

inline void Vec4::Lerp(Vec4& v1, Vec4& v2, float t)
{
    x = v1.x + (v2.x - v1.x) * t;
    y = v1.y + (v2.y - v1.y) * t;
    z = v1.z + (v2.z - v1.z) * t;
    w = v1.w + (v2.w - v1.w) * t;
}

inline void Vec4::Set(float _x, float _y, float _z, float _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

inline Vec4 Vec4::operator-()
{
    return Vec4(-x, -y, -z, -w);
}

inline float Vec4::Dot_product(Vec4& v)
{
    return (x * v.x + y * v.y + z * v.z + w * v.w);
}

inline Vec4 Vec4::Cross_product(Vec4& v)
{
    return Vec4(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x, 0.0f);
}

inline float Vec4::Length()
{
    return sqrt(x * x + y * y + z * z + w * w);
}

inline void Vec4::Normalize()
{
    float r = sqrt(x * x + y * y + z * z + w * w);
    x = x / r;
    y = y / r;
    z = z / r;
    w = w / r;
}
namespace std {
    inline ostream& operator<<(ostream& os, const Vec4& v)
    {
        os << "x=" << v.x << " ";
        os << "y=" << v.y << " ";
        os << "z=" << v.z << " ";
        os << "w=" << v.w;
        os << endl;
        return os;
    }
}

inline Vec4 operator+(const Vec4& v1, const Vec4& v2)
{
    return Vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

inline Vec4 operator+(const Vec4& v1, float v2)
{
    return Vec4(v1.x + v2, v1.y + v2, v1.z + v2, v1.w + v2);
}

inline Vec4 operator+(float v1, const Vec4& v2)
{
    return Vec4(v1 + v2.x, v1 + v2.y, v1 + v2.z, v1 + v2.w);
}

inline Vec4 operator-(const Vec4& v1, const Vec4& v2)
{
    return Vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

inline Vec4 operator-(const Vec4& v1, float v2)
{
    return Vec4(v1.x - v2, v1.y - v2, v1.z - v2, v1.w - v2);
}

inline Vec4 operator-(float v1, const Vec4& v2)
{
    return Vec4(v1 - v2.x, v1 - v2.y, v1 - v2.z, v1 - v2.w);
}

inline Vec4 operator*(const Vec4& v1, const Vec4& v2)
{
    return Vec4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
}

inline Vec4 operator*(const Vec4& v1, float v2)
{
    return Vec4(v1.x * v2, v1.y * v2, v1.z * v2, v1.w * v2);
}

inline Vec4 operator*(float v1, const Vec4& v2)
{
    return Vec4(v1 * v2.x, v1 * v2.y, v1 * v2.z, v1 * v2.w);
}
