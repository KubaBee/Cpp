//
// Created by 1kuba on 16.11.2020.
//

#ifndef PSZCZOLAJAKUB_ETAP1_MACHINE_H
#define PSZCZOLAJAKUB_ETAP1_MACHINE_H
#include <iostream>
#include <exception>
#include <unistd.h>
#include "Payment.h"
#include "Choices.h"
#include <string>
#include "Type.h"

struct fofail : std::exception {
};
struct emptyfail : std::exception {
};

class Tdrinks;
class Tmachine{
private:
    //int _amount[4]{3, 3, 3, 3};
public:
    bool wbfile=true;
    int _topay{};
    void print(Tdrinks &p);
    bool check(bool) const;
    void choice(Tdrinks &p);
    bool oneless(Tdrinks &p);
    void choice2( const char*  file , std::vector<Tchoices>&) ;
};


class Tdrinks
{
protected:
    /*const*/ std::string _name{};
   /* const*/ int _ind{};
public:
    int _amount[1]{3};
    int _price{};
    /*explicit Tdrinks(std::string na, int pr, int index, int volume) : _name(std::move(na)), _price(pr), _ind(index){}*/
    friend class Tmachine;
    friend std::ostream& operator<<(std::ostream& os, Tdrinks &p);
};

class Tcan : public Tdrinks{
public:
    int price_diff;
    void changeval();
    Tcan(std::string na, int pr, int index, int pd) /*: Tdrinks(_name(std::move(na)), _price(pr), _ind(index), price_diff(pd))*/{
        _name=na;
        _price=pr;
        _ind=index;
        price_diff=pd;
    }
};

class Tbottle : public Tdrinks{
public:
    Tbottle(std::string na, int pr, int index) /*: _name(std::move(na)), _price(pr), _ind(index)*/{
        _name = na;
        _price = pr;
        _ind = index;
    }
};

#endif //PROJEKT1_MACHINE_H
