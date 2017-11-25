#include "NearPointsCrit.h"
#include <cmath>


NearPointsCrit::NearPointsCrit()
{
}

NearPointsCrit::NearPointsCrit(double eps) : AbstractStopCrit(eps)
{

}


NearPointsCrit::~NearPointsCrit()
{
}

bool NearPointsCrit::criterion(const VectorXd &x1, 
							const VectorXd &x2, 
							const AbstractFunction &f) const
{
	return((((x1 - x2).cwiseAbs()).maxCoeff() > epsilon));
}