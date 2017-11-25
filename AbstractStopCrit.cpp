#include "AbstractStopCrit.h"



AbstractStopCrit::AbstractStopCrit()
{

}

AbstractStopCrit::~AbstractStopCrit()
{

}

AbstractStopCrit::AbstractStopCrit(double eps)
{
	epsilon = eps;
}

double AbstractStopCrit::getEpsilon() const
{
	return epsilon;
}

double AbstractStopCrit::setEpsilon(double eps)
{
	epsilon = eps;
	return epsilon;
}
