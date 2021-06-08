//
// Created by kuba on 04.01.2021.
//

#ifndef PSZCZOLAJAKUB_ETAP2_TYPE_H
#define PSZCZOLAJAKUB_ETAP2_TYPE_H
#include <iostream>
#include <vector>
#include "Machine.h"


template<typename T>                                                                                    //szablon klasy
class shelf{
public:
    int vol{};
    std::vector<T>onshelf;
    void putonshel(T &p);
    explicit shelf(int vv);
    //T giveback(int);
};

template<typename T>
void shelf<T>::putonshel(T &p) {
    onshelf.push_back(p);
}

template<typename T>
shelf<T>::shelf(int vv): vol(vv) {}                                             //konstruktor szablonu

//template<typename T>
//T shelf<T>::giveback(int i) {
//    return onshelf[i-1];
//}

#endif //PSZCZOLAJAKUB_ETAP2_TYPE_H
