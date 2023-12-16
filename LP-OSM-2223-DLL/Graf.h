#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "MapaBase.h"
#include "Util.h"


class Graf {
public:
    Graf() : m_numNodes(0) {}

    Graf(std::vector<CamiBase*> camins) {
        for (auto cami : camins) {
            const std::vector<Coordinate>& camiCoords = cami->getCamiCoords();

            for (const auto& coord : camiCoords) {
                afegirNode(coord);
            }

            afegirArestesCami(camiCoords);
        }
    }

    void afegirNode(const Coordinate& node) {
        int pos = -1;

        for (int i = 0; i < m_nodes.size(); ++i) {
            if (m_nodes[i].lat == node.lat && m_nodes[i].lon == node.lon) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            m_nodes.push_back(node);
            m_matriuAdj.emplace_back(m_numNodes, 0.0);
            for (auto& row : m_matriuAdj)
                row.push_back(0.0);
            m_numNodes++;
        }
    }

    void afegirAresta(const Coordinate& node1, const Coordinate& node2) {
        int pos1 = -1, pos2 = -1;

        for (int i = 0; i < m_nodes.size(); ++i) {
            if (m_nodes[i].lat == node1.lat && m_nodes[i].lon == node1.lon) {
                pos1 = i;
            }
            if (m_nodes[i].lat == node2.lat && m_nodes[i].lon == node2.lon) {
                pos2 = i;
            }
        }

        if (pos1 != -1 && pos2 != -1) {
            double distancia = Util::DistanciaHaversine(node1, node2);
            m_matriuAdj[pos1][pos2] = distancia;
            m_matriuAdj[pos2][pos1] = distancia;
        }
    }

    void afegirArestesCami(const std::vector<Coordinate>& cami) {
        for (size_t i = 0; i < cami.size() - 1; i++) {
            afegirAresta(cami[i], cami[i + 1]);
        }
    }

    std::vector<Coordinate> dijkstra(const Coordinate& origen, const Coordinate& destino) {
        int posOrig = -1, posDest = -1;

        for (int i = 0; i < m_nodes.size(); ++i) {
            if (m_nodes[i].lat == origen.lat && m_nodes[i].lon == origen.lon) {
                posOrig = i;
                break;
            }
        }

        for (int i = 0; i < m_nodes.size(); ++i) {
            if (m_nodes[i].lat == destino.lat && m_nodes[i].lon == destino.lon) {
                posDest = i;
                break;
            }
        }

        if (posOrig == -1 || posDest == -1) {
            std::cerr << "Nodos de origen o destino no encontrados en el grafo.\n";
            return {};
        }

        std::vector<double> distancia(m_numNodes, std::numeric_limits<double>::infinity());
        std::vector<int> padre(m_numNodes, -1);

        distancia[posOrig] = 0;

        std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
        pq.push({ 0, posOrig });

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (int v = 0; v < m_numNodes; ++v) {
                double pesoUV = m_matriuAdj[u][v];
                if (pesoUV > 0 && distancia[u] + pesoUV < distancia[v]) {
                    distancia[v] = distancia[u] + pesoUV;
                    padre[v] = u;
                    pq.push({ distancia[v], v });
                }
            }
        }

        std::vector<Coordinate> camino;
        int actual = posDest;
        while (actual != -1) {
            camino.push_back(m_nodes[actual]);
            actual = padre[actual];
        }

        std::reverse(camino.begin(), camino.end());

        return camino;
    }

private:
    std::vector<Coordinate> m_nodes;
    std::vector<std::vector<double>> m_matriuAdj;
    int m_numNodes;
};
