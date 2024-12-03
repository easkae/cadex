#pragma once
#define _USE_MATH_DEFINES
#include "BaseCurve.h"

class Helix : public BaseCurve
{
private:
	double radius, step;

public:
	Helix(double radius, double step);

	std::vector<double> Point(double t);

	std::vector<double> Derivative(double t);

	double GetRadius();

	double GetStep();
};
