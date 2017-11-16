#include "OptimizationResult.h"



OptimizationResult::OptimizationResult()
{
}

OptimizationResult::OptimizationResult(VectorXd &point, 
										double value, 
										int iterations)
{
	optPoint = point;
	optValue = value;
	numIterations = iterations;
}

OptimizationResult::~OptimizationResult()
{
}

VectorXd OptimizationResult::getOptPoint() const
{
	return optPoint;
}

int OptimizationResult::getNumIterations() const
{
	return numIterations;
}

double OptimizationResult::getOptValue() const
{
	return optValue;
}