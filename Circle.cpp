#include "Circle.hpp"
#include <iostream>

Lemon::Circle::Circle(double r0, point_t p0) : radius_c(r0), pos_c(p0)
{
	if (r0 <= 0)
	{
		throw std::invalid_argument("Wrong argument");
	}
	number_++;
}

void Lemon::Circle::putData()
{
	std::cin >> radius_c >> pos_c.x >> pos_c.y;
}

double Lemon::Circle::getArea() const
{
	return radius_c * radius_c * 3.14;
}

rectangle_t Lemon::Circle::getFrameRect() const
{

	return rectangle_t{ radius_c * 2, radius_c * 2, pos_c };
}

void Lemon::Circle::move(const point_t a)
{
	pos_c.x = a.x;
	pos_c.y = a.y;
}

void Lemon::Circle::move(double w1, double h1)
{
	pos_c.x += w1;
	pos_c.y += h1;
}

void Lemon::Circle::scale(double a1)
{
	if (a1 <= 0)
	{
		throw std::invalid_argument("Wrong argument");
	}
	radius_c *= a1;
}

void Lemon::Circle::number_pushData()
{
	std::cout << "Number: " << number_ << '\n';
}

void Lemon::Circle::pushData()const
{
	std::cout << "Радиус: " << radius_c << '\n';
	Lemon::Circle::number_pushData();
	Lemon::Shape::pushData();
}

double Lemon::Circle::getRadius_c()const
{
	return radius_c;
}

point_t Lemon::Circle::getPos_c() const
{
	return point_t(pos_c);
}
