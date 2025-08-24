#include <cstdlib>
#include "../program/sillystr.hh"

char* crhsllTock1 = std::getenv("SILLTOCKEN");
char* crhsllTock2 = std::getenv("WHTRTOCKEN");

std::string gSillyTock =    crhsllTock1 ? crhsllTock1 : "";
std::string fwheatherapik = crhsllTock2 ? crhsllTock2 : "";

std::string gCommDef1 = "made";
std::string gCommDef2 = "wheather";
std::string gCommRes1 = "I am programmed with c++";


std::string gCommErr = "error! command not found...";