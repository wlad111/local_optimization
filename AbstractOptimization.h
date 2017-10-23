#pragma once

#include <Eigen/Dense>
#include "AbstractFunction.h"
#include "AbstractStopCrit.h"

using namespace Eigen;
using namespace std;

class AbstractOptimizer
{
public:
	//virtual VectorXd optim(VectorXd &x0, double eps, AbstractFunction &f, AbstractStopCrit &stop) = 0;
	AbstractOptimizer();
	virtual ~AbstractOptimizer();
protected:
	int dim;
};

