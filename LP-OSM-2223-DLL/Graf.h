#pragma once

#include <iostream>

#include <vector>

#include <unordered_map>

#include "MapaBase.h"

#include "Util.h"



class Graf

{

public:

    Graf() : m_nodes(0) { }

    Graf(std::vector<CamiBase*> camins)

    {

        for (auto cami : camins)

        {



            std::vector<Coordinate> camiCoords = cami->getCamiCoords();



            for (const auto& coord : camiCoords) {

                afegirNode(coord);

                m_matriuAdj.push_back(std::vector<int>(m_numNodes));

                m_numNodes++;

                for (int i = 0; i < m_numNodes; i++) m_matriuAdj[i].push_back(0);

            }

            afegirArestesCami(cami->getCamiCoords());



        }



    }



    void afegirNode(const Coordinate& node)

    {

        auto it = std::find(m_nodes.begin(), m_nodes.end(), node);



        if (it != m_nodes.end())

        {

            m_nodes.push_back(node);

        }





    }



    void afegirAresta(const Coordinate& node1, const Coordinate& node2)

    {



        auto it1 = std::find(m_nodes.begin(), m_nodes.end(), node1);

        auto it2 = std::find(m_nodes.begin(), m_nodes.end(), node2);

        int pos1 = m_nodes.end() - it1;

        int pos2 = m_nodes.end() - it2;





        if (it1 != m_nodes.end() && it2 != m_nodes.end())

        {

            double distancia = Util::DistanciaHaversine(node1, node2);

            m_matriuAdj[pos1][pos2] = distancia;

            m_matriuAdj[pos2][pos1] = distancia;

        }





    }

    void afegirArestesCami(std::vector<Coordinate> cami)

    {

        for (int i = 0; i < cami.size(); i++)

        {

            afegirAresta(cami[i], cami[i + 1]);



        }



    }

private:

    std::vector<Coordinate> m_nodes;

    std::vector<std::vector<int>> m_matriuAdj;

    int m_numNodes;



};

