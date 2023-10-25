#pragma once
    
#include "MapaSolucio.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"


MapaSolucio::MapaSolucio() {
    
    PuntDeInteresBotigaSolucio* bakery = new PuntDeInteresBotigaSolucio({ 41.4918606, 2.1465411 }, "La Millor Pastisseria", "bakery");

    PuntDeInteresRestaurantSolucio* restaurant = new PuntDeInteresRestaurantSolucio({ 41.4902204, 2.1406477 }, "El Millor Restaurant", "restaurant");

     
    m_pdis.push_back(bakery);
    m_pdis.push_back(restaurant);

    
    m_camins.push_back(new CamiSolucio());
}

MapaSolucio::~MapaSolucio() {
    
    for (auto pdi : m_pdis) {
        delete pdi;
    }
    for (auto cami : m_camins) {
        delete cami;
    }
}

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis) {
    pdis = m_pdis;
}

void MapaSolucio::getCamins(std::vector<CamiBase*>& camins) {
    camins = m_camins;
}
void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements) {
    
}