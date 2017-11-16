/*!
	\brief Random Search

	Class that provides random search in bounded area 
	to find global minimum of a function. Extends AbstractOptimizer
*/

#pragma once
#include "AbstractOptimization.h"
#include "RectangularArea.h"
#include "OptimizationResult.h"
#include <Eigen/Dense>
#include <random>

using namespace Eigen;

class RandomSearch :
	public AbstractOptimizer
{
public:
	/*!
		performs random search to find global minimum
		\param[in] f function to optimize
	*/
	OptimizationResult optim(const AbstractFunction &f);
	/*!
		gets random uniformly distributed point in an area
		\param[in] area box area
	*/
	VectorXd getPointInArea(const RectangularArea &area);
	RandomSearch(double prob);
	~RandomSearch();
private: 
	double p;
	mt19937 RNG;
	uniform_real_distribution<> dist;
};

