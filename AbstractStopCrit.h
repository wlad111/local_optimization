/*!
	\brief Abstract stopping criterion

	Base class to determine stopping criterions in optimization
*/

#pragma once

#include <Eigen/Dense>
#include "AbstractFunction.h"


using namespace Eigen;
using namespace std;

class AbstractStopCrit
{
public:
	/*!
		compares two vectors and returns boolean value that stops optimization or not
		\param[in] x1 first vector 
		\param[in] x2 second vector
		\param[in] eps accuracy
		\param[in] f function
	*/
	virtual bool criterion(const VectorXd &x1, const VectorXd &x2, double eps, const AbstractFunction &f) const = 0;
	AbstractStopCrit();
	virtual ~AbstractStopCrit();
};

