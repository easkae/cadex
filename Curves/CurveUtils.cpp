#pragma once
#include "pch.h"
#include "CurveUtils.h"
#include "CadCircle.h"
#include "CadEllipse.h"
#include "CadHelix.h"

std::shared_ptr<BaseCurve> CurveUtils::CreateRandomCurve()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disType(0, 2);
    std::uniform_int_distribution<> randValue(0, RAND_MAX);
    CurveType type = CurveType(disType(gen));

    switch (type)
    {
    case CurveType::circle:
    {
        double randomRadius = 1.0 + randValue(gen);
        return std::make_shared<CadCircle>(randomRadius);
    }
    case CurveType::ellipse:
    {
        double randomRadiusX = 1.0 + randValue(gen);
        double randomRadiusY = 1.0 + randValue(gen);
        return std::make_shared<CadEllipse>(randomRadiusX, randomRadiusY);
    }
    case CurveType::helix:
    {
        double randomStep = 1.0 + randValue(gen);
        double randomRadius = 1.0 + randValue(gen);
        return std::make_shared<CadHelix>(randomStep, randomRadius);
    }
    }
    return nullptr;
}
