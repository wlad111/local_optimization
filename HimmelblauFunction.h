#pragma once
#include "AbstractFunction.h"
class HimmelblauFunction :
	public AbstractFunction
{
public:
	string getName() override;
	double eval(VectorXd &x) override;
	HimmelblauFunction();
	~HimmelblauFunction();
};

