#include <cstdlib>
#include "../program/sillystr.hh"

std::string gGetEnvFunc(const char* gvar){
    char* crhsllTock = std::getenv(gvar);
    return crhsllTock ? crhsllTock : "";
}

std::string gSillyTock =    gGetEnvFunc("SILLTOCKEN");
std::string fwheatherapik = gGetEnvFunc("WHTRTOCKEN");

std::string gCommDef1 = "made";
std::string gCommDef2 = "wheather";
std::string gCommRes1 = "I am programmed with c++";
std::string gCommRes2 = "Get the current wheather of a city";
std::string gCommDef3 = "dado";
std::string gCommRes3 = "Get a random Dado response";


std::string gCommErr = "error! command not found...";