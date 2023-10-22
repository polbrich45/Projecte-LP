#pragma once
#include "MapaBase.h"
#include "PuntDeInteresBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"


using namespace std;

class MapaSolucio :
    public MapaBase
{  
public:
    MapaSolucio();
    ~MapaSolucio();

    void getPdis(vector<PuntDeInteresBase*>&);

private:
    vector<PuntDeInteresBase*> m_pdis;
};

