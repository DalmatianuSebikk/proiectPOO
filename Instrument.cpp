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
    std::cout << "Dimensiuni:" << std::endl;
    std::cout << "lungime:" << std::endl;
    is >> dimensiuni.lungime;
    std::cout << "latime:" << std::endl;
    is >> dimensiuni.latime;
    return is;
}
std::istream &operator>>(std::istream &is, Instrument &instrument){
    std::cout << "categorie:" << std::endl;
    is >> instrument.categorie;
    std::cout << "nume:" << std::endl;
    is >> instrument.nume;
    std::cout << "material:" << std::endl;
    is >> instrument.material;
    std::cout << "culoare:" << std::endl;
    is >> instrument.culoare;
    std::cout << "acordat:" << std::endl;
    is >> instrument.acordat;
    is >> instrument.dimensiune;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Instrument &instrument) {
    instrument.afisare(os);
    return os;
}

void Instrument::afisare(std::ostream &os) const {
    os << "categorie: " << categorie << " nume: " << nume << " material: " << material
       << " culoare: " << culoare << " acordat: " << acordat << " dimensiune: "
       << dimensiune;
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

bool Instrument::isAcordat() const {
    return acordat;
}


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

void Instrument::setAcordat(bool acordat) {
    Instrument::acordat = acordat;
}

void Dimensiuni::setLatime(int latime) {
    Dimensiuni::latime = latime;
}

Dimensiuni::Dimensiuni() {}
