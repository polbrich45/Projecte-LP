#pragma once

#include "Common.h"
#include <vector>

class CamiBase {
	public:
		
		virtual std::vector<Coordinate> getCamiCoords() = 0;
		virtual std::vector<Coordinate> getCamiCoords_par(std::vector<Coordinate> camiCoords)=0;
};

