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
#include "HimmelblauFunction.h"
#include "FourthDegreeFunction.h"

using namespace Eigen;
using namespace std;

int main()
{
	int t, s, u, v;
	AbstractFunction* f = 0;
	cout << "Choose Function to optimize:" << endl;
	cout << ROSENBROCK_FUNCTION << " Press 0" << endl;
	cout << HIMMELBLAU_FUNCTION << " Press 1" <<  endl;
	cout << FOURTH_DEGREE_FUNCTION << " Press 2" << endl;
	cin >> s;
	switch (s)
	{
	case 0:
	{
		f = new FunctionOne;
		break;
	}
	case 1:
	{
		f = new HimmelblauFunction;
		break;
	}
	case 2:
		f = new FourthDegreeFunction;
		break;
	}
	cout << "Default left borders: " << endl << f->getArea().getLeft() << endl << "Default right borders: " << endl << f->getArea().getRight() << endl << "Press 0 for use custom constrains, something else for defaults";
	cin >> u;
	switch (u)
	{
	case 0:
	{
		VectorXd left(f->getDim()), right(f->getDim());
		cout << "Enter left borders:" << endl;
		for (int i = 0; i < f->getDim(); i++)
		{
			cin >> left(i);
		}
		cout << "Enter right borders:" << endl;
		for (int i = 0; i < f->getDim(); i++)
		{
			cin >> right(i);
		}
		f->setArea(left, right);
		break;
	}
	default:
		break;
	}
	cout << "Choose the way of optimization: 0 -- for Newton method, 1 -- for random search" << endl;
	cin >> t;

	switch (t)
	{
	case 0:
	{
		AbstractStopCrit* crit = 0;
		NewtonOptimizer newton;
		VectorXd x0(f->getDim());
		cout << "Press 0 for Near Points Criterion, 1 for Near values" << endl;
		cin >> v;
		switch (v)
		{
		case 0:
		{
			crit = new NearPointsCrit;
			break;
		}
		case 1:
			crit = new ValuesCriterion;
			break;
		}
		cout << "Enter initial vector:" << endl;
		for (int i = 0; i < f->getDim(); i++)
		{
			cin >> x0(i);
		}
		cout << "Choose stop criterion" << endl;
		//NearPointsCrit stop;
		cout << newton.optim(x0, EPSILON, *f, *crit);
		break;
	}
	case 1:
	{
		RandomSearch rs(0.7);
		VectorXd res = rs.optim(*f);
		cout << res << endl;
		cout << f->eval(res);
		break;
	}
	}
	delete f;
	system("pause");
}


