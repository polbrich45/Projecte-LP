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
	PuntDeInteresRestaurantSolucio(Coordinate coord, std::string name, bool wheelchair,std::string cuisine):PuntDeInteresBase(coord, name,wheelchair), m_cuisine(cuisine){}

	std::string getName(){ return PuntDeInteresBase::getName(); }
	bool getWheelChair() {
		return PuntDeInteresBase::getWheelChair();
	};
	 unsigned int getColor() {
		  if (m_cuisine == "chinese")
			 {
				 return 0xA6D9F7;
			 }
		 if (getWheelChair() == true) {
			 if (m_cuisine == "pizza")
			 {
				 return 0x03FCBA;
			 }
			 else {
				 return 0x251351;
			 }
		 }
		
		 return PuntDeInteresBase::getColor();
		 }
		 
		 

		 



	 
		 
			 
	

};