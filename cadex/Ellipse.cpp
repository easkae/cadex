#include "Ellipse.h"

Ellipse::Ellipse(double radiusX, double radiusY) : radiusX(radiusX), radiusY(radiusY) {}

std::vector<double> Ellipse::Point(double t)
{
	std::vector<double> point = { radiusX * std::cos(t), radiusY * std::sin(t), 0.0 };
	return point;
}

std::vector<double> Ellipse::Derivative(double t)
{
	std::vector<double> point = { -radiusX * std::sin(t), radiusY * std::cos(t), 0.0 };
	return point;
}

double Ellipse::GetRadiusX()
{
	return radiusX;
}

double Ellipse::GetRadiusY()
{
	return radiusY;
}
