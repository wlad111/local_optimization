#pragma once
class AbstractArea
{
public:
	AbstractArea();
	virtual ~AbstractArea();
	int getDim() const;
protected:
	int dim;
};

