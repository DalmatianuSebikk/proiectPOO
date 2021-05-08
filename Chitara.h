//
// Created by sebas on 4/20/2021.
//

#ifndef PROIECTPOO_CHITARA_H
#define PROIECTPOO_CHITARA_H

#include <iostream>
#include "Instrument.h"
#include <cstring>

//class Instrument;
class Chitara: public Instrument {
private:
    short nr_corzi;
    std::string tip;
    bool conectabil;
public:

    Chitara(const std::string &categorie, const std::string &nume, const std::string &material,
            const std::string &culoare, bool acordat, const Dimensiuni &dimensiune, short nrCorzi,
            const std::string &tip, bool conectabil);

    Chitara();

    friend std::ostream &operator<<(std::ostream &os, const Chitara &chitara);

    int conecteazaLaAmplificator(std::string numeAmp);

    int deconecteaza();

    void afisare(std::ostream &os) const override;
};



#endif //PROIECTPOO_CHITARA_H
