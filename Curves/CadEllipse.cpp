#include "pch.h"
#include "CadEllipse.h"

CadEllipse::CadEllipse(double radiusX, double radiusY)
{
	if (radiusX <= 0 || radiusY <= 0)
	{
		throw std::invalid_argument("Radius must be greater than zero.");
	}

	this->radiusX = radiusX;
	this->radiusY = radiusY;
}

std::vector<double> CadEllipse::Point(double t)
{
	std::vector<double> point = { radiusX * std::cos(t), radiusY * std::sin(t), 0.0 };
	return point;
}

std::vector<double> CadEllipse::Derivative(double t)
{
	std::vector<double> point = { -radiusX * std::sin(t), radiusY * std::cos(t), 0.0 };
	return point;
}

double CadEllipse::GetRadiusX()
{
	return radiusX;
}

double CadEllipse::GetRadiusY()
{
	return radiusY;
}
