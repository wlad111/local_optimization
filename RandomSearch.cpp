#include "RandomSearch.h"
#include "Values.h"
#include <iostream>

using namespace std;


RandomSearch::RandomSearch(double prob)
{
	p = prob;
	random_device rd;
	mt19937 mt(rd());
	RNG = mt;
	uniform_real_distribution<> d(0,1);
	dist = d;
}


RandomSearch::~RandomSearch()
{

}

VectorXd RandomSearch::optim(AbstractFunction &f)
{
	bool flag = false;
	double t, delta = 0.02;
	int i = 1, j = 0;
	int dim = f.getDim();
	VectorXd y_prev(dim), y_next(dim), x(dim), left(dim), right(dim), x0(dim);
	x = getPointInArea(f.getArea());
	x0 = getPointInArea(f.getArea());
	y_prev = x0;
	y_next = x;
	while ((i < MAX_ITERATIONS) && (j < COUNT_SUCCESSES))
	{
		t = dist(RNG);
		if (t < p)
		{
			x = getPointInArea(f.getArea());
			if (f.eval(x) < f.eval(y_next))
			{
				y_prev = y_next;
				y_next = x;
				j++;
			}
		}
		else
		{
			for (int i = 0; i < dim; i++)
			{
				if ((y_next(i) - delta) < f.getArea().getLeft()(i)) 
				{
					left(i) = f.getArea().getLeft()(i);
					flag = true;
				}
				else
				{
					left(i) = y_next(i) - delta;
				}
				if ((y_next(i) + delta) > f.getArea().getRight()(i))
				{
					right(i) = f.getArea().getRight()(i);
					flag = true;
				}
				else
				{
					right(i) = y_next(i) + delta;
				}
			}
			//left = y_next - VectorXd::Constant(dim, delta);
			//right = y_next + VectorXd::Constant(dim, delta);
			RectangularArea vicinity(left, right, dim);
			x = getPointInArea(vicinity);
			if ((f.eval(x) < f.eval(y_next)))
			{	
				//delta *= 0.9;
				y_prev = y_next;
				y_next = x;
				j++;
			}
		}
		i++;
		//cout << i << " Iteration" << endl;
		//cout << y_next << endl;

	}
	cout << i << " Iterations" << endl;
	return y_next;
}

VectorXd RandomSearch::getPointInArea(RectangularArea& area)
{
	VectorXd point(area.getDim());
	for (int i = 0; i < area.getDim(); i++)
	{
		point(i) = (area.getRight()(i) - area.getLeft()(i))*dist(RNG) + area.getLeft()(i);
	}
	return point;
}
