/*
Project 1.
Created by Jakub Pszczola.
*/

#include "Machine.h"
#include "Payment.h"
#include "Choices.h"
#include "Type.h"
#include <iostream>
#include<unistd.h>
#include <vector>
using namespace std;

int main(int count, char* argv[]){
    
    int ch{};
    int ch2{};
    int chn{};
    bool tof{};

    Tmachine mach;

    cout << "\nVending machine accept only following coins(type this): 10gr(10), 20gr(20), 50gr(50), 1zl(1), 2zl(2), 5zl(5).\n\n";
    sleep(1);


    Tcan Pepsi("Pepsi",370,5,80);
    Tcan Sprite("Sprite",200,6,20);
    Tcan Nestea("Nestea",610,7,250);
    Tcan Water("Water",1000,8,300);
    //vector <Tcan> schwcan{Pepsi, Sprite, Nestea, Water};       //przypisanie obietków do wektora

    Tbottle Pepsi2("Pepsi",370,1);
    Tbottle Sprite2("Sprite",200,2);
    Tbottle Nestea2("Nestea",610,3);
    Tbottle Water2("Water",1000,4);
    //vector<Tbottle>schwpbottle{Pepsi2, Sprite2, Nestea2, Water2};

    shelf<Tcan> shwcan(330);                                          //tworzenie szablonu klasy dla półki z puszkami
    shelf<Tbottle> shwpbottle(500);                                      // tworzenie szablonu klasy dla półki z butelkami plastikowymi

    shwcan.putonshel(Pepsi);
    shwcan.putonshel(Sprite);
    shwcan.putonshel(Nestea);
    shwcan.putonshel(Water);

    for(auto &onshel:shwcan.onshelf){
        onshel.changeval();
    }

    shwpbottle.putonshel(Pepsi2);
    shwpbottle.putonshel(Sprite2);
    shwpbottle.putonshel(Nestea2);
    shwpbottle.putonshel(Water2);

    //std::vector<shared_ptr<Tdrinks>> cansandbottles{};


    Tchoices Dr{};
    Tchoices Cob{};
    Tchoices Pmnt{};
    Tchoices Othr{};
    vector<Tchoices> lochoices{Dr,Cob,Pmnt,Othr};


    vector<Tpayment*> objects;
    objects.push_back(new Tcash);                                   //wpisywanie obiektów do wektora innym sposobem
    objects.push_back(new Tblik);
    objects.push_back(new Tcard);


    try {
        mach.choice2(argv[1], lochoices);
    }
    catch(fofail &noexist){
        cerr<<"Error: cannot open this file (probably doesn't exist)\n";
        mach.wbfile=false;

    }
    catch (const std::exception &empty_file) {
        cerr<<"Error: file is empty\n";
        mach.wbfile=false;

    }
    catch(...){
        cerr<<"Error: unknown exception";
        throw;
    }



    do {                                                                                                                 //petla obslugujaca menu wyboru trwajaca dopoki nie zostanie wybrane zero
        cout << "Choose your drink from the list or press 5 to exit:\n\n";
        for (auto & listofdrink : shwpbottle.onshelf) {
            mach.print(listofdrink);                                                                                 //wypisywanie listy napojów
        }
        ch=lochoices[0].rtrnch(mach.wbfile);
        if ((ch == 1) || (ch == 2) || (ch == 3) || (ch == 4)) {                                                          //wybor napoju i przypisanie ceny napoju pomnożonej przez 100 do wymaganje kwoty zaplaty
            cout<<"Do you want your drink in:\n1.Plastic bottle (vol) "<<shwpbottle.vol<<", that costs: "<<float(shwpbottle.onshelf[ch-1]._price)/100<<" avaiavle in amount: "<<*shwpbottle.onshelf[ch-1]._amount<<endl
            <<"2.Can (vol) "<<shwcan.vol<<", that costs: "<<static_cast<float>(shwcan.onshelf[ch-1]._price)/100<<" avaiavle in amount: "<<*shwcan.onshelf[ch-1]._amount<<endl;


            chn=lochoices[1].rtrnch(mach.wbfile);
            if(chn==1) {
                mach.choice(shwpbottle.onshelf[ch - 1]);
                tof=mach.oneless(shwpbottle.onshelf[ch - 1]);
            }
            else if(chn==2){
                mach.choice(shwcan.onshelf[ch - 1]);
                tof=mach.oneless(shwcan.onshelf[ch - 1]);
            }
            else{
                cerr<<"Error: There isn't such option, try again\n\n";
            }

            if (tof) {                                                                 //sprawdzanie czy napój jest jeszcze dostępny

                cout<<"Payment method\n\n1.Cash\n2.Blik\n3.Card\n";

                ch2=lochoices[2].rtrnch(mach.wbfile);

                if(ch2 >= 1 && ch2 <= objects.size()){

                    while (!mach.check(objects[ch2-1]->pay(lochoices[3], mach)))                       //petla sprawdzajaca czy oczekiwana kwota zaostala zaplacona
                        ;
                    }
                else
                    cerr<<"  Error: there is no such option, please choose the right one.\n\n";
            }
        }

        else if (ch == 5)
            ;                                        //wylapanie 5 i wyjscie z petli
        else {
            cerr << "  Error: there is no such option, please choose the right one.\n\n";
            sleep(1);
        }
        if(mach.wbfile) {
            //lochoices[2].isfile = false;
            mach.wbfile = false;
        }

    }while (ch != 5);

    cout << "Looking forward to see you again.";

return 0;
}


