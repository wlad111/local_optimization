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
}