#include "Rectangle.hpp"
#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(rectangle_test)
const double EPSILON = 0.000001;
const double WIDTH = 15.0;
const double HEIGHT = 10.0;
const point_t POSITION = { 3.0, 4.0 };
const point_t MOVEPOINT = { 10.0, 11.0 };
const double DX = 10.0;
const double DY = 11.0;
const double COEFFICIENT = 1.5;
const double AREA = WIDTH * HEIGHT;
const rectangle_t F_RECT = { WIDTH, HEIGHT, POSITION };
const double DSCALE = 10;

BOOST_AUTO_TEST_CASE(getters_test)
{
	Lemon::Rectangle rec(WIDTH, HEIGHT, POSITION);
	rectangle_t frame = rec.getFrameRect();
	BOOST_CHECK_CLOSE(HEIGHT, rec.getHight_r(), EPSILON);
	BOOST_CHECK_CLOSE(WIDTH, rec.getWidt_r(), EPSILON);
	BOOST_CHECK_CLOSE(POSITION.x, rec.getPos_r().x, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.y, rec.getPos_r().y, EPSILON);
	BOOST_CHECK_CLOSE(AREA, rec.getArea(), EPSILON);
	BOOST_CHECK_CLOSE(F_RECT.hight, rec.getFrameRect().hight, EPSILON);
	BOOST_CHECK_CLOSE(F_RECT.widht, rec.getFrameRect().widht, EPSILON);
	BOOST_CHECK_CLOSE(F_RECT.pos.x, rec.getFrameRect().pos.x, EPSILON);
	BOOST_CHECK_CLOSE(F_RECT.pos.y, rec.getFrameRect().pos.y, EPSILON);
}
BOOST_AUTO_TEST_CASE(move_test)
{
	Lemon::Rectangle rec(WIDTH, HEIGHT, POSITION);
	rec.move(MOVEPOINT);
	BOOST_CHECK_CLOSE(HEIGHT, rec.getHight_r(), EPSILON);
	BOOST_CHECK_CLOSE(WIDTH, rec.getWidt_r(), EPSILON);
	BOOST_CHECK_CLOSE(MOVEPOINT.x, rec.getPos_r().x, EPSILON);
	BOOST_CHECK_CLOSE(MOVEPOINT.y, rec.getPos_r().y, EPSILON);
	BOOST_CHECK_CLOSE(F_RECT.hight, rec.getFrameRect().hight, EPSILON);
	BOOST_CHECK_CLOSE(F_RECT.widht, rec.getFrameRect().widht, EPSILON);
	BOOST_CHECK_CLOSE(MOVEPOINT.x, rec.getFrameRect().pos.x, EPSILON);
	BOOST_CHECK_CLOSE(MOVEPOINT.y, rec.getFrameRect().pos.y, EPSILON);
	rec = { WIDTH, HEIGHT, POSITION };
	rec.move(DX, DY);
	BOOST_CHECK_CLOSE(HEIGHT, rec.getHight_r(), EPSILON);
	BOOST_CHECK_CLOSE(WIDTH, rec.getWidt_r(), EPSILON);
	BOOST_CHECK_CLOSE(POSITION.x + DX, rec.getPos_r().x, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.y + DY, rec.getPos_r().y, EPSILON);
	BOOST_CHECK_CLOSE(F_RECT.hight, rec.getFrameRect().hight, EPSILON);
	BOOST_CHECK_CLOSE(F_RECT.widht, rec.getFrameRect().widht, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.x + DX, rec.getFrameRect().pos.x, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.y + DY, rec.getFrameRect().pos.y, EPSILON);
	
}
BOOST_AUTO_TEST_CASE(scale_test)
{
	Lemon::Rectangle rec(WIDTH, HEIGHT, POSITION);
	rec.scale(DSCALE);
	BOOST_CHECK_CLOSE(HEIGHT * DSCALE, rec.getHight_r(), EPSILON);
	BOOST_CHECK_CLOSE(WIDTH * DSCALE, rec.getWidt_r(), EPSILON);
	BOOST_CHECK_CLOSE(POSITION.x, rec.getPos_r().x, EPSILON);
	BOOST_CHECK_CLOSE(POSITION.y, rec.getPos_r().y, EPSILON);
	BOOST_CHECK_CLOSE(AREA * DSCALE * DSCALE, rec.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(invalid_width)
{
	BOOST_CHECK_THROW(Lemon::Rectangle rec(-WIDTH, HEIGHT, POSITION), std::invalid_argument);
	BOOST_CHECK_THROW(Lemon::Rectangle rec(0, HEIGHT, POSITION), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(invalid_hight)
{
	BOOST_CHECK_THROW(Lemon::Rectangle rec(WIDTH, -HEIGHT, POSITION), std::invalid_argument);
	BOOST_CHECK_THROW(Lemon::Rectangle rec(WIDTH, 0, POSITION), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(invalid_scale)
{
	Lemon::Rectangle rec(WIDTH, HEIGHT, POSITION);
	BOOST_CHECK_THROW(rec.scale(-COEFFICIENT), std::invalid_argument);
	BOOST_CHECK_THROW(rec.scale(0), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()