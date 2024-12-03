#pragma once
#include "pch.h"
#include "Export.h"

#include <vector>
#include <cmath>
#include <stdexcept>

class BaseCurve
{
public:
	virtual std::vector<double> Point(double t) = 0;
	virtual std::vector<double> Derivative(double t) = 0;
	virtual ~BaseCurve() = default;
};
