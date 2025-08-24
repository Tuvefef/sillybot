#include "../program/slllogic.hh"
#include "../program/madecomm.hh"
#include "../program/whtrcomm.hh"
#include "../program/sillystr.hh"

void ssslllogic::minitlogic(dpp::cluster& bot){
    mvcomm.push_back(std::make_unique<mmadecomm>());
    mvcomm.push_back(std::make_unique<mwhtrcomm>());

    bot.on_slashcommand([this](const dpp::slashcommand_t& iDataEvent){
        for(const auto& comm : mvcomm){
            if(iDataEvent.command.get_command_name() == comm->mdefcomm()){
                comm->mdefExecComm(iDataEvent);
                break;
            }
        }
        iDataEvent.reply("unknown command1");
    });

    bot.on_ready([&bot, this](const dpp::ready_t& iDataEvent){
        if(dpp::run_once<struct register_bot_commands> ()){
            for(const auto& comm : mvcomm){
                dpp::slashcommand sc(comm->mdefcomm(), comm->mdefdesc(), bot.me.id);
                
                if(comm->mdefcomm() == gCommDef2){
                    sc.add_option(dpp::command_option(dpp::co_string, "city", "name of the city", true));
                }
                bot.global_command_create(sc);
            }
        }
    });
}