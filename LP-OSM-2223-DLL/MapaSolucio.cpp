#pragma once
    
#include "MapaSolucio.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "Util.h"



MapaSolucio::MapaSolucio() {
    
    PuntDeInteresBotigaSolucio* bakery = new PuntDeInteresBotigaSolucio({ 41.4918606, 2.1465411 }, "La Millor Pastisseria", false, "bakery", "Div 06:00-22:00");

    PuntDeInteresRestaurantSolucio* restaurant = new PuntDeInteresRestaurantSolucio({ 41.4902204, 2.1406477 }, "El Millor Restaurant", true,"regional");

     
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

    
    
    
     
   

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{
    for (int i = 0; i < xmlElements.size(); i++) {
        double lat = 0;
        double lon = 0;
        string cuisine = "", name = "", shop = "";
        string opening_hours = "";
        bool wheelchair = false;
        string node_id = "";

        if (xmlElements[i].id_element == "node") {
            bool var_restaurant;
            bool var_shop;
            for (int j = 0; j < xmlElements[i].atributs.size(); j++) {
                if (xmlElements[i].atributs[j].first == "lon") {
                    lon = std::stod(xmlElements[i].atributs[j].second);
                }
                if (xmlElements[i].atributs[j].first == "lat") {
                    lat = std::stod(xmlElements[i].atributs[j].second);
                }
                if (xmlElements[i].atributs[j].first == "id") {
                    node_id = xmlElements[i].atributs[j].second;
                }
            }

            for (int j = 0; j < xmlElements[i].fills.size(); j++) {
                var_restaurant = false;
                var_shop = false;

                if (xmlElements[i].fills[j].first == "tag") {
                    if (xmlElements[i].fills[j].second[0].second == "cuisine") {
                        cuisine = xmlElements[i].fills[j].second[1].second;
                        var_restaurant = true;
                    }
                    if (xmlElements[i].fills[j].second[0].second == "name") {
                        name = xmlElements[i].fills[j].second[1].second;
                    }
                    if (xmlElements[i].fills[j].second[0].second == "shop") {
                        shop = xmlElements[i].fills[j].second[1].second;
                        var_shop = true;
                    }
                    if (xmlElements[i].fills[j].second[0].second == "opening_hours") {
                        shop = xmlElements[i].fills[j].second[1].second;
                    }
                    if (xmlElements[i].fills[j].second[0].second == "wheelchair") {
                        string aux = xmlElements[i].fills[j].second[1].second;
                        if (aux == "yes") {
                            wheelchair = true;
                        }
                    }
                }
                //tonto quien lo lea
                if (var_restaurant && name != "") {
                    PuntDeInteresRestaurantSolucio* restaurant = new PuntDeInteresRestaurantSolucio({ lat, lon }, name, wheelchair, cuisine);
                    m_pdis.push_back(restaurant);
                }
                if (var_shop && name != "") {
                    PuntDeInteresBotigaSolucio* bakery = new PuntDeInteresBotigaSolucio({ lat, lon }, name, wheelchair, shop, opening_hours);
                    m_pdis.push_back(bakery);
                }
            } 
        }
        /* if (xmlElements[i].id_element == "way") {
            bool isHighway = false;
            int j = 0;

            while (j < xmlElements[i].fills.size() && !isHighway) {
                if (xmlElements[i].fills[j].second[0].second == "highway") {
                    isHighway = true;
                }
                j++;
            }

            if (isHighway) {
                std::vector<string> nodes;
                std::vector<Coordinate> nodosCoords;
                for (int k = 0; k < xmlElements[i].fills.size(); k++) {
                    if (xmlElements[i].fills[k].second[0].second == "nd") {
                        nodes.push_back(xmlElements[i].fills[k].second[1].second);
                    }
                }
                CamiSolucio* aux = new CamiSolucio();
                for (int n = 0; n < nodes.size(); n++) {
                    for (int s = 0; s < xmlElements.size(); s++) {
                        if (xmlElements[s].id_element == "node") {
                            int p = 0; bool var = false;
                            while (p < xmlElements[s].atributs.size() && !var) {
                                if (xmlElements[s].atributs[p].first == "id" && xmlElements[s].atributs[p].second == nodes[n]) {
                                    double lat = 0;
                                    double lon = 0;
                                    for (int a = 0; a < xmlElements[s].atributs.size(); a++) {
                                        if (xmlElements[s].atributs[a].first == "lat") {
                                            lat = std::stod(xmlElements[s].atributs[a].second);
                                        }
                                        if (xmlElements[s].atributs[a].first == "lon") {
                                            lon = std::stod(xmlElements[s].atributs[a].second);
                                        }
                                    }

                                    if (lat != 0 && lon != 0) {
                                        nodosCoords.push_back({ lat, lon });
                                        var = true;
                                    }
                                }
                                p++;
                            }
                        }
                    }

                }
                aux->getCamiCoords_par(nodosCoords);
                m_camins.push_back(aux);
                nodosCoords.clear();
                nodes.clear();
            } */
        }
    }

 

    


    