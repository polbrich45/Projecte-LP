#pragma once

#include "MapaSolucio.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"

using namespace std;

MapaSolucio::MapaSolucio() {

	PuntDeInteresBotigaSolucio* bakery = new PuntDeInteresBotigaSolucio({ 41.4918606, 2.1465411 }, "La Millor Pastisseria", "bakery", " ", false);
	PuntDeInteresRestaurantSolucio* restaurant = new PuntDeInteresRestaurantSolucio({ 41.4902204, 2.1406477 }, "El Millor Restaurant", "restaurant", false);

	m_pdis.push_back(bakery);
	m_pdis.push_back(restaurant);

	m_camins.push_back(new CamiSolucio());
}

MapaSolucio::~MapaSolucio() {

	for (auto pdi : m_pdis) {
		delete pdi;
	}

	for (auto camins : m_camins) {
		delete camins;
	}
}

void MapaSolucio::getPdis(vector<PuntDeInteresBase*>& pdis){
	pdis = m_pdis;
}

void MapaSolucio::getCamins(std::vector<CamiBase*>& camins) {
	camins = m_camins;
}