#pragma once


#include "CamiBase.h"


class CamiSolucio : public CamiBase {
public:
    std::vector<Coordinate> getCamiCoords();
    std::vector<Coordinate> getCamiCoords_par(std::vector<Coordinate> camiCoords);
};