#include "shape.hpp"
#include <iostream>

void Lemon::Shape::pushData() const
{
	std::cout << "Площадь: " << getArea() << '\n';
	std::cout << "Размеры описывающего прямоугольника\t Высота: "
		<< getFrameRect().hight << " Ширина: " << getFrameRect().widht
		<< "\nПозиция по X: " << getFrameRect().pos.x << " по Y: " << getFrameRect().pos.y
		<< '\n';
}
