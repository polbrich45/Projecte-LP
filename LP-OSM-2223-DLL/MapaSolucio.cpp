#pragma once

#include "MapaSolucio.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "Util.h"


MapaSolucio::MapaSolucio() {

    //* bakery = new PuntDeInteresBotigaSolucio({ 41.4918606, 2.1465411 }, "La Millor Pastisseria", false, "bakery", "Div 06:00-22:00");

    //PuntDeInteresRestaurantSolucio* restaurant = new PuntDeInteresRestaurantSolucio({ 41.4902204, 2.1406477 }, "Cafe Gaucho", false,"regional");


    //m_pdis.push_back(bakery);
    //m_pdis.push_back(restaurant);


    //m_camins.push_back((new CamiSolucio()));


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


//

CamiBase* MapaSolucio::buscaCamiMesCurt(PuntDeInteresBase* desde, PuntDeInteresBase* a) {
    Graf graf(m_camins);
    vector<Coordinate> camins = graf.dijkstra(desde->getCoord(), a->getCoord());
    return new CamiSolucio(camins);
}


void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{
    m_camins.clear();
    m_pdis.clear();
    m_xml.clear();

    std::unordered_map<std::string, std::pair<double, double>> nodes_map = obtenirNodes(xmlElements);
    for (int i = 0; i < xmlElements.size(); i++) {
        double lat = 0;
        double lon = 0;
        string cuisine = "", name = "", shop = "";
        string opening_hours = "";
        bool wheelchair = true;
        string node_id = "";

        if (xmlElements[i].id_element == "node") {
            bool var_restaurant = false;
            bool var_shop = false;
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
                        opening_hours = xmlElements[i].fills[j].second[1].second;
                        var_shop = true;
                    }
                    if (xmlElements[i].fills[j].second[0].second == "wheelchair") {
                        string aux = xmlElements[i].fills[j].second[1].second;
                        if (aux == "no") {
                            wheelchair = false;
                        }
                    }
                }
            }


            if ((var_restaurant || var_shop) && !name.empty() && (lat != 0 || lon != 0)) {
                if (var_restaurant) {
                    PuntDeInteresRestaurantSolucio* restaurant = new PuntDeInteresRestaurantSolucio({ lat, lon }, name, wheelchair, cuisine);
                    m_pdis.push_back(restaurant);
                }
                if (var_shop) {
                    PuntDeInteresBotigaSolucio* bakery = new PuntDeInteresBotigaSolucio({ lat, lon }, name, wheelchair, shop, opening_hours);
                    m_pdis.push_back(bakery);
                }
            }
        }

        if (xmlElements[i].id_element == "way") {
            bool isHighway = false;

            for (int j = 0; j < xmlElements[i].fills.size(); j++) {

                if (xmlElements[i].fills[j].first == "tag") {

                    if (xmlElements[i].fills[j].second[0].second == "highway") {
                        isHighway = true;
                    }

                }

            }


            if (isHighway) {
                std::vector<std::string> nodes;
                std::vector<Coordinate> nodosCoords;
                for (int j = 0; j < xmlElements[i].fills.size(); j++) {
                    if (xmlElements[i].fills[j].first == "nd") {

                        if (xmlElements[i].fills[j].second[0].first == "ref") {
                            nodes.push_back(xmlElements[i].fills[j].second[0].second);

                        }

                    }

                }

                for (int n = 0; n < nodes.size(); n++) {
                    auto node = nodes_map.find(nodes[n]);
                    if (node != nodes_map.end()) {
                        nodosCoords.push_back({ node->second.first, node->second.second });
                    }
                }

                m_camins.push_back((new CamiSolucio(nodosCoords)));
                nodosCoords.clear();
                nodes.clear();
            }

        }
    }
}

std::unordered_map<std::string, std::pair<double, double>> MapaSolucio::obtenirNodes(const std::vector<XmlElement>& xmlElements)
{
    std::unordered_map<std::string, std::pair<double, double>> nodesMap;
    for (const auto& element : xmlElements) {

        if (element.id_element == "node") {
            std::string id;
            double lat = 0;
            double lon = 0;

            for (const auto& atributo : element.atributs) {
                if (atributo.first == "id") {
                    id = atributo.second;
                }
                else if (atributo.first == "lat") {
                    lat = std::stod(atributo.second);
                }
                else if (atributo.first == "lon") {
                    lon = std::stod(atributo.second);
                }
            }

            if (lat != 0 && lon != 0) {
                nodesMap[id] = std::make_pair(lat, lon);
            }
        }
    }

    return nodesMap;


}


