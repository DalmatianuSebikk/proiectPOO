//
// Created by sebas on 4/20/2021.
//

#ifndef PROIECTPOO_CANTARET_H
#define PROIECTPOO_CANTARET_H


#include <ostream>
#include <memory>
#include <vector>
#include "Instrument.h"
class Cantaret {
private:
    std::string nume;
    std::vector<std::string> canteceCunoscute;
    std::vector<std::unique_ptr<Instrument>> instrumente;
public:
//    void adauga_instrument(std::vector<Instrument> &instrumente);
    const std::vector<std::unique_ptr<Instrument>> &getInstrumente() const;

    void afiseaza_instrumente(std::vector<Instrument> &instrumente);

    void produ_nota(std::vector<Instrument> &instrumente, int i);

    void acordeaza(std::vector<Instrument> &instrumente, int i);

    void vopseste(std::vector<Instrument> &instrumente, int i, std::string culoare);

    void canta(std::vector<Instrument> &instrumente, int i, std::string cantecel);

    void setNume(const std::string &nume);

    void setCanteceCunoscute(const std::vector<std::string> &canteceCunoscute);

    const std::string &getNume() const;

    const std::vector<std::string> &getCanteceCunoscute() const;

    Cantaret();

    Cantaret(const std::string &nume, std::vector<std::string> &canteceCunoscute);

    friend std::ostream &operator<<(std::ostream &os, const Cantaret &cantaret);

    void adauga_instrument(std::string tip);

};


#endif //PROIECTPOO_CANTARET_H
