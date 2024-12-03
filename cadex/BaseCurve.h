#ifndef BASECURVE_H
#define BASECURVE_H

#include <vector>
#include <cmath>

class BaseCurve
{
public:
	virtual std::vector<double> Point(double t) = 0;
	virtual std::vector<double> Derivative(double t) = 0;
	virtual ~BaseCurve() = default;
};

#endif
