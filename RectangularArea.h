#pragma once
#include "AbstractArea.h"
#include <Eigen/Dense>
#include <random>

using namespace Eigen;

class RectangularArea :
	public AbstractArea
{
public:
	VectorXd getLeft() const;
	VectorXd getRight() const;
	RectangularArea();
	RectangularArea(const VectorXd &l, const VectorXd &r, int d);
	~RectangularArea();
private:
	VectorXd left;
	VectorXd right;
};

