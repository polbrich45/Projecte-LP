#pragma once

#include "MapaBase.h"
#include "PuntDeInteresBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"
#include <unordered_map>
#include "Graf.h"

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
    std::unordered_map<std::string, std::pair<double, double>> obtenirNodes(const std::vector<XmlElement>& xmlElements);
    CamiBase* buscaCamiMesCurt(PuntDeInteresBase* desde, PuntDeInteresBase* a);
};