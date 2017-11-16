#pragma once

#include <Eigen/Dense>

using namespace Eigen;

class OptimizationResult
{
public:
	OptimizationResult();
	OptimizationResult(VectorXd &point, double value, int iterations);
	~OptimizationResult();
	VectorXd getOptPoint() const;
	double getOptValue() const;
	int getNumIterations() const;
private:
	int numIterations;
	VectorXd optPoint;
	double optValue;
};

