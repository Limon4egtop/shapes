#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-type.hpp"

namespace Lemon
{
	class Shape
	{
	public:
		virtual ~Shape() = default;
		virtual double getArea() const = 0;				//вычисление площади
		virtual rectangle_t getFrameRect() const = 0;	//возвращает размеры и координаты описовающего пр€моугольника
		virtual void move(const point_t) = 0;			//смещение в точку
		virtual void move(double, double) = 0;			//смещение по ’ и Y
		virtual void scale(double) = 0;					//увеличивает размер фигуры в * раз
		//virtual static void number_pushData() = 0;		//выводит кол-во фигур(объектов)
		virtual void pushData() const = 0;				//вывод информации
	};
}
#endif // !SHAPE_HPP

