#include <cstdlib>
#include "program/sillystr.h"

char* crhsllTock = std::getenv("SILLTOCKEN");

std::string gSillyTock = crhsllTock ? crhsllTock : "";

std::string gCommDef1 = "made";
std::string gCommRes1 = "I am programmed with c++";

std::string gCommErr = "error! command not found...";