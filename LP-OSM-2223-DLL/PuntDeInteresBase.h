#pragma once

#include <string>
#include "Common.h"

class PuntDeInteresBase {

	private:
		Coordinate m_coord;
		std::string m_name;
		bool wheelchair;

	public:		
		PuntDeInteresBase();
		PuntDeInteresBase(Coordinate coord, std::string name);

		virtual bool getWheelChair() { return wheelchair; };
		virtual std::string getName();
		virtual Coordinate getCoord();
		virtual unsigned int getColor();

};