#pragma once
#include "PuntDeInteresBase.h"

class PuntDeInteresBotigaSolucio: public PuntDeInteresBase
{

private:
	
	string m_shop;
	string m_opening_hours;
	bool m_wheelchair;

public:
	PuntDeInteresBotigaSolucio() : PuntDeInteresBase() , m_shop("undefinit"),
		m_opening_hours("undefinit"), m_wheelchair(false) {}
	PuntDeInteresBotigaSolucio(Coordinate coord, string name,string shopType, string hours,bool wheelc)
		: PuntDeInteresBase(coord, name), m_shop(shopType), m_opening_hours(hours), m_wheelchair(wheelc) {};

	std::string getName();
	Coordinate getCoord();
	unsigned int getColor();

	





};
