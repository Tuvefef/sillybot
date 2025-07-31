#include <dpp/dpp.h>
#include "program/sillystr.h"
#include "program/sllmacros.h"

int main(){
    dpp::cluster bot(gSillyTock);
    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand(
        [&bot] (const dpp::slashcommand_t& iDataEvent){
            std::string iDataCommd = iDataEvent.command.get_command_name();
            std::string iEmbedCommd = std::to_string(iDataEvent.command.channel_id);

            if(iDataCommd == gCommDef1){
                iDataEvent.reply(dpp::message(iEmbedCommd, dpp::embed().set_color(fSSLCOLOR1).set_title(gCommRes1)));
            } else {
                iDataEvent.reply(gCommErr);
            }
        }
    );

    bot.on_ready(
        [&bot] (const dpp::ready_t& iDataEvent){
            if(dpp::run_once <struct register_bot_commands> ()){
                bot.global_command_create(dpp::slashcommand(gCommDef1, "language in which I am made", bot.me.id));
            }
        }
    );

    bot.start(dpp::st_wait);
}