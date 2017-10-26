/*!
	\brief Newton method

	Class that provides optimization with newton method. Extends AbstractOptimizer
*/


#pragma once
#include "AbstractOptimization.h"
class NewtonOptimizer :
	public AbstractOptimizer
{
public:
	/*!
		performs local optimization using Newton method. Returns argument of local minimum
		\param[in] x0 initial vector
		\param[in] eps accuracy
		\param[in] f function
		\param[in] stop Stop criterion
	*/
	VectorXd optim(const VectorXd &x0, double eps, const AbstractFunction &f, const AbstractStopCrit &stop) const;
	NewtonOptimizer();
	~NewtonOptimizer();
};
