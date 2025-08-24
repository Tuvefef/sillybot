#ifndef MAINCOMMHH
#define MAINCOMMHH

#include <dpp/dpp.h>
#include <string>

class mmaincomm{
    public:
        virtual ~mmaincomm() = default;
        virtual std::string mdefcomm() const = 0;
        virtual std::string mdefdesc() const = 0;
        virtual void mdefExecComm(const dpp::slashcommand_t& iDataEvent) = 0;
};

#endif