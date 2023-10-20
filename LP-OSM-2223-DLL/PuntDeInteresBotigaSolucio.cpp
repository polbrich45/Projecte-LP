#include "pch.h"
#include "PuntDeInteresBotigaSolucio.h"

unsigned int PuntDeInteresBotigaSolucio::getColor()
{
    
    if (m_shop == "supermarket") {
        return 0xA5BE00;
    }
    else if (m_shop == "tobacco") {
        return 0xFFAD69;
    }
    else if (m_shop == "bakery") {
        
        if ((m_opening_hours.find("06:00 - 22 : 00") != std::string::npos) && m_wheelchair) {
            return 0x4CB944;
        }
        else {
            return 0xE85D75;
        }
    }
    else {
        return 0xEFD6AC;
    }
    
}

    

