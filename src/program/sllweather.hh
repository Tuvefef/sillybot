#ifndef SILLYWEATHER_H
#define SILLYWEATHER_H

#include <string>
#include <sstream>
#include <nlohmann/json.hpp>

std::string fWheaterRegister(const nlohmann::json& esymdata, const std::string& esymcity);

#endif