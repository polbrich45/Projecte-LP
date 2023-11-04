#pragma once


#include "CamiBase.h"


class CamiSolucio : public CamiBase {
public:
    CamiSolucio() { m_cami={
        {41.4928803, 2.1452381},
        {41.4929072, 2.1452474 },
        {41.4933070, 2.1453852 },
        {41.4939882, 2.1456419 }

    };
    }
    CamiSolucio(std::vector<Coordinate> cami) { m_cami = cami; }
    std::vector<Coordinate> getCamiCoords();
    

private:
    std::vector<Coordinate> m_cami;
};