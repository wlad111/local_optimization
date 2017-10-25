#pragma once

#include <Eigen/Dense>
#include "RectangularArea.h"



using namespace Eigen;
using namespace std;

class AbstractFunction
{
public:
	virtual double eval(const VectorXd &x) const = 0;
	virtual string getName() = 0;
	VectorXd gradient(const VectorXd &x) const; 
	MatrixXd hessian(const VectorXd &x) const;
	int getDim() const;
	RectangularArea getArea() const;
	AbstractFunction();
	virtual ~AbstractFunction();
	void setArea(const VectorXd &l, const VectorXd &r);
protected: 
	int dim;
	bool isConvex;
	RectangularArea domain;
};

