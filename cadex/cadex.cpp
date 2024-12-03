#define _USE_MATH_DEFINES

#include <iostream>
#include <numeric>
#include <algorithm>
#include "CurveUtils.h"
#include "Circle.h"
#include "Helix.h"
#include "Ellipse.h"

int main()
{
    std::vector<std::shared_ptr<BaseCurve>> randomCurves;
    std::vector<std::shared_ptr<Circle>> circleContainer;

    for (int i = 0; i < 100; i++)
    {
        randomCurves.push_back(CurveUtils::CreateRandomCurve());
    }

    std::cout << "Curve points:\n";

    for (auto curvePtr : randomCurves)
    {
        std::string type;
        std::vector<double> curvePIPoints = curvePtr->Point(M_PI / 4);
        std::vector<double> curvePIDerivative = curvePtr->Derivative(M_PI / 4);
        if (auto circle = std::dynamic_pointer_cast<Circle>(curvePtr)) {

            circleContainer.push_back(circle);
            type = "circle";
        }
        else  if (auto ellipse = std::dynamic_pointer_cast<Ellipse>(curvePtr))
        {
            type = "ellipse";
        }
        else if (auto helix = std::dynamic_pointer_cast<Helix>(curvePtr))
        {
            type = "helix";
        }

        std::cout << "Curve type:\t" << type << "\tpoint:\t" << curvePIPoints[0] << '\t' << curvePIPoints[1] << '\t' << curvePIPoints[2] <<
            "\tderivative:\t" << curvePIDerivative[0] << '\t' << curvePIDerivative[1] << '\t' << curvePIDerivative[2] << '\n';
    }

    std::sort(circleContainer.begin(), circleContainer.end(), [](const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) {
        return a->GetRadius() < b->GetRadius();
    });

    double totalRadius = 0;
    #pragma omp parallel for reduction(+:totalRadius)
    for (size_t i = 0; i < circleContainer.size(); ++i)
    {
        totalRadius += circleContainer[i]->GetRadius();
    }

    std::cout << std::endl << "sum of radii: " << totalRadius << std::endl;
    
}
