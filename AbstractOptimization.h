/*!
	\brief Abstract optimization

	Base class for optimization. 
*/

#pragma once

#include <Eigen/Dense>
#include "AbstractFunction.h"
#include "AbstractStopCrit.h"

using namespace Eigen;
using namespace std;

class AbstractOptimizer
{
public:
	AbstractOptimizer();
	virtual ~AbstractOptimizer();
protected:
	int dim;
};

