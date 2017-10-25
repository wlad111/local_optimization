#pragma once
#include "AbstractFunction.h"
class HimmelblauFunction :
	public AbstractFunction
{
public:
	string getName() override;
	double eval(const VectorXd &x) const override;
	HimmelblauFunction();
	~HimmelblauFunction();
};

