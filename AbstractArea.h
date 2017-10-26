/*!
	\brief Parent class for area in euclidian space
	
	This class is used to represent abstract area in euclidian space of arbitrary dimension
*/

#pragma once
class AbstractArea
{
public:
	AbstractArea();
	virtual ~AbstractArea();
	/*!
		returns the dimension of an area
	*/
	int getDim() const;
protected:
	int dim;
};

