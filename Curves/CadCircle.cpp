#include "pch.h"
#include "CadCircle.h"

CadCircle::CadCircle(double radius)
{
	if (radius <= 0)
	{
		throw std::invalid_argument("Radius must be greater than zero.");
	}
	this->radius = radius;
}

std::vector<double> CadCircle::Point(double t)
{
	std::vector<double> point = { radius * std::sin(t), radius * std::cos(t), 0.0 };
	return point;
}

std::vector<double> CadCircle::Derivative(double t)
{
	std::vector<double> point = { -radius * std::sin(t), radius * std::cos(t), 0.0 };
	return point;
}

double CadCircle::GetRadius()
{
	return radius;
}
