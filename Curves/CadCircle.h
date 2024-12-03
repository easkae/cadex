#pragma once
#include "BaseCurve.h"
#include "pch.h"

class CURVE_API CadCircle : public BaseCurve
{
private:
	double radius;

public:
	CadCircle(double radius);

	std::vector<double> Point(double t);

	std::vector<double> Derivative(double t);

	double GetRadius();
};
