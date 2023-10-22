#pragma once
#include "PuntDeInteresBase.h"

class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase
{

private:

	string m_cuisine;
	bool m_normatiu;
public:
	PuntDeInteresRestaurantSolucio() : PuntDeInteresBase(), m_cuisine("undefinit"),
		m_normatiu(false){}
	PuntDeInteresRestaurantSolucio(Coordinate coord, string name, string cuina, bool invalid)
		: PuntDeInteresBase(coord, name), m_cuisine(cuina), m_normatiu(invalid) {};

	//td::string getName();
	//Coordinate getCoord();
	unsigned int getColor();







};

