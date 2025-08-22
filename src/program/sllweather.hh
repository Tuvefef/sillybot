#ifndef SILLYWEATHER_H
#define SILLYWEATHER_H

#include <string>
#include <sstream>
#include <nlohmann/json.hpp>

std::string fWheaterRegister(const nlohmann::json& esymdata, const std::string& esymcity){
    std::ostringstream gSStrm;
    std::string gCity = esymcity.empty() ? "unknown city!" : esymcity;

    std::string gdesc = esymdata["weather"][0]["description"];
    double gtemp = esymdata["main"]["temp"];
    double gsens = esymdata["main"]["feels_like"];
    double gairs = esymdata["wind"]["speed"];

    gSStrm << "The weather in " << gCity << " is: \n";
    gSStrm << "temperature: " << gtemp << "°C, \n";
    gSStrm << "feels like: " << gsens << "°C, \n";
    gSStrm << "wind speed: " << gairs << " m/s, \n";
    gSStrm << "description: " << gdesc;

    std::string finaltrm = gSStrm.str();
    return finaltrm;
}

#endif