#include "NearPointsCrit.h"
#include <cmath>


NearPointsCrit::NearPointsCrit()
{
}


NearPointsCrit::~NearPointsCrit()
{
}

bool NearPointsCrit::criterion(const VectorXd &x1, const VectorXd &x2, double eps, const AbstractFunction &f) const
{
	//return(sqrt((x1 - x2).dot((x1 - x2))) > eps);
	return((((x1 - x2).cwiseAbs()).maxCoeff() > eps));
}