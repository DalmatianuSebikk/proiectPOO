//
// Created by sebas on 3/18/2021.
//

#ifndef PROIECTPOO_INSTRUMENT_H
#define PROIECTPOO_INSTRUMENT_H

#include <string>
#include <iostream>
//#include "Chitara.h"
//#include "Percutie.h"

class Dimensiuni{
    int lungime;
    int latime;

public:
    Dimensiuni();

    friend std::ostream &operator<<(std::ostream &os, const Dimensiuni &dimensiuni);
    friend std::istream &operator>>(std::istream &is, Dimensiuni &dimensiuni);
    Dimensiuni(const Dimensiuni &dimensiune); // de copiere
    Dimensiuni(int lungime, int latime); // de initializare
    ~Dimensiuni();

    void setLungime(int lungime);

    void setLatime(int latime);
};
class Instrument {
private:
    std::string categorie;
    std::string nume;
    std::string material;
    std::string culoare;
    bool acordat;
    Dimensiuni dimensiune;

public:

    Instrument(const std::string &categorie, const std::string &nume, const std::string &material,
               const std::string &culoare, bool acordat, const Dimensiuni &dimensiune);

    friend std::istream &operator>>(std::istream &is, Instrument &instrument);
    friend std::ostream &operator<<(std::ostream &os, const Instrument &instrument);

    bool isAcordat() const;

    const std::string &getCategorie() const;

    const std::string &getCuloare() const;

    virtual ~Instrument();

    virtual void acordeaza(){
        acordat = true;
        std::cout << "S-a acordat instrumentul!"<<std::endl;
    }
    virtual void vopseste(std::string culoareNoua){
        culoare = culoareNoua;
        std::cout<<"Instrument vopsit!"<<std::endl;
    }
    virtual void produNota(std::string nota){
        std::cout << "Cant nota:" << nota;
    }
    virtual void playSong(std::string song){
        std::cout << "Cant melodia:" << song << std::endl;
    }

    Instrument();

    void setAcordat(bool acordat);

    virtual void afisare(std::ostream &os) const;
};

// aplic factory design pattern : Instrumente cu f multe atribute, nu ne int sa le setam pe fiecare in parte.
// dorim sa obtinem o instanta a obiectului "repede", fara sa ne preocupe ce contine.
// in factory vreau ceva basic, nu foarte customizabil, deci daca pun parametri la functie, eventual sa fie cat mai putini

//class Instrument_factory {
//public:
//    static Instrument pianDigital(const std::string& nume = "Novation", std::string& culoare ="gri") {
//        return Instrument("piane", nume, "plastic/metal", culoare, true, Dimensiuni{78, 77});
//    }; // poti sa-l consideri orga
//    static Instrument pianOrganic(std::string& nume = "Yamaha", std::string& culoare ="lemn de nuc") {
//        return Instrument("piane", nume, "lemn/metal", culoare, true, Dimensiuni{149, 61});
//    }; // pianul normal
//    static Chitara chitaraDigitala(std::string& nume = "Traveler", std::string& culoare = "gri") {
//        return Chitara("chitare", nume, "plastic/metal", culoare, true, Dimensiuni{78, 55}, 6, "electrica/digitala", true);
//    }; // chiar exista asa ceva
//    static Chitara chitaraOrganica(std::string& nume = "Cort", std::string& culoare = "lemn") {
//        return Chitara("chitare", nume, "lemn", culoare, true, Dimensiuni{78, 55}, 6, "acustica/clasica", false);
//    }; // chitara normala
//    static Percutie tobeDigitale(std::string& nume = "Novation",std::string& culoare = "gri") {
//        return Percutie("percutie", nume, "plastic/metal", culoare, true, Dimensiuni{200, 150}, 64); // nrTobe in cazul asta inseamna cate pad-uri am
//    }; // un launchPad de exemplu
//    static Instrument tobeOrganice(std::string& nume = "Novation",std::string& culoare = "gri") {
//        return Percutie("percutie", nume, "lemn/metal", culoare, true, Dimensiuni{200, 150}, 10);
//    }; // tobe reale
//};
#endif //PROIECTPOO_INSTRUMENT_H
