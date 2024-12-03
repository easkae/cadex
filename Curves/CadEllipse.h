#pragma once
#include "BaseCurve.h"
#include "pch.h"

class CURVE_API CadEllipse : public BaseCurve
{
private:
	double radiusX, radiusY;

public:
	CadEllipse(double radiusX, double radiusY);

	std::vector<double> Point(double t);

	std::vector<double> Derivative(double t);

	double GetRadiusX();

	double GetRadiusY();
};
