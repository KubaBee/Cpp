//
// Created by 1kuba on 08.12.2020.
//

#include <iostream>
#include "Machine.h"
#include <string>
#include <algorithm>

using namespace std;

bool is_number( string& s){                                                 //spr czy string jest wart ciágiem liczb
    return !s.empty() && find_if(s.begin(), s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();       // wyrażenie lambda
}

bool Tcard::pay(Tchoices &p, Tmachine &r) {
    cout<<"Chosen payment method: card"<<endl;
    string pin;
    cout << "Bring the card close to the terminal and press 0 or \nput inside and enter your card pin";
    cout << ", when it is done press enter: \n";
    pin=to_string(p.rtrnch(r.wbfile));

    if ((is_number(pin) && (stoi(pin) == 0)) || ((pin.size() == 4) && is_number(pin)))
        return true;
    else {
        cerr << "  Error: PIN code is incorrect\n";
        return false;
    }
}

bool Tcash::pay(Tchoices &p, Tmachine &r) {
    cout<<"Chosen payment method: cash"<<endl;
    int coin;
    int &varone=r._topay;
    if(varone==0){
        return true;
    }
    else {
        cout << "\nInsert a coin: ";
        coin=p.rtrnch(r.wbfile);

        if ((coin == 10) || (coin == 20) || (coin == 50)) {         //obsluga monet groszowych

            if (coin <= varone) {                                   //sprawdzenie czy moneta jest mniejsza niz cena
                varone -= coin;                                     //odejmowanie wprowadzonej kwoty
                return false;
            } else {
                cerr << "  Error: the coin is bigger than price od a drink.\n";
            }
        } else if ((coin == 1) || (coin == 2) || (coin == 5)) {       //obsluga monet

            if (coin * 100 <= varone) {                             //sprawdzenie czy moneta*100 jest mniejsza niz cena
                varone -= coin * 100;                               //odejmowanie wprowadzonej kwoty*100
                return false;
            } else {
                cerr << "  Error: the coin is bigger than price of a drink.\n";
            }
        } else {

            cerr << "  Error: there is no such a coin available.\n";
            return false;
        }
    }
    return false;
}

bool Tblik::pay(Tchoices &p, Tmachine &r) {
    string bcode;
    cout << "\nEnter 6-digit BLIK code: ";
    bcode=to_string(p.rtrnch(r.wbfile));

    if(bcode.size()==6 && is_number(bcode)) {
        return true;
    }
    else {
        cerr<<"\n  Error: BLIK code is incorrect\n";
        return false;
    }
}
