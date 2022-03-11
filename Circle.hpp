#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "base-type.hpp"
#include "shape.hpp"

namespace Lemon
{
	class Circle : public Shape
	{
	private:
		double radius_c;
		point_t pos_c;
		static int number_;
	public:
		Circle(double, point_t);
		void putData();
		double getArea() const override;
		rectangle_t getFrameRect() const override;
		void move(const point_t);
		void move(double, double);
		void scale(double);
		static void number_pushData();
		void pushData() const override;
		double getRadius_c() const;
		point_t getPos_c() const;
	};
}
#endif // !CIRCLE_HPP