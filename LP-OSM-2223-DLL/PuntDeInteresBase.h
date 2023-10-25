#pragma once

#include <string>
#include "Common.h"
using namespace std;

class PuntDeInteresBase {

	private:
		Coordinate m_coord;
		std::string m_name;
		bool m_wheelchair;
	public:		
		PuntDeInteresBase();
		PuntDeInteresBase(Coordinate coord, std::string name);
		
		virtual bool getWheelchair() { return m_wheelchair; }
		string getName();
		virtual Coordinate getCoord();
		virtual unsigned int getColor();

};
