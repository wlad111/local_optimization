#include "FunctionOne.h"

using namespace Eigen;

FunctionOne::FunctionOne()
{
	dim = 2;
	//RectangularArea dom(left, right, dim);
	//domain = dom;
}


FunctionOne::~FunctionOne()
{
}

string FunctionOne::getName()
{
	return "100 * (x(1) - x(0) * x(0))*(x(1) - x(0) * x(0)) + (1 - x(0)) * (1 - x(0))";
}

double FunctionOne::eval(Eigen::VectorXd &x)
{
	//return (((x(0)*x(0) + x(1) - 11)*(x(0)*x(0) + x(1) - 11) + (x(0) + x(1)*x(1) - 7)*(x(0) + x(1)*x(1) - 7)));
	//return (x(0)*x(0) + x(1)*x(1));
	//return (x(0)*x(0)*x(0)*x(0) + x(1)*x(1)*x(1)*x(1));
	return(100 * (x(1) - x(0) * x(0))*(x(1) - x(0) * x(0)) + (1 - x(0)) * (1 - x(0)));
}



