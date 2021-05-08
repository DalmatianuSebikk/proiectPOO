//
// Created by sebas on 5/8/2021.
//

#ifndef PROIECTPOO_FACTORY_H
#define PROIECTPOO_FACTORY_H


// aplic factory design pattern : Instrumente cu f multe atribute, nu ne int sa le setam pe fiecare in parte.
// dorim sa obtinem o instanta a obiectului "repede", fara sa ne preocupe ce contine.
// in factory vreau ceva basic, nu foarte customizabil, deci daca pun parametri la functie, eventual sa fie cat mai putini

#include "Instrument.h"
#include "Chitara.h"
#include "Percutie.h"

class Instrument_factory {
public:
    static Instrument pianDigital(const std::string& nume = (std::string &) "Novation", std::string& culoare = (std::string &) "gri") {
        return Instrument("piane", nume, "plastic/metal", culoare, true, Dimensiuni{78, 77});
    }; // poti sa-l consideri orga
    static Instrument pianOrganic(std::string& nume = (std::string &) "Yamaha", std::string& culoare = (std::string &) "lemn de nuc") {
        return Instrument("piane", nume, "lemn/metal", culoare, true, Dimensiuni{149, 61});
    }; // pianul normal
    static Chitara chitaraDigitala(std::string& nume =  (std::string &) "Traveler", std::string& culoare = (std::string &) "gri") {
        return Chitara("chitare", nume, "plastic/metal", culoare, true, Dimensiuni{78, 55}, 6, "electrica/digitala", true);
    }; // chiar exista asa ceva
    static Chitara chitaraOrganica(std::string& nume = (std::string &) "Cort", std::string& culoare = (std::string &) "lemn") {
        return Chitara("chitare", nume, "lemn", culoare, true, Dimensiuni{78, 55}, 6, "acustica/clasica", false);
    }; // chitara normala
    static Percutie tobeDigitale(std::string& nume = (std::string &) "Novation",std::string& culoare = (std::string &) "gri") {
        return Percutie("percutie", nume, "plastic/metal", culoare, true, Dimensiuni{200, 150}, 64); // nrTobe in cazul asta inseamna cate pad-uri am
    }; // un launchPad de exemplu
    static Instrument tobeOrganice(std::string& nume = (std::string &) "Novation",std::string& culoare = (std::string &) "gri") {
        return Percutie("percutie", nume, "lemn/metal", culoare, true, Dimensiuni{200, 150}, 10);
    }; // tobe reale
};


#endif //PROIECTPOO_FACTORY_H
