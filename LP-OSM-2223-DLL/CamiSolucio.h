#pragma once


#include "CamiBase.h"


class CamiSolucio : public CamiBase {
public:
    std::vector<Coordinate> getCamiCoords();

    CamiSolucio() { getCamiCoords(); }
};