#include "NewtonOptimizer.h"
#include <iostream>

using namespace std;



NewtonOptimizer::NewtonOptimizer()
{

}

NewtonOptimizer::~NewtonOptimizer()
{

}

VectorXd NewtonOptimizer::optim(VectorXd &x0, double eps, AbstractFunction &f, AbstractStopCrit &stop)
{
	MatrixXd H = f.hessian(x0);
	VectorXd x_next = H.colPivHouseholderQr().solve(H*x0 - f.gradient(x0));
	int i = 1;
	//cout << i << "Iteration" << endl;
	//cout << x_next << endl;
	while (stop.criterion(x_next, x0, eps, f))
	{
		H = f.hessian(x0);
		if ((H(0, 0) < 0) || (H(0, 0)*H(1, 1) - H(0, 1)*H(1, 0) < 0))
		{
			cout << "Negative" << endl;
		}
		x0 = x_next;
		x_next = H.colPivHouseholderQr().solve(H*x0 - f.gradient(x0));
		i++;
		cout << i << "Iteration" <<  endl;
		cout << x_next << endl;
	}
	cout << i << " Iterations" << endl;
	return (x_next);
}
