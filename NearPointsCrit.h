#pragma once
#include "AbstractStopCrit.h"
class NearPointsCrit :
	public AbstractStopCrit
{
public:
	bool criterion(VectorXd &x1, VectorXd &x2, double eps, AbstractFunction &f) override;
	NearPointsCrit();
	~NearPointsCrit();
};

