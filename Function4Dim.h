#pragma once
#include "AbstractFunction.h"
class Function4Dim :
	public AbstractFunction
{
public:
	double eval(const Eigen::VectorXd &x) const override;
	Function4Dim(const VectorXd &left, const VectorXd &right);
	~Function4Dim();
};

