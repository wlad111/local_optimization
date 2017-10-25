#pragma once
#include "AbstractFunction.h"
#include "RectangularArea.h"

using namespace Eigen;


class FunctionOne :
	public AbstractFunction
{
public:
	double eval(const VectorXd &x) const override;
	string getName() override;
	FunctionOne();
	~FunctionOne();
};
