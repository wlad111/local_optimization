#include "NearPointsCrit.h"
#include <cmath>


NearPointsCrit::NearPointsCrit()
{
}


NearPointsCrit::~NearPointsCrit()
{
}

bool NearPointsCrit::criterion(VectorXd &x1, VectorXd &x2, double eps, AbstractFunction &f)
{
	//return(sqrt((x1 - x2).dot((x1 - x2))) > eps);
	return((((x1 - x2).cwiseAbs()).maxCoeff() > eps));
}