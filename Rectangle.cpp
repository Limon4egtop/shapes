#include "Rectangle.hpp"
#include <iostream>

Lemon::Rectangle::Rectangle(double w0, double h0, point_t p0) : widht_r(w0), hight_r(h0), pos_r(p0)
{
	number_++;
	if ((w0 <= 0) || (h0 <= 0))
	{
		throw std::invalid_argument("Wrong argument");
	}
}

void Lemon::Rectangle::putData()
{
	std::cin >> widht_r >> hight_r >> pos_r.x >> pos_r.y;
}

double Lemon::Rectangle::getArea() const
{
	return widht_r * hight_r;
}

rectangle_t Lemon::Rectangle::getFrameRect() const
{
	return rectangle_t{ widht_r, hight_r, pos_r };
}

void Lemon::Rectangle::move(const point_t a)
{
	pos_r.x = a.x;
	pos_r.y = a.y;
}

void Lemon::Rectangle::move(double w1, double h1)
{
	pos_r.x += w1;
	pos_r.y += h1;
}

void Lemon::Rectangle::scale(double a1)
{
	if (a1 <= 0)
	{
		throw std::invalid_argument("Wrong argument");
	}
	hight_r *= a1;
	widht_r *= a1;
}

void Lemon::Rectangle::number_pushData()
{
	std::cout << "Number: " << number_ << '\n';
}

void Lemon::Rectangle::pushData()const
{
	std::cout << "Высота: " << hight_r << " Ширина: " << widht_r << '\n';
	Lemon::Rectangle::number_pushData();
	Lemon::Shape::pushData();
}

double Lemon::Rectangle::getWidt_r()const
{
	return widht_r;
}

double Lemon::Rectangle::getHight_r()const
{
	return hight_r;
}

point_t Lemon::Rectangle::getPos_r()const
{
	return point_t{ pos_r.x, pos_r.y };
}
