#include "FunctionOne.h"

using namespace Eigen;

FunctionOne::FunctionOne()
{
	dim = 2;
	VectorXd left(2), right(2);
	left(0) = -2;
	left(1) = -2;
	right(0) = 2;
	right(1) = 2;
	RectangularArea area(left, right, dim);
	domain = area;
	isConvex = false;
}


FunctionOne::~FunctionOne()
{
}

string FunctionOne::getName()
{
	return "100 * (x(1) - x(0) * x(0))*(x(1) - x(0) * x(0)) + (1 - x(0)) * (1 - x(0))";
}

double FunctionOne::eval(const Eigen::VectorXd &x) const
{
	return(100 * (x(1) - x(0) * x(0))*
		(x(1) - x(0) * x(0)) + (1 - x(0)) * (1 - x(0)));
}



