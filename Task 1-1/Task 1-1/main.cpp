#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/*
* \brief Находит значение a
* \param x Значение x
* \param y Значение z
* \param z Значение y
* \return Значение a
*/
double getA(const double x, const double y, const double z);

/*
* \brief Находит значение b
* \param x Значение y
* \param y Значение x
* \param z Значение z
* \return Значение b
*/
double getB(const double x, const double y, const double z);

/*
* \brief Вход в программу
* \return в случае успеха, возвращает 0
*/

int main()
{
	const auto x = 0.5;
	const auto y = 0.05;
	const auto z = 0.7;

	const auto a = getA(x, y, z);
	const auto b = getB(x, y, z);

	cout << " x = " << x << ", y = " << y << ", z = " << z << "\n";
	cout << " a = " << a << ", b = " << b;

	return 0;
}

double getA(const double x, const double y, const double z)
{
	return x * x * (x + 1) / (y - pow(sin(x + z), 2));
}

double getB(const double x, const double y, const double z)
{
	return sqrt(x * y / z) + pow(cos((x + y) * (x + y)), 2);
}