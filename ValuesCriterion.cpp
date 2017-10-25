#include "ValuesCriterion.h"



ValuesCriterion::ValuesCriterion()
{
}


ValuesCriterion::~ValuesCriterion()
{
}

bool ValuesCriterion::criterion(const VectorXd &x1, const VectorXd &x2, double eps, const AbstractFunction &f) const
{
	return(abs(f.eval(x1) - f.eval(x2)) > eps);
}