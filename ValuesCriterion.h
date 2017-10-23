#pragma once
#include "AbstractStopCrit.h"
class ValuesCriterion :
	public AbstractStopCrit
{
public:
	bool criterion(VectorXd &x1, VectorXd &x2, double eps, AbstractFunction &f);
	ValuesCriterion();
	~ValuesCriterion();
};

