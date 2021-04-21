//
// Created by sebas on 4/20/2021.
//

#include "Chitara.h"

int Chitara::deconecteaza() {
    if(conectabil == 1) {
        std::cout << "deconectat de la amplificator" << std::endl;
    }
    else {
        std::cout << "Nu se poate deconecta, ca nu ai unde sa-l conectezi" << std::endl;
    }
    return 0;
}

int Chitara::conecteazaLaAmplificator(std::string numeAmp) {
    if(conectabil == 1) {
        std::cout << "Conectat la amplificatorul " << numeAmp << std::endl;
        return 1;
    }
    else {
        std::cout << "Nu se poate conecta la un amplificator" << std::endl;
        return 0;
    }
}

std::ostream &operator<<(std::ostream &os, const Chitara &chitara) {
    os << static_cast<const Instrument &>(chitara) << " nr_corzi: " << chitara.nr_corzi << " tip: " << chitara.tip
       << " conectabil: " << chitara.conectabil;
    return os;
}

void Chitara::afisare(std::ostream &os) const {
    Instrument::afisare(os);
    os << nr_corzi << " tip: " << tip << " conectabil: " << conectabil;
}

Chitara::Chitara() {
    nr_corzi = 0;
    tip = "";
    conectabil = 0;
}

Chitara::Chitara(const std::string &categorie, const std::string &nume, const std::string &material,
                 const std::string &culoare, bool acordat, const Dimensiuni &dimensiune, short nrCorzi,
                 const std::string &tip, bool conectabil) : Instrument(categorie, nume, material, culoare, acordat,
                                                                       dimensiune), nr_corzi(nrCorzi), tip(tip),
                                                            conectabil(conectabil) {}
