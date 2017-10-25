#pragma once
#include "AbstractOptimization.h"
class NewtonOptimizer :
	public AbstractOptimizer
{
public:
	VectorXd optim(const VectorXd &x0, double eps, const AbstractFunction &f, const AbstractStopCrit &stop) const;
	NewtonOptimizer();
	~NewtonOptimizer();
};

