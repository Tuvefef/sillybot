#include <dpp/dpp.h>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>

#include "program/sillystr.hh"
#include "program/sllconst.h"
#include "program/sllweather.hh"

    /*
This struct is commented out as it is not used in the current implementation
It can be uncommented if needed in the future

struct registeryt{
    std::string gtitle;
    std::string gurl;
    std::string gtmbl;
}; 
    */

int main(){
    dpp::cluster bot(gSillyTock);
    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand(
        [&bot] (const dpp::slashcommand_t& iDataEvent){
            std::string iDataCommd = iDataEvent.command.get_command_name();
            std::string iEmbedCommd = std::to_string(iDataEvent.command.channel_id);

            if(iDataCommd == gCommDef1){
                iDataEvent.reply(dpp::message(iEmbedCommd, dpp::embed().set_color(fSSLCOLOR5).set_title(gCommRes1)));
            
            } else if(iDataCommd == gCommDef2){
                std::string gcity = std::get<std::string>(iDataEvent.get_parameter("city"));
                std::string gurl = "https://api.openweathermap.org/data/2.5/weather?q=" + gcity + "&units=metric&lang=es&appid=" + fwheatherapik;
                cpr::Response r = cpr::Get(cpr::Url{gurl});

                if(r.status_code == 200){
                    nlohmann::json gDataw = nlohmann::json::parse(r.text);
                    std::string gresult = fWheaterRegister(gDataw, gcity);
                    iDataEvent.reply(dpp::message(iEmbedCommd, 
                        dpp::embed()
                        .set_color(fSSLCOLOR2)
                        .set_title(gCommDef2)
                        .set_description(gresult)
                    ));
                }
            } else {
                iDataEvent.reply(gCommErr);
            }
        }
    );

    bot.on_ready(
        [&bot] (const dpp::ready_t& iDataEvent){
            if(dpp::run_once <struct register_bot_commands> ()){
                bot.global_command_create(dpp::slashcommand(gCommDef1, "language in which I am made", bot.me.id));

                dpp::slashcommand gcomm2(gCommDef2, "get the wheather of a city", bot.me.id);
                gcomm2.add_option(dpp::command_option(dpp::co_string, "city", "name of the city", true));
                bot.global_command_create(gcomm2);
            }
        }
    );

    bot.start(dpp::st_wait);
}