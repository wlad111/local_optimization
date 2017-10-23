#pragma once
#include "AbstractOptimization.h"
class NewtonOptimizer :
	public AbstractOptimizer
{
public:
	VectorXd optim(VectorXd &x0, double eps, AbstractFunction &f, AbstractStopCrit &stop);

	NewtonOptimizer();
	~NewtonOptimizer();
};

