#include <random>
#include "../program/ddcomm.hh"
#include "../program/sillystr.hh"

std::string mddcomm::mdefcomm() const{
    return gCommDef3;
}

std::string mddcomm::mdefdesc() const{
    return gCommRes3;
}

void mddcomm::mdefExecComm(const dpp::slashcommand_t& iDataEvent){
    std::string iDataCommd = iDataEvent.command.get_command_name();
    if(iDataCommd == gCommDef3){
        std::random_device gsrand;
        std::mt19937 ggen(gsrand());
        std::uniform_int_distribution<> distr(1, 6);
        int rndnum = distr(ggen);
        iDataEvent.reply("result: " + std::to_string(rndnum));
    }
}