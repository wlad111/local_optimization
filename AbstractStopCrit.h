#pragma once

#include <Eigen/Dense>
#include "AbstractFunction.h"


using namespace Eigen;
using namespace std;

class AbstractStopCrit
{
public:
	virtual bool criterion(VectorXd &x1, VectorXd &x2, double eps, AbstractFunction &f) = 0;
	AbstractStopCrit();
	virtual ~AbstractStopCrit();
};

