#include "BallTree.h"


void BallTree::construirArbre(const std::vector<Coordinate>& coordenades) {
    if (m_coordenades.empty()) {
        m_coordenades = coordenades;


        double sumX = 0.0, sumY = 0.0;
        for (const auto& coord : coordenades) {
            sumX += coord.lat;
            sumY += coord.lon;

            m_pivot = Coordinate{ sumX / coordenades.size(), sumY / coordenades.size() };

            if (m_coordenades.size() > 1) {
                Coordinate A, Q;
                double maxDist = 0.0, minDist = 9999999999999999999;
                for (const auto& coord : coordenades) {
                    double dist = Util::DistanciaHaversine(coord, m_pivot);
                    if (dist > maxDist) {
                        maxDist = dist;
                        A = coord;
                    }
                    if (dist < minDist) {
                        minDist = dist;
                        Q = coord;
                    }
                }


                std::vector<double> distanciasA, distanciasQ;
                for (const auto& coord : coordenades) {

                    distanciasA.push_back(Util::DistanciaHaversine(coord, A));
                    distanciasQ.push_back(Util::DistanciaHaversine(coord, Q));
                }


                std::vector<Coordinate> leftCoords, rightCoords;
                for (size_t i = 0; i < coordenades.size(); ++i) {
                    if (distanciasA[i] < distanciasQ[i]) {
                        leftCoords.push_back(m_coordenades[i]);
                    }
                    else {
                        rightCoords.push_back(m_coordenades[i]);
                    }
                }

                if (!leftCoords.empty()) {
                    m_left = new BallTree();
                    m_left->construirArbre(leftCoords);
                }
                if (!rightCoords.empty()) {
                    m_right = new BallTree();
                    m_right->construirArbre(rightCoords);
                }
            }
        }
    }
}

void BallTree::inOrdre(std::vector<std::list<Coordinate>>& out) {
    // TODO: TASCA 2
}
void BallTree::preOrdre(std::vector<std::list<Coordinate>>& out) {
    // TODO: TASCA 2
}

void BallTree::postOrdre(std::vector<std::list<Coordinate>>& out) {
    // TODO: TASCA 2
}

Coordinate BallTree::nodeMesProper(Coordinate targetQuery, Coordinate& Q, BallTree* ball) {
    // TODO: TASCA 3
    Q = { 0.00,0.00 };
    if (ball->getRadi() == 0.001) { Q = ball->getPivot(); }
    double target_distance = Util::DistanciaHaversine(targetQuery, ball->getPivot());
    double ball_distance = Util::DistanciaHaversine(targetQuery, Q);

    if (target_distance - ball->getRadi() >= ball_distance) {
        return Q;
    }
    else {


        double target_distance_left = Util::DistanciaHaversine(targetQuery, ball->getEsquerre()->getPivot());
        double target_distance_right = Util::DistanciaHaversine(targetQuery, ball->getDreta()->getPivot());

        if (target_distance_left < target_distance_right) {
            nodeMesProper(targetQuery, Q, ball->getEsquerre());
        }
        else {
            nodeMesProper(targetQuery, Q, ball->getDreta());
        }
    }
}



