#include "Helix.h"

Helix::Helix(double radius, double step) : radius(radius), step(step) {};

std::vector<double> Helix::Point(double t)
{
	std::vector<double> point = { radius * std::cos(t), radius * std::sin(t), step * t / (2 * M_PI) };
	return point;
}

std::vector<double> Helix::Derivative(double t)
{
	std::vector<double> point = { -radius * std::sin(t), radius * std::cos(t), step / (2 * M_PI) };
	return point;
}

double Helix::GetRadius()
{
	return radius;
}

double Helix::GetStep()
{
	return step;
}
