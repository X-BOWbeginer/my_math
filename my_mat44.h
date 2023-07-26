#pragma once

#include "my_vec.h"

using namespace std;
class Mat44 {
public:
	union data_t{
		Vec4 row[4];
		float elems[16];
		data_t() {}

	}data;
	Mat44() {
		memset(&data, 0, sizeof(data));
		data.elems[0] = 1;
		data.elems[5] = 1;
		data.elems[10] = 1;
		data.elems[15] = 1;
	}
	Mat44(float* elements) {
		for (int i = 0; i < 16; i++) {
			data.elems[i] = elements[i];
		}
	}
	Mat44(Vec4* rows) {
		for (int i = 0; i < 4; i++) {
			data.row[i] = rows[i];
		}
	}
	Mat44(Vec4 v0,Vec4 v1, Vec4 v2,Vec4 v3) {
		data.row[0] = v0;
		data.row[1] = v1;
		data.row[2] = v2;
		data.row[3] = v3;
	}
	inline Mat44& operator=(const Mat44& m1)
	{
		data.row[0] = m1.data.row[0];
		data.row[1] = m1.data.row[1];
		data.row[2] = m1.data.row[2];
		data.row[3] = m1.data.row[3];
		return *this;
	}
	inline Mat44 operator-();
	//inline void Set(float _x, float _y, float _z, float _w);
	inline float& operator()(int row, int col);
	inline void transpose() {
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				swap(data.elems[i*4+j], data.elems[j * 4 + i]);
			}
		}
	}

	inline  Mat44 RotateX(float radians);
	inline  Mat44 RotateY(float radians);
	inline  Mat44 RotateZ(float radians);
	inline  Mat44 Rotate(float radiansX, float radiansY, float radiansZ);
	inline Mat44 Translate(float x, float y, float z);
	inline Mat44 Scale(float x, float y, float z);
	
};
inline Mat44 Mat44::Scale(float x, float y, float z)
{
	Mat44 res;
	res.data.elems[0] = x;
	res.data.elems[5] = y;
	res.data.elems[10] = z;
	return res;
}
inline Mat44 Mat44::Translate(float x, float y, float z)
{
	Mat44 res;
	res.data.elems[12] = x;
	res.data.elems[13] = y;
	res.data.elems[14] = z;
	return res;
}
inline  Mat44 Mat44::RotateX(float radians)
{
	float sa = sinf(radians);
	float ca = cosf(radians);
	float buffer[16] = { 1,0,0,0,
		0,ca,sa,0,
		0,-sa,ca,0,
		0,0,0,1 };
	return Mat44(buffer);
}
inline Mat44 Mat44::RotateY(float radians)
{
	float sa = sinf(radians);
	float ca = cosf(radians);
	float buffer[16] = { ca,0,-sa,0,
		0,1,0,0,
		sa,0,ca,0,
		0,0,0,1 };
	return Mat44(buffer);
}



inline Mat44 Mat44::RotateZ(float radians)
{
	float sa = sinf(radians);
	float ca = cosf(radians);
	float buffer[16] = { ca,sa,0,0,
		-sa,ca,0,0,
		0,0,1,0,
		0,0,0,1 };
	return Mat44(buffer);
}



inline Mat44 Mat44::Rotate(float radiansX, float radiansY, float radiansZ)
{
	float sx = sinf(radiansX);
	float sy = sinf(radiansY);
	float sz = sinf(radiansZ);
	float cx = cosf(radiansX);
	float cy = cosf(radiansY);
	float cz = cosf(radiansZ);
	float buffer[16] = {
		(cz * cy + sz * sx * sy), sz * cx, (cz * -sy + sz * sx * cy), 0,
		(-sz * cy + cz * sx * sy), cz * cx, (-sz * -sy + cz * sx * cy), 0,
		cx * sy, -sx, cx * cy, 0,
		0, 0, 0, 1
	};
	return Mat44(buffer);
}

inline float& Mat44::operator()(int row, int col) {
	return data.elems[row * 4 + col];
}

inline Mat44 Mat44::operator-() {
	return Mat44(-data.row[0], -data.row[1], -data.row[2], -data.row[3]);
}
//-----------------------------------------------------------------------
//----------------------------------------------------------------
namespace std {
	inline ostream& operator<<(ostream& os, Mat44& m)
	{
		os << "Mat44:" << endl;
		os << m.data.row[0];
		os << m.data.row[1];
		os << m.data.row[2];
		os << m.data.row[3];
		os << endl;
		return os;
	}
}
//----------------------------------------------------------------
inline Mat44 operator+(const Mat44& m,const Mat44& other) {
	return Mat44(m.data.row[0] + other.data.row[0], m.data.row[1] + other.data.row[1], m.data.row[2] + other.data.row[2], m.data.row[3] + other.data.row[3]);
}
inline Mat44 operator+(const Mat44& m, const float& other)
{
	return Mat44(m.data.row[0] + other, m.data.row[1] + other, m.data.row[2] + other, m.data.row[3] + other);
}
inline Mat44 operator+(const float& other,const Mat44& m)
{
	return Mat44(m.data.row[0] + other, m.data.row[1] + other, m.data.row[2] + other, m.data.row[3] + other);
}
inline Mat44  operator-(const Mat44& m, const Mat44& other)
{
	return Mat44(m.data.row[0] - other.data.row[0], m.data.row[1] - other.data.row[1], m.data.row[2] - other.data.row[2], m.data.row[3] - other.data.row[3]);
}
inline Mat44 operator-(const Mat44& m, const float& other)
{
	return Mat44(m.data.row[0] - other, m.data.row[1] - other, m.data.row[2] - other, m.data.row[3] - other);
}
inline Mat44 operator-(const float& other, const Mat44& m)
{
	return Mat44( other- m.data.row[0] , other - m.data.row[1], other - m.data.row[2], other - m.data.row[3]);
}
inline Mat44 operator*(const Mat44& m, const Mat44& other) {
	Mat44 tmp = other;
	tmp.transpose();
	return Mat44(m.data.row[0] * tmp.data.row[0], m.data.row[1] * tmp.data.row[1], m.data.row[2] * tmp.data.row[2], m.data.row[3] * tmp.data.row[3]);
}
inline Mat44 operator*(const Mat44& m, const float& other)
{
	return Mat44(m.data.row[0] * other, m.data.row[1] * other, m.data.row[2] * other, m.data.row[3] * other);
}
inline Mat44 operator*(const float& other, const Mat44& m)
{
	return Mat44(m.data.row[0] * other, m.data.row[1] * other, m.data.row[2] * other, m.data.row[3] * other);
}

//-----------------------------------------------------------------
inline Vec4 operator*(Vec4& v, Mat44& m)
{
	Mat44 tmp = m;
	tmp.transpose();
	return Vec4(v.Dot_product(tmp.data.row[0]), v.Dot_product(tmp.data.row[1]), v.Dot_product(tmp.data.row[2]), v.Dot_product(tmp.data.row[3]));

}