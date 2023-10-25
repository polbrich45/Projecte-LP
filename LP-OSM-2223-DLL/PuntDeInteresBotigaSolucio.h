#pragma once
#include "PuntDeInteresBase.h"

class PuntDeInteresBotigaSolucio: public PuntDeInteresBase
{

private:
	
	string m_shop;
	string m_opening_hours;

public:
	PuntDeInteresBotigaSolucio() : PuntDeInteresBase() , m_shop("undefinit"),
		m_opening_hours("undefinit"){}
	PuntDeInteresBotigaSolucio(Coordinate coord, string name,string shopType, string hours,bool wheelc)
		: PuntDeInteresBase(coord, name), m_shop(shopType){};
	unsigned int getColor();
	std::string getName() { return PuntDeInteresBase::getName(); }
	bool getWheelChair() { return PuntDeInteresBase::getWheelchair(); }



};
