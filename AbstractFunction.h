/*!
	\brief Abstract multidimensional function

	This is base class to represent abstract multidimensional functions.
*/


#pragma once

#include <Eigen/Dense>
#include "RectangularArea.h"



using namespace Eigen;
using namespace std;

class AbstractFunction
{
public:
	/*!
		evaluates function at chosen vector
		\param[in] x Vector of corresponding dimension
	*/
	virtual double eval(const VectorXd &x) const = 0;
	virtual string getName() = 0;
	/*! 
		counts approximate gradient of a function at chosen vector
		\param[in] x Vector of corresponding dimension
	*/
	VectorXd gradient(const VectorXd &x) const; 
	/*!
		counts approximate hessian (matrix of second partial derivatives) at chosen vector
		\param[in] x Vector of corresponding dimension
	*/
	MatrixXd hessian(const VectorXd &x) const;
	/*!
		returns dimension
	*/
	int getDim() const;
	/*!
		returns box domain of function
	*/
	RectangularArea getArea() const;
	AbstractFunction();
	virtual ~AbstractFunction();
	/*!
		sets box domain of function
		\param[in] l Vector of left borders
		\param[in] r Vector of right borders
	*/
	void setArea(const VectorXd &l, const VectorXd &r);
protected: 
	int dim;
	bool isConvex;
	RectangularArea domain;
};

