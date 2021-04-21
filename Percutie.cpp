//
// Created by sebas on 4/20/2021.
//

#include "Percutie.h"

Percutie::Percutie(const std::string &categorie, const std::string &nume, const std::string &material,
                   const std::string &culoare, bool acordat, const Dimensiuni &dimensiune, int nrTobe) : Instrument(
        categorie, nume, material, culoare, acordat, dimensiune), nr_tobe(nrTobe) {}

Percutie::Percutie() {
    nr_tobe = 0;
}

int Percutie::getNrTobe() const {
    return nr_tobe;
}

void Percutie::setNrTobe(int nrTobe) {
    nr_tobe = nrTobe;
}
