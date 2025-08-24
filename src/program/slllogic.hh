#ifndef SLLLOGICHH
#define SLLLOGICHH

#include <dpp/dpp.h>
#include <vector>
#include <memory>
#include "maincomm.hh"

class ssslllogic{
    public:
        void minitlogic(dpp::cluster& bot);
    private:
        std::vector<std::unique_ptr<mmaincomm>> mvcomm;
};

#endif //defined(_MSC_VER) && (_MSC_VER >= 1020)