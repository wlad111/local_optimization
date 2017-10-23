#include "HimmelblauFunction.h"



HimmelblauFunction::HimmelblauFunction()
{
	dim = 2;
	VectorXd left(2), right(2);
	left(0) = 0;
	left(1) = 0;
	right(0) = 4;
	right(1) = 4;
	RectangularArea area(left, right, dim);
	domain = area;
	isConvex = false;
}


HimmelblauFunction::~HimmelblauFunction()
{
}


string HimmelblauFunction::getName()
{
	return "((x(0)*x(0) + x(1) - 11)*(x(0)*x(0) + x(1) - 11) + (x(0) + x(1)*x(1) - 7)*(x(0) + x(1)*x(1) - 7))";
}


double HimmelblauFunction::eval(Eigen::VectorXd &x)
{
	return (((x(0)*x(0) + x(1) - 11)*(x(0)*x(0) + x(1) - 11) + (x(0) + x(1)*x(1) - 7)*(x(0) + x(1)*x(1) - 7)));
}

