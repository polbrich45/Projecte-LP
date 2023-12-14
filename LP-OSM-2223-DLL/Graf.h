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


            }

            afegirArestesCami(cami->getCamiCoords());



        }



    }



    void afegirNode(const Coordinate& node)

    {

        auto it = std::find(m_nodes.begin(), m_nodes.end(), node);



        if (it == m_nodes.end())

        {

            m_nodes.push_back(node);

            m_matriuAdj.push_back(std::vector<double>(m_numNodes));

            for (int i = 0; i < m_numNodes; i++) m_matriuAdj[i].push_back(0);

            m_numNodes++;

        }

        

    }



    void afegirAresta(const Coordinate& node1, const Coordinate& node2)

    {



        auto it1 = std::find(m_nodes.begin(), m_nodes.end(), node1);

        auto it2 = std::find(m_nodes.begin(), m_nodes.end(), node2);

        int pos1 = it1 - m_nodes.begin();

        int pos2 = it2 - m_nodes.begin();





        if (it1 != m_nodes.end() && it2 != m_nodes.end())

        {

            double distancia = Util::DistanciaHaversine(node1, node2);

            m_matriuAdj[pos1][pos2] = distancia;

            m_matriuAdj[pos2][pos1] = distancia;

        }





    }

    void afegirArestesCami(std::vector<Coordinate> cami)

    {

        for (int i = 0; i < cami.size()-1; i++)

        {

            afegirAresta(cami[i], cami[i + 1]);



        }



    }

private:

    std::vector<Coordinate> m_nodes;

    std::vector<std::vector<double>> m_matriuAdj;

    int m_numNodes;



};

