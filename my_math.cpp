// my_math.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "my_mat44.h"
using namespace std;
int main()
{
    Vec2 v1(1, 2);
    Vec2 v2(1, 2);
    Vec2 v3 = v1 + v2;
    Vec2 v4 = v3;
    cout << v4;
    v4 = -v3;
    cout << v4;
    v4.Set(6, 7);
    cout << v4;
    cout << v4.Length() << endl;
    cout << v4.Dot_product(v3) << endl;
    cout << (v4 == v4) << endl;
    v4.Normalize();
    cout << v4;
    v4.Lerp(v1, v3, 0.5);
    cout << v4;
    Vec3 vv(1, 2, 3);
    cout << vv;
    Vec4 vvv(1,1, 1, 1);
    cout << vvv;
    
    float in[16] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f };
    Mat44 m(in);
    m = -m;
    cout << "sd";
    cout << m(1, 1);
    m(1, 1) = m(1,3);
    cout << m(1, 1) << endl;
    cout << m;
    m.transpose();
    cout << m;
    cout << vvv * m;





}

