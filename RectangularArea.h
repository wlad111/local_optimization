#pragma once
#include "AbstractArea.h"
#include <Eigen/Dense>
#include <random>

using namespace Eigen;

class RectangularArea :
	public AbstractArea
{
public:
	VectorXd getLeft();
	VectorXd getRight();
	RectangularArea();
	RectangularArea(VectorXd &l, VectorXd &r, int d);
	~RectangularArea();
private:
	VectorXd left;
	VectorXd right;
};

