//
// Created by sebas on 3/18/2021.
//

#include "Instrument.h"
#include <iostream>

const std::string &Instrument::getCategorie() const {
    return categorie;
}

const std::string &Instrument::getCuloare() const {
    return culoare;
}
std::istream &operator>>(std::istream &is, Dimensiuni &dimensiuni){
    is >> dimensiuni.lungime >> dimensiuni.latime;
}
std::istream &operator>>(std::istream &is, Instrument &instrument){
    is >> instrument.categorie >> instrument.nume >> instrument.material >> instrument.culoare >> instrument.acordat >> instrument.dimensiune;
}

std::ostream &operator<<(std::ostream &os, const Instrument &instrument) {
    os << "categorie: " << instrument.categorie << " nume: " << instrument.nume << " material: " << instrument.material
       << " culoare: " << instrument.culoare << " acordat: " << instrument.acordat << " dimensiune: "
       << instrument.dimensiune;
    return os;
}

Instrument::~Instrument() {
    categorie = "";
    nume = "";
    culoare = "";
    acordat = false;
    dimensiune.setLatime(0);
    dimensiune.setLungime(0);
}

Instrument::Instrument(const std::string &categorie, const std::string &nume, const std::string &material,
                       const std::string &culoare, bool acordat, const Dimensiuni &dimensiune) : categorie(categorie),
                                                                                                 nume(nume),
                                                                                                 material(material),
                                                                                                 culoare(culoare),
                                                                                                 acordat(acordat),
                                                                                                 dimensiune(
                                                                                                         dimensiune) {}

Instrument::Instrument() {}


Dimensiuni::Dimensiuni(int lungime, int latime) : lungime(lungime), latime(latime) {}

Dimensiuni::Dimensiuni(const Dimensiuni &dimensiune){
    std::cout <<"Copy constructor"<<std::endl;
    lungime = dimensiune.lungime;
    latime = dimensiune.latime;
}

std::ostream &operator<<(std::ostream &os, const Dimensiuni &dimensiuni) {
    os << "lungime: " << dimensiuni.lungime << " latime: " << dimensiuni.latime;
    return os;
}

Dimensiuni::~Dimensiuni() {
    lungime = 0;
    latime = 0;
}

void Dimensiuni::setLungime(int lungime) {
    Dimensiuni::lungime = lungime;
}

void Dimensiuni::setLatime(int latime) {
    Dimensiuni::latime = latime;
}

Dimensiuni::Dimensiuni() {}
