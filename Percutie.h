//
// Created by sebas on 4/20/2021.
//

#ifndef PROIECTPOO_PERCUTIE_H
#define PROIECTPOO_PERCUTIE_H
#include "Instrument.h"
#include <iostream>
#include <cstring>

class Percutie:public Instrument {
private:
    int nr_tobe;
public:
    Percutie(const std::string &categorie, const std::string &nume, const std::string &material,
             const std::string &culoare, bool acordat, const Dimensiuni &dimensiune, int nrTobe);

    Percutie();

    int getNrTobe() const;

    void setNrTobe(int nrTobe);

    void schimbaRitmul(std::string ritm) {
        std::cout << "Ritmul a fost schimbat in " << ritm << std::endl;
    }

    void schimbaTempo(int tempo) {
        std::cout << "Tempo-ul a fost schimbat la " << tempo << " BPM" << std::endl;
    }
};


#endif //PROIECTPOO_PERCUTIE_H
