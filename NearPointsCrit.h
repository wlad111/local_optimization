/*!
	\brief Stop criterion 

	Stop criterion compares how near are two iterations. Extends AbstractStopCrit
*/

#pragma once
#include "AbstractStopCrit.h"
class NearPointsCrit :
	public AbstractStopCrit
{
public:
	bool criterion(const VectorXd &x1, 
					const VectorXd &x2, 
					double eps, 
					const AbstractFunction &f) const override;
	NearPointsCrit();
	~NearPointsCrit();
};

