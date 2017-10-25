#include "AbstractFunction.h"
#include "RectangularArea.h"
#include "Values.h"



AbstractFunction::AbstractFunction()
{

}


AbstractFunction::~AbstractFunction()
{

}

RectangularArea AbstractFunction::getArea() const
{
	return domain;
}


int AbstractFunction::getDim() const
{
	return dim;
}

void AbstractFunction::setArea(const VectorXd &l, const VectorXd &r)
{
	RectangularArea area(l, r, dim);
	domain = area;
}

VectorXd AbstractFunction::gradient(const VectorXd &x) const
{
	int n = dim;
	double h = STEP;
	VectorXd grad(n);
	VectorXd x0(n), x1(n);
	for (int j = 0; j < n; j++)
	{
		x0(j) = x(j);
		x1(j) = x(j);
	}
	for (int i = 0; i < n; i++)
	{
		x0(i) += h;
		x1(i) -= h;
		grad(i) = (eval(x0) - eval(x1)) / (2 * h);
		x0(i) -= h;
		x1(i) += h;
	}
	return(grad);
}

MatrixXd AbstractFunction::hessian(const VectorXd &x) const
{
	int n = dim;
	double h = STEP;
	VectorXd x0(n), x1(n), x2(n), x3(n);
	MatrixXd hess(n, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
				for (int k = 0; k < n; k++)
				{
					x0(k) = x(k);
					x1(k) = x(k);
					x2(k) = x(k);
					x3(k) = x(k);
				}
				x0(i) += h;
				x0(j) += h;
				x1(i) += h;
				x2(j) += h;
			hess(i, j) = (eval(x0) - eval(x1) - eval(x2) + eval(x3)) / (h*h);
		}
	}
	return(hess);
}