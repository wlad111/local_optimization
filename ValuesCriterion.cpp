#include "ValuesCriterion.h"



ValuesCriterion::ValuesCriterion()
{
}

ValuesCriterion::ValuesCriterion(double eps):AbstractStopCrit(eps)
{

}


ValuesCriterion::~ValuesCriterion()
{
}

bool ValuesCriterion::criterion(const VectorXd &x1, 
								const VectorXd &x2,
								const AbstractFunction &f) const
{
	return(abs(f.eval(x1) - f.eval(x2)) > epsilon);
}