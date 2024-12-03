#pragma once
#define _USE_MATH_DEFINES
#include "BaseCurve.h"

class CURVE_API CadHelix : public BaseCurve
{
private:
	double radius, step;

public:
	CadHelix(double radius, double step);
	std::vector<double> Point(double t);
	std::vector<double> Derivative(double t);
	double GetRadius();
	double GetStep();
};
