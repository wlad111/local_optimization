#include "RectangularArea.h"



RectangularArea::RectangularArea()
{

}

RectangularArea::RectangularArea(VectorXd &l, VectorXd &r, int d)
{
	dim = d;
	left = l;
	right = r;
}

RectangularArea::~RectangularArea()
{
}

VectorXd RectangularArea::getLeft()
{
	return left;
}

VectorXd RectangularArea::getRight()
{
	return right;
}
