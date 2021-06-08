//
// Created by 1kuba on 08.12.2020.
//

#ifndef PSZCZOLAJAKUB_ETAP1_PAYMENT_H
#define PSZCZOLAJAKUB_ETAP1_PAYMENT_H
#include "Machine.h"
#include "Choices.h"
class Tmachine;
class Tpayment {
public:
    virtual bool pay(Tchoices &p, Tmachine &r)=0;
};

class Tblik : public Tpayment{
public:
    bool pay(Tchoices &p, Tmachine &r) override;
};

class Tcash : public Tpayment{
public:
    bool pay(Tchoices &p, Tmachine &r) override;
};

class Tcard : public Tpayment{
public:
    bool pay(Tchoices &p, Tmachine &r) override;
};

#endif //PSZCZOLAJAKUB_ETAP1_PAYMENT_H
