/*!
	stop criterion that checks how near are values of function in two vectors
*/

#pragma once
#include "AbstractStopCrit.h"
class ValuesCriterion :
	public AbstractStopCrit
{
public:
	bool criterion(const VectorXd &x1, 
					const VectorXd &x2,
					const AbstractFunction &f) const;
	ValuesCriterion();
	ValuesCriterion(double eps);
	~ValuesCriterion();
};

