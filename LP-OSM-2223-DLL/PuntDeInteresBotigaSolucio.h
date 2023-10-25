#pragma once

#include <string>
#include "Common.h"
#include "PuntDeInteresBase.h"
#include <iostream>
using namespace std;

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase {

private:
	
	string m_shop;
	string m_openingHours;
	

public:
	PuntDeInteresBotigaSolucio();
	PuntDeInteresBotigaSolucio(Coordinate coord, std::string name, std::string shopType):PuntDeInteresBase(coord, name), m_shop(shopType) {}

	std::string getName(){ return PuntDeInteresBase::getName(); }
	bool getWheelChair() { return PuntDeInteresBase::getWheelChair();
	};
	unsigned int getColor(){
	
		
		if (m_shop == "supermarket")
		{
			return 0xA5BE00;

		} 
		
		if (m_shop == "tobacco")
		{
			return 0xFFAD69;
		}
		if (m_shop == "bakery") {
			if (m_openingHours == "06:00-22:00" && getWheelChair() == true)
			{
				return 0x4CB944;
			}
			else
			{
				return 0xE85D75;
			}
			
		}
		else
		{
			return 0xEFD6AC;
		}

	}

};