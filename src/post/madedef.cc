#include "../program/madecomm.hh"
#include "../program/sillystr.hh"
#include "../program/sllconst.h"

std::string mmadecomm::mdefcomm() const{
    return gCommDef1;
}

std::string mmadecomm::mdefdesc() const{
    return "language in which I am made";
}

void mmadecomm::mdefExecComm(const dpp::slashcommand_t& iDataEvent){
    std::string iEmbedCommd = std::to_string(iDataEvent.command.channel_id);
    iDataEvent.reply(
        dpp::message(iEmbedCommd, dpp::embed().set_color(fSSLCOLOR4).set_title(gCommRes1))
    );
}