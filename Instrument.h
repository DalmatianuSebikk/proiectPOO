//
// Created by sebas on 3/18/2021.
//

#ifndef PROIECTPOO_INSTRUMENT_H
#define PROIECTPOO_INSTRUMENT_H

#include <string>
#include <iostream>
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

    const std::string &getCategorie() const;

    const std::string &getCuloare() const;

    ~Instrument();

    void acordeaza(){
        acordat = true;
        std::cout << "S-a acordat instrumentul!"<<std::endl;
    }
    void vopseste(std::string culoareNoua){
        culoare = culoareNoua;
        std::cout<<"Instrument vopsit!"<<std::endl;
    }
    void produNota(std::string nota){
        std::cout << "Cant nota:" << nota;
    }
    void playSong(std::string song){
        std::cout << "Cant melodia:" << song << std::endl;
    }

    Instrument();
};



#endif //PROIECTPOO_INSTRUMENT_H
