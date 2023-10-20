#pragma once
#include "pch.h"
#include "CamiBase.h"

class CamiSolucio: public CamiBase {
public:
	
	std::vector<Coordinate> getCamiCoords() = 0
    {
        std::vector<Coordinate> coordenadas;

        coordenadas.push_back({ 41.4928803, 2.1452381 });
        coordenadas.push_back({ 41.4929072, 2.1452474 });
        coordenadas.push_back({ 41.4933070, 2.1453852 });
        coordenadas.push_back({ 41.4939882, 2.1456419 });

        return coordenadas;
    }

};