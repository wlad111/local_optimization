#include "RectangularArea.h"



RectangularArea::RectangularArea()
{

}

RectangularArea::RectangularArea(const VectorXd &l, const VectorXd &r, int d)
{
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
