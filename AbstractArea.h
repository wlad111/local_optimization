#pragma once
class AbstractArea
{
public:
	AbstractArea();
	virtual ~AbstractArea();
	const int getDim();
protected:
	int dim;
};

