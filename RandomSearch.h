#pragma once
#include "AbstractOptimization.h"
#include "RectangularArea.h"
#include <Eigen/Dense>
#include <random>

using namespace Eigen;

class RandomSearch :
	public AbstractOptimizer
{
public:
	VectorXd optim(AbstractFunction &f);
	VectorXd getPointInArea(RectangularArea &area);
	RandomSearch(double prob);
	~RandomSearch();
private: 
	double p;
	mt19937 RNG;
	uniform_real_distribution<> dist;
};

