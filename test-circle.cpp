#include "Circle.hpp"
#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(circle_test)
const double EPSILON = 0.000001;
const double RADIUS = 10.0;
const point_t POSITION = { 3.0, 4.0 };
const point_t MOVEPOINT = { 10.0, 11.0 };
const double DX = 10.0;
const double DY = 11.0;
const double AREA = RADIUS * RADIUS * 3.14;
const double DSCALE = 10;
const double COEFFICIENT = 1.5;

BOOST_AUTO_TEST_CASE(getters_test)
{
	Lemon::Circle cir(RADIUS, POSITION);
	rectangle_t frame = cir.getFrameRect();
	BOOST_CHECK_CLOSE(RADIUS, cir.getRadius_c(), EPSILON);
	BOOST_CHECK_CLOSE(POSITION.x, cir.getPos_c().x, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.y, cir.getPos_c().y, EPSILON);
	BOOST_CHECK_CLOSE(AREA, cir.getArea(), EPSILON);
	BOOST_CHECK_CLOSE(RADIUS * 2, cir.getFrameRect().hight, EPSILON);
	BOOST_CHECK_CLOSE(RADIUS * 2, cir.getFrameRect().widht, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.x, cir.getFrameRect().pos.x, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.y, cir.getFrameRect().pos.y, EPSILON);
}
BOOST_AUTO_TEST_CASE(move_test)
{
	Lemon::Circle cir(RADIUS, POSITION);
	cir.move(MOVEPOINT);
	BOOST_CHECK_CLOSE(RADIUS, cir.getRadius_c(), EPSILON);
	BOOST_CHECK_CLOSE(MOVEPOINT.x, cir.getPos_c().x, EPSILON);
	BOOST_CHECK_CLOSE(MOVEPOINT.y, cir.getPos_c().y, EPSILON);
	BOOST_CHECK_CLOSE(AREA, cir.getArea(), EPSILON);
	BOOST_CHECK_CLOSE(RADIUS * 2, cir.getFrameRect().hight, EPSILON);
	BOOST_CHECK_CLOSE(RADIUS * 2, cir.getFrameRect().widht, EPSILON);
	BOOST_CHECK_CLOSE(MOVEPOINT.x, cir.getPos_c().x, EPSILON);
	BOOST_CHECK_CLOSE(MOVEPOINT.y, cir.getPos_c().y, EPSILON);
	cir = { RADIUS, POSITION };
	BOOST_CHECK_CLOSE(RADIUS, cir.getRadius_c(), EPSILON);
	BOOST_CHECK_CLOSE(POSITION.x, cir.getPos_c().x, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.y, cir.getPos_c().y, EPSILON);
	BOOST_CHECK_CLOSE(AREA, cir.getArea(), EPSILON);
	BOOST_CHECK_CLOSE(RADIUS * 2, cir.getFrameRect().hight, EPSILON);
	BOOST_CHECK_CLOSE(RADIUS * 2, cir.getFrameRect().widht, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.x, cir.getFrameRect().pos.x, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.y, cir.getFrameRect().pos.y, EPSILON);
	cir.move(DX, DY);
	BOOST_CHECK_CLOSE(RADIUS, cir.getRadius_c(), EPSILON);
	BOOST_CHECK_CLOSE(POSITION.x + DX, cir.getPos_c().x, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.y + DY, cir.getPos_c().y, EPSILON);
	BOOST_CHECK_CLOSE(AREA, cir.getArea(), EPSILON);
	BOOST_CHECK_CLOSE(RADIUS * 2, cir.getFrameRect().hight, EPSILON);
	BOOST_CHECK_CLOSE(RADIUS * 2, cir.getFrameRect().widht, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.x + DX, cir.getPos_c().x, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.y + DY, cir.getPos_c().y, EPSILON);
}
BOOST_AUTO_TEST_CASE(scale_test)
{
	Lemon::Circle cir(RADIUS, POSITION);
	cir.scale(DSCALE);
	BOOST_CHECK_CLOSE(RADIUS * DSCALE, cir.getRadius_c(), EPSILON);
	BOOST_CHECK_CLOSE(POSITION.x, cir.getPos_c().x, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.y, cir.getPos_c().y, EPSILON);
	BOOST_CHECK_CLOSE(AREA * DSCALE * DSCALE, cir.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(invalid_radius)
{
	BOOST_CHECK_THROW(Lemon::Circle cir(-RADIUS, POSITION), std::invalid_argument);
	BOOST_CHECK_THROW(Lemon::Circle cir(0, POSITION), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(invalid_scale)
{
	Lemon::Circle cir(RADIUS, POSITION);
	BOOST_CHECK_THROW(cir.scale(-COEFFICIENT), std::invalid_argument);
	BOOST_CHECK_THROW(cir.scale(0), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()