#pragma once

#include <Eigen/Dense>
#include "AbstractFunction.h"


using namespace Eigen;
using namespace std;

class AbstractStopCrit
{
public:
	virtual bool criterion(const VectorXd &x1, const VectorXd &x2, double eps, const AbstractFunction &f) const = 0;
	AbstractStopCrit();
	virtual ~AbstractStopCrit();
};

