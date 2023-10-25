#pragma once

#include <string>
#include "Common.h"
#include "PuntDeInteresBase.h"
#include <iostream>
using namespace std;

class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase {

private:
	
	
	string m_cuisine;

public:
	PuntDeInteresRestaurantSolucio();
	PuntDeInteresRestaurantSolucio(Coordinate coord, std::string name, std::string cuisine):PuntDeInteresBase(coord, name), m_cuisine(cuisine){}

	std::string getName(){ return PuntDeInteresBase::getName(); }
	bool getWheelChair() {
		return PuntDeInteresBase::getWheelChair();
	};
	 unsigned int getColor() {
		if (m_cuisine == "pizza" && getWheelChair() == true)
		{
			return 0x03FCBA;

		}

		if (m_cuisine == "chinese")
		{
			return 0xA6D9F7;
		}
		if (getWheelChair() == true) {
			return 0x251351;

		}
		else
		{
			return PuntDeInteresBase::getColor();
		}

	}
	

};