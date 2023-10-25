#pragma once

#include "MapaBase.h"
#include "PuntDeInteresBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"

using namespace std;

class MapaSolucio :
    public MapaBase
{  
public:
    MapaSolucio();
    ~MapaSolucio();

    void getPdis(vector<PuntDeInteresBase*>&) override;
    void getCamins(std::vector<CamiBase*>& camins) override;

private:
    vector<PuntDeInteresBase*> m_pdis;
    std::vector<CamiBase*> m_camins;
};

