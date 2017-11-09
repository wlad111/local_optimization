// local_optimization.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	int t, v;
	char s = 'a', u = 'a';
	AbstractFunction* f = 0;
	

	while ((s != '0') && (s != '1') && (s != '2'))
	{
		cout << "Choose Function to optimize:" << endl;
		cout << ROSENBROCK_FUNCTION << " Press 0" << endl;
		cout << HIMMELBLAU_FUNCTION << " Press 1" << endl;
		cout << FOURTH_DEGREE_FUNCTION << " Press 2" << endl;
		cin >> s;
	}

	switch (s)
	{
	case '0':
	{
		f = new FunctionOne;
		break;
	}
	case '1':
	{
		f = new HimmelblauFunction;
		break;
	}
	case '2':
		f = new FourthDegreeFunction;
		break;
	}

	cout << "Default left borders: " << endl << f->getArea().getLeft() << endl << "Default right borders: " << endl << f->getArea().getRight() << endl << "Press 0 for use custom constrains, something else for defaults";
	cin >> u;
	switch (u)
	{
	case '0':
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
	cout << "Choose the way of optimization: 0 -- for Newton method, anything else -- for random search" << endl;
	cin >> t;

	switch (t)
	{
	case 0:
	{
		AbstractStopCrit* crit = 0;
		NewtonOptimizer newton;
		VectorXd x0(f->getDim());
		cout << "Press 0 for Near Points Criterion, anything else for Near values" << endl;
		cin >> v;
		switch (v)
		{
		case 0:
		{
			crit = new NearPointsCrit;
			break;
		}
		default:
			crit = new ValuesCriterion;
			break;
		}
		cout << "Enter initial vector:" << endl;
		for (int i = 0; i < f->getDim(); i++)
		{
			cin >> x0(i);
		}
		try 
		{
			cout << newton.optim(x0, EPSILON, *f, *crit);
		}
		catch (exception &x)
		{
			cout << x.what() << endl;
		}
		break;
	}
	default:
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


