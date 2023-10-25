#pragma once

#include "MapaBase.h"
#include "PuntDeInteresBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"

class MapaSolucio : public MapaBase {
private:
    std::vector<PuntDeInteresBase*> m_pdis;
    std::vector<CamiBase*> m_camins;
    
    std::vector<XmlElement*> m_xml;




public:
    MapaSolucio();
    ~MapaSolucio();

    void getPdis(std::vector<PuntDeInteresBase*>& pdis) override;
    void getCamins(std::vector<CamiBase*>& camins) override;
    void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override;
};