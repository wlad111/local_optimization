#pragma once
#include "AbstractFunction.h"
class FourthDegreeFunction :
	public AbstractFunction
{
public:
	string getName() override;
	double eval(const VectorXd &x) const override;
	FourthDegreeFunction();
	~FourthDegreeFunction();
};

