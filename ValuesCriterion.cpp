#include "ValuesCriterion.h"



ValuesCriterion::ValuesCriterion()
{
}


ValuesCriterion::~ValuesCriterion()
{
}

bool ValuesCriterion::criterion(VectorXd &x1, VectorXd &x2, double eps, AbstractFunction &f)
{
	return(abs(f.eval(x1) - f.eval(x2)) > eps);
}