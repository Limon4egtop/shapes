#include "shape.hpp"
#include <iostream>

void Lemon::Shape::pushData() const
{
	std::cout << "�������: " << getArea() << '\n';
	std::cout << "������� ������������ ��������������\t ������: "
		<< getFrameRect().hight << " ������: " << getFrameRect().widht
		<< "\n������� �� X: " << getFrameRect().pos.x << " �� Y: " << getFrameRect().pos.y
		<< '\n';
}
