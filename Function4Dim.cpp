#include "Function4Dim.h"



Function4Dim::Function4Dim(const VectorXd &left, const VectorXd &right)
{
	dim = 4;
	RectangularArea dom(left, right, dim);
	domain = dom;
}


Function4Dim::~Function4Dim()
{
}

double Function4Dim::eval(const Eigen::VectorXd &x) const
{
	return(x(0)*x(0) + x(1)*x(1) + x(2)*x(2) + x(3)*x(3)*x(3)*x(3));
	//return(100 *(x(1) - x(0)*x(0))*(x(1) - x(0)*x(0)) + (1 - x(0))*(1 - x(0)) + 90 * (x(3) - x(2)*x(2)) * (x(3) - x(2)*x(2)) + (1 - x(2))*(1 - x(2))*(1 - x(2)) + 10.1*(x(1) - 1) * (x(1) - 1) + (x(3) - 1)*(x(3) - 1) + 19.8*(x(1) - 1)*(x(3) - 1));
}