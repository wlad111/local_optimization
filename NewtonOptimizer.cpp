#include "NewtonOptimizer.h"
#include "Values.h"
#include <iostream>

using namespace std;



NewtonOptimizer::NewtonOptimizer()
{

}

NewtonOptimizer::~NewtonOptimizer()
{

}

OptimizationResult NewtonOptimizer::optim(const VectorXd &x0, 
										const AbstractFunction &f, 
										const AbstractStopCrit &stop) const
{
	if (!f.getArea().isPointInArea(x0))
	{
		throw exception("wrong initial value");
	}
	MatrixXd H = f.hessian(x0);
	VectorXd x_next = H.colPivHouseholderQr().solve(H*x0 - f.gradient(x0));
	VectorXd x_prev = x0;
	int i = 1;
	while (stop.criterion(x_next, x_prev, f) && (i < MAX_ITERATIONS)) 
	{
		H = f.hessian(x_prev);
		if ((H(0, 0) < 0) || (H(0, 0)*H(1, 1) - H(0, 1)*H(1, 0) < 0))
		{
			cout << "Negative" << endl;
		}
		x_prev = x_next;
		x_next = H.colPivHouseholderQr().solve(H*x_prev - f.gradient(x_prev));
		for (int i = 0; i < f.getDim(); i++)
		{
			if ((x_next(i)) < f.getArea().getLeft()(i))
			{
				x_next(i) = f.getArea().getLeft()(i);
			}
			if ((x_next(i)) > f.getArea().getRight()(i))
			{
				x_next(i) = f.getArea().getRight()(i);
			}
		}
		i++;
	}
	OptimizationResult res(x_next, f.eval(x_next), i);
	return (res);
}
