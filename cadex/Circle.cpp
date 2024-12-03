#include "Circle.h"

Circle::Circle(double radius) : radius(radius) {}

std::vector<double> Circle::Point(double t)
{
	std::vector<double> point = { radius * std::sin(t), radius * std::cos(t), 0.0 };
	return point;
}

std::vector<double> Circle::Derivative(double t)
{
	std::vector<double> point = { -radius * std::sin(t), radius * std::cos(t), 0.0 };
	return point;
}

double Circle::GetRadius()
{
	return radius;
}
