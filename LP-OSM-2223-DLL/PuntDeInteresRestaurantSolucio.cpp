#include "pch.h"
#include "PuntDeInteresRestaurantSolucio.h"

unsigned int PuntDeInteresRestaurantSolucio::getColor()
{
    if (m_cuisine == "pizza" && m_normatiu) {
        return 0x03FCBA;
    }
    else if (m_cuisine == "chinese") {
        return 0xA6D9F7;
    }
    else if (m_normatiu) {
        return 0x251351;
    }
    else {
        return 0xEFD6AC;
    }
}
