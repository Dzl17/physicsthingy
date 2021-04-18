#include <blah/math/circle.h>
#include <blah/math/calc.h>

using namespace Blah;


void Circle::project(const Vec2& axis, float* min, float* max) const
{
	*min = Vec2::dot(center - axis * radius, axis);
	*max = Vec2::dot(center + axis * radius, axis);
}