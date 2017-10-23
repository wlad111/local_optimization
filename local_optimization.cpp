// local_optimization.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <Eigen/Dense>
#include "FunctionOne.h"
#include "NewtonOptimizer.h"
#include "NearPointsCrit.h"
#include "ValuesCriterion.h"
#include "RandomSearch.h"
#include "RectangularArea.h"
#include "Function4Dim.h"
#include "Values.h"

using namespace Eigen;
using namespace std;

int main()
{
	int t;
	//VectorXd r(2), l(2), y0(4), r4(4), l4(4);
	cout << "Function to optimize" << endl;
	cout << "100 * (x(1) - x(0) * x(0))*(x(1) - x(0) * x(0)) + (1 - x(0)) * (1 - x(0))" << endl;
	cout << "Define rectangular Area. Enter left borders:" << endl;
	FunctionOne f;
	VectorXd left(f.getDim()), right(f.getDim());
	for (int i = 0; i < f.getDim(); i++)
	{
		cin >> left(i);
	}
	cout << "Enter right borders:" << endl;
	for (int i = 0; i < f.getDim(); i++)
	{
		cin >> right(i);
	}
	f.setArea(left, right);
	cout << "Choose the way of optimization: 0 -- for Newton method, 1 -- for random search" << endl;
	cin >> t;

	switch (t)
	{
	case 0:
	{
		NewtonOptimizer newton;
		VectorXd x0(f.getDim());
		cout << "Enter initial vector:" << endl;
		for (int i = 0; i < f.getDim(); i++)
		{
			cin >> x0(i);
		}
		NearPointsCrit stop;
		cout << newton.optim(x0, EPSILON, f, stop);
		break;
	}
	case 1:
		RandomSearch rs(0.5);
		cout << rs.optim(f) << endl;
		break;
	}

	
	
	//ValuesCriterion stop;
	
	//RandomSearch rs(0.5);
	//cout << "Newton" << endl;
	//cout << newton.optim(x0, EPSILON, f, stop) << endl;
	//cout << "Random Search:" << endl;
	//cout << rs.optim(x0, EPSILON, f, stop) << endl;
	system("pause");
}


