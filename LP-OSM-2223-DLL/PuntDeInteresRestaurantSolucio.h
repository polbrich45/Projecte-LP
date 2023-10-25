#pragma once
#include "PuntDeInteresBase.h"

class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase
{

private:

	string m_cuisine;
public:
	PuntDeInteresRestaurantSolucio() : PuntDeInteresBase(), m_cuisine("undefinit") {}
	PuntDeInteresRestaurantSolucio(Coordinate coord, string name, string cuina, bool invalid)
		: PuntDeInteresBase(coord, name), m_cuisine(cuina) {};

	unsigned int getColor();

};


