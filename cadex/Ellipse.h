#pragma once
#include "BaseCurve.h"

class Ellipse : public BaseCurve
{
private:
	double radiusX, radiusY;

public:
	Ellipse(double radiusX, double radiusY);

	std::vector<double> Point(double t);

	std::vector<double> Derivative(double t);

	double GetRadiusX();

	double GetRadiusY();
};
