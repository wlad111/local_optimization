#pragma once
#include "AbstractFunction.h"
class Function4Dim :
	public AbstractFunction
{
public:
	double eval(Eigen::VectorXd &x) override;
	Function4Dim(VectorXd &left, VectorXd &right);
	~Function4Dim();
};

