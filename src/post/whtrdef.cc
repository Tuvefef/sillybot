#include "../program/whtrcomm.hh"
#include "../program/sillystr.hh"
#include "../program/sllconst.h"
//#include "../program/sllweather.hh"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

std::string mwhtrcomm::mdefcomm() const{
    return gCommDef2;
}

std::string mwhtrcomm::mdefdesc() const{
    return "get the wheather of a city";
}

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

void mwhtrcomm::mdefExecComm(const dpp::slashcommand_t& iDataEvent){
    std::string iEmbedCommd = std::to_string(iDataEvent.command.channel_id);
    std::string gCity = std::get<std::string>(iDataEvent.get_parameter("city"));
    std::string gUrl = "https://api.openweathermap.org/data/2.5/weather?q=" + gCity + "&units=metric&lang=es&appid=" + fwheatherapik;
    cpr::Response mrm = cpr::Get(cpr::Url{gUrl});

    if(mrm.status_code == 200){
        nlohmann::json gDataw = nlohmann::json::parse(mrm.text);
        std::string gresult = fWheaterRegister(gDataw, gCity);

        iDataEvent.reply(dpp::message(iEmbedCommd, 
            dpp::embed()
            .set_color(fSSLCOLOR2)
            .set_title(gCommDef2)
            .set_description(gresult)
        ));
    }
}