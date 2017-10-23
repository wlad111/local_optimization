#pragma once

#include <Eigen/Dense>
#include "RectangularArea.h"



using namespace Eigen;
using namespace std;

class AbstractFunction
{
public:
	virtual double eval(VectorXd &x) = 0;
	virtual string getName() = 0;
	VectorXd gradient(VectorXd &x);
	MatrixXd hessian(VectorXd &x);
	const int getDim();
	RectangularArea getArea();
	AbstractFunction();
	virtual ~AbstractFunction();
	void setArea(VectorXd &l, VectorXd &r);
protected: 
	int dim;
	bool isConvex;
	RectangularArea domain;
};

