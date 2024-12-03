#pragma once
#include "BaseCurve.h"

class Circle : public BaseCurve
{
private:
	double radius;

public:
	Circle(double radius);

	std::vector<double> Point(double t);

	std::vector<double> Derivative(double t);

	double GetRadius();
};
