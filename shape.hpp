#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-type.hpp"

namespace Lemon
{
	class Shape
	{
	public:
		virtual ~Shape() = default;
		virtual double getArea() const = 0;				//���������� �������
		virtual rectangle_t getFrameRect() const = 0;	//���������� ������� � ���������� ������������ ��������������
		virtual void move(const point_t) = 0;			//�������� � �����
		virtual void move(double, double) = 0;			//�������� �� � � Y
		virtual void scale(double) = 0;					//����������� ������ ������ � * ���
		//virtual static void number_pushData() = 0;		//������� ���-�� �����(��������)
		virtual void pushData() const = 0;				//����� ����������
	};
}
#endif // !SHAPE_HPP

