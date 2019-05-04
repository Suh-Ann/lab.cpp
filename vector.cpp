#include "pch.h"
#include <iostream>
#include <cmath>  
using namespace std;

class Vector
{

public:
	Vector() : x(), y(), z()
	{

	}
	Vector(int v1, int v2, int v3) : x(v1), y(v2), z(v3)
	{

	}
	void UmVector()
	{
		cout << x + y + z << "";
	}
	void newVector()
	{
		cout << x << ":" << y << ":" << z << "";
	}

	Vector operator+(Vector)const;
	Vector operator*(Vector)const;
	float gamma();
	Vector operator%(Vector)const;

private:
	int x;
	int y;
	int z;
};

Vector Vector :: operator+ (Vector q)const
{
	int v1 = x + q.x;
	int v2 = y + q.y;
	int v3 = z + q.z;
	return Vector(v1, v2, v3);
}

Vector Vector :: operator% (Vector q)const
{
	int v1 = x * q.x;
	int v2 = y * q.y;
	int v3 = z * q.z;
	return Vector((v1 + v2 + v3), v1 * 0, v2 * 0);
}


Vector Vector :: operator* (Vector q)const
{
	int v1 = y * q.z - z * q.y;
	int v2 = z * q.x - x * q.z;
	int v3 = x * q.y - y * q.x;
	return Vector((v1 + v2 + v3), v1 * 0, v2 * 0);
}

float Vector::gamma()
{
	return std::acos(y / (sqrt(float(x*x + y * y))));
}


int main()
{

	int x, y, z, i, j, k;
	Vector a, b, c;
	cout << "Введите координаты вектора a: " << endl;
	cin >> x >> y >> z;
	cout << "Введите координаты вектора b: " << endl;
	cin >> i >> j >> k;
	a = Vector(x, y, z);
	b = Vector(i, j, k);
	c = a + b;
	cout << "Сложение: a("; a.newVector(); cout << ") + b("; b.newVector(); cout << ") = c("; c.newVector(); cout << ")" << endl;
	c = a % b;
	cout << "Векторное произведение: a("; a.newVector(); cout << ") * b("; b.newVector(); cout << ") = "; c.UmVector(); cout << endl;
	cout << "Угол вектора g =  " << a.gamma() << " радиан" << endl;
	cout << "Скалярное произведение: a("; a.newVector(); cout << ") % b("; b.newVector(); cout << ") = "; c.newVector(); cout << endl;
	c = a * b;



	return 0;
}
