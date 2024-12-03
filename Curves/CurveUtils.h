#pragma once
#include <memory>
#include <random>
#include <ctime>
#include "BaseCurve.h"

enum CURVE_API CurveType
{
	circle = 0,
	ellipse = 1,
	helix = 2
};

class CURVE_API CurveUtils
{
public:
	static std::shared_ptr<BaseCurve> CreateRandomCurve();
};
