#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-type.hpp"
#include "shape.hpp"

namespace Lemon
{
	class Rectangle : public Shape
	{
	private:
		double widht_r;
		double hight_r;
		point_t pos_r;
		static int number_;
	public:
		Rectangle(double, double, point_t);
		void putData();
		double getArea() const override;
		rectangle_t getFrameRect() const override;
		void move(const point_t);
		void move(double, double);
		void scale(double);
		static void number_pushData();
		void pushData() const override;
		double getWidt_r()const;
		double getHight_r()const;
		point_t getPos_r()const;

	};
}
#endif // !RECTANGLE_HPP