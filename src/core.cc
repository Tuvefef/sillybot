#include <dpp/dpp.h>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>

#include "program/sillystr.hh"
#include "program/sllconst.h"
#include "program/sllweather.hh"
#include "program/slllogic.hh"

    /*
This struct is commented out as it is not used in the current implementation
It can be uncommented if needed in the future
    */

struct registeryt{
    std::string gtitle;
    std::string gurl;
    std::string gtmbl;
}; 

int main(){
    dpp::cluster bot(gSillyTock);
    bot.on_log(dpp::utility::cout_logger());

    ssslllogic slogic;
    slogic.minitlogic(bot);

    bot.start(dpp::st_wait);
    return 0;
}