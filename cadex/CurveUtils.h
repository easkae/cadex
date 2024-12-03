#pragma once
#include <memory>
#include <random>
#include <ctime>
#include "BaseCurve.h"

enum CurveType
{
	circle = 0,
	ellipse = 1,
	helix = 2
};

class CurveUtils
{
public:
	static std::shared_ptr<BaseCurve> CreateRandomCurve();
};
