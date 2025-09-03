#ifndef DADOCOMMHH
#define DADOCOMMHH
#include "maincomm.hh"

class mddcomm : public mmaincomm{
    public:
        std::string mdefcomm() const override;
        std::string mdefdesc() const override;
        void mdefExecComm(const dpp::slashcommand_t& iDataEvent) override;
};

#endif