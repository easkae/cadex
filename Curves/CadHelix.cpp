#include "pch.h"
#include "CadHelix.h"

CadHelix::CadHelix(double radius, double step)
{
	if (radius <= 0)
	{
		throw std::invalid_argument("Radius must be greater than zero.");
	}

	this->radius = radius;
	this->step = step;
}

std::vector<double> CadHelix::Point(double t)
{
	std::vector<double> point = { radius * std::cos(t), radius * std::sin(t), step * t / (2 * M_PI) };
	return point;
}

std::vector<double> CadHelix::Derivative(double t)
{
	std::vector<double> point = { -radius * std::sin(t), radius * std::cos(t), step / (2 * M_PI) };
	return point;
}

double CadHelix::GetRadius()
{
	return radius;
}

double CadHelix::GetStep()
{
	return step;
}
