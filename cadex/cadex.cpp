#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "CurveUtils.h"
#include "CadCircle.h"
#include "CadEllipse.h"
#include "CadHelix.h"

int main()
{
    std::vector<std::shared_ptr<BaseCurve>> randomCurves;
    std::vector<std::shared_ptr<CadCircle>> circleContainer;

    for (int i = 0; i < 1000; i++)
    {
        randomCurves.push_back(CurveUtils::CreateRandomCurve());
    }

    std::cout << "Curve points:\n";

    for (auto curvePtr : randomCurves)
    {
        std::string type;
        std::vector<double> curvePIPoints = curvePtr->Point(M_PI / 4);
        std::vector<double> curvePIDerivative = curvePtr->Derivative(M_PI / 4);
        if (auto circle = std::dynamic_pointer_cast<CadCircle>(curvePtr)) {
            circleContainer.push_back(circle);
            type = "circle";
        }
        else if (auto ellipse = std::dynamic_pointer_cast<CadEllipse>(curvePtr))
        {
            type = "ellipse";
        }
        else if (auto helix = std::dynamic_pointer_cast<CadHelix>(curvePtr))
        {
            type = "helix";
        }

        std::cout << "Curve type:\t" << type
            << "\tpoint:\t" << curvePIPoints[0] << '\t' << curvePIPoints[1] << '\t' << curvePIPoints[2]
            << "\tderivative:\t" << curvePIDerivative[0] << '\t' << curvePIDerivative[1] << '\t' << curvePIDerivative[2] << '\n';
    }

    std::sort(circleContainer.begin(), circleContainer.end(),
        [](const std::shared_ptr<CadCircle>& a, const std::shared_ptr<CadCircle>& b) {
            return a->GetRadius() < b->GetRadius();
        });

    double totalRadius = 0;
#pragma omp parallel for reduction(+:totalRadius)
    for (size_t i = 0; i < circleContainer.size(); ++i)
    {
        totalRadius += circleContainer[i]->GetRadius();
    }

    std::cout << "\nSum of radii: " << totalRadius << std::endl;
}