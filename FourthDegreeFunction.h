#pragma once
#include "AbstractFunction.h"
class FourthDegreeFunction :
	public AbstractFunction
{
public:
	string getName() override;
	double eval(VectorXd &x) override;
	FourthDegreeFunction();
	~FourthDegreeFunction();
};

