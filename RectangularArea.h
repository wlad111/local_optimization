/*!
	\brief box area class

	Class that represents multidimensional box area
*/

#pragma once
#include "AbstractArea.h"
#include <Eigen/Dense>
#include <random>

using namespace Eigen;

class RectangularArea :
	public AbstractArea
{
public:
	/*!
		gets vector of left borders
	*/
	VectorXd getLeft() const;
	/*!
		gets vector of right borders
	*/
	VectorXd getRight() const;
	bool isPointInArea(const VectorXd &x) const;
	RectangularArea();
	RectangularArea(const VectorXd &l, const VectorXd &r, int d);
	~RectangularArea();
private:
	VectorXd left;
	VectorXd right;
};

