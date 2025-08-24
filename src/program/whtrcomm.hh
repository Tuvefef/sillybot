#ifndef WHTRCOMMHH
#define WHTRCOMMHH
#include "maincomm.hh"

class mwhtrcomm : public mmaincomm{
    public:
        std::string mdefcomm() const override;
        std::string  mdefdesc() const override;
        void mdefExecComm(const dpp::slashcommand_t& iDataEvent) override;
};

#endif