//
// Created by 1kuba on 16.11.2020.
//

#include "Machine.h"
#include <iostream>
using namespace std;


void Tmachine::choice2(const char* file, vector<Tchoices>&loch) {                                           //otwieranie pliku i zapisywanie danych do  niego
    ifstream data;
    data.open(file);
    if(data.is_open()) {
        if(data.peek()!= EOF) {
            for (auto &loc : loch) {
                data >> loc.ch;
            }
            data.close();
        }
        else{
            const emptyfail empty_file;
            throw empty_file;                                                       //rzucenie wyjátku pustego pliku
        }
    }
    else {
        const fofail noexist;
        throw noexist;                                                              //rzucenie wyjátku nieistniejácego pliku
        }
}

void Tmachine::choice(Tdrinks &p) {
    cout << "\nYou chose " << p._name << " pay " << float(p._price)/100 << " zl.\n\n";
    _topay = p._price;
}



ostream & operator<<(ostream& os, Tdrinks& p) {
    os << "Press " << p._ind << " to choose " << p._name <<endl;
    return os;
}

void Tmachine::print(Tdrinks &p) {
    //cout << "Press " << p._ind << " to choose " << p._name << ", available in an amount of " << p._amount[p._ind - 1] << " and costs " << p._price << "." << endl;
    operator<<(cout, p);
}

bool Tmachine::oneless(Tdrinks& p) {
    if (p._amount[0] != 0) {                                  //zmniejszenie ilosci w prywatnej tablicy
        -- p._amount[0];
        return true;
    }
    else {
            cerr << "\n\n  Error: we are out of this drink, please choose a different one.\n\n";
            return false;
    }
}


bool Tmachine::check(bool varcheck) const {
    if(varcheck == 1) {                                       //sprawdzenie czy kwota zostala zaplacona
        cout << "\n\nAll has been paid.\nThe machine dispenses the drink, please wait.\n";
        sleep(2);
        cout << "Enjoy.\n\n";
        sleep(1);
        return true;
    }
    else {
        cout << endl << "Left to pay:" << float(_topay)/100 << "zl" << endl;
        return false;
    }
}

void Tcan::changeval() {
    _price=_price-price_diff;
}