#include "RectangularArea.h"
#include <exception>

using namespace std;



RectangularArea::RectangularArea()
{

}

RectangularArea::RectangularArea(const VectorXd &l,
								const VectorXd &r, int d)
{
	for (int i = 0; i < d; i++)
	{
		if (l(i) > r(i))
		{
			throw exception("wrong area");
		}
	}
	dim = d;
	left = l;
	right = r;
}

RectangularArea::~RectangularArea()
{
}

VectorXd RectangularArea::getLeft() const
{
	return left;
}

VectorXd RectangularArea::getRight() const
{
	return right;
}

bool RectangularArea::isPointInArea(const VectorXd &x) const
{
	if (x.size() != dim) 
	{
		return false;
	}
	for (int i = 0; i < dim; i++)
	{
		if ((x(i) < left(i)) || (x(i) > right(i)))
		{
			return false;
		}
	}
	return true;
}