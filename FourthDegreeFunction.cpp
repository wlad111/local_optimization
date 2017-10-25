#include "FourthDegreeFunction.h"



FourthDegreeFunction::FourthDegreeFunction()
{
	dim = 2;
	VectorXd left(2), right(2);
	left(0) = -100;
	left(1) = -100;
	right(0) = 100;
	right(1) = 100;
	RectangularArea area(left, right, dim);
	domain = area;
	isConvex = true;
}


FourthDegreeFunction::~FourthDegreeFunction()
{
}


string FourthDegreeFunction::getName()
{
	return "(x(0)*x(0)*x(0)*x(0) + x(1)*x(1)*x(1)*x(1)) (Convex)";
}


double FourthDegreeFunction::eval(const VectorXd &x) const
{
	return (x(0)*x(0)*x(0)*x(0) + x(1)*x(1)*x(1)*x(1));
}