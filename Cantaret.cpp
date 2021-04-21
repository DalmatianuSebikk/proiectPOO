//
// Created by sebas on 4/20/2021.
//

#include <vector>
#include "Cantaret.h"
#include "Instrument.h"
#include "Chitara.h"
#include "Percutie.h"


void Cantaret::adauga_instrument(std::string tip) {
    std::unique_ptr<Instrument> instrument;

    if(tip == "Chitara"){
        instrument = std::make_unique<Chitara>();
    }
    else if (tip == "Percutie"){
        instrument = std::make_unique<Percutie>();
    }
    instrumente.emplace_back(std::move(instrument));
}

void Cantaret::afiseaza_instrumente(std::vector<Instrument> &instrumente) {
    std::cout << "----------------INSTRUMENTE----------------"<<std::endl;
    for(int i = 0; i < instrumente.size(); ++i){
        std::cout << "INSTRUMENTUL 1:";
        std::cout << instrumente[i] << std::endl;
    }
}

void Cantaret::produ_nota(std::vector<Instrument> &instrumente, int i) {
    std::cout << "Alege cu ce instrument vrei sa canti" << std::endl;
    std::cin >> i;
    if(i > instrumente.size()){
        std::cout << "Nu am instrumentul asta." << std::endl;
        return;
    }
    instrumente[i].produNota("LA");
}

void Cantaret::acordeaza(std::vector<Instrument> &instrumente, int i) {
    std::cout << "Alege ce instrument vrei sa acordezi" << std::endl;
    std::cin >> i;
    if(i > instrumente.size()){
        std::cout << "Nu am instrumentul asta." << std::endl;
        return;
    }
    instrumente[i].acordeaza();
}

void Cantaret::vopseste(std::vector<Instrument> &instrumente, int i, std::string culoare) {
    afiseaza_instrumente(instrumente);
    std::cout << "Alege ce instrument vrei sa vopsesti" << std::endl;
    std::cin >> i;
    std::cout << "Alege si culoarea" << std::endl;
    std::cin >> culoare;
    if(i > instrumente.size()){
        std::cout << "Nu am instrumentul asta." << std::endl;
        return;
    }
    instrumente[i].vopseste("negru");
}

void Cantaret::canta(std::vector<Instrument> &instrumente, int i, std::string cantecel) {
    afiseaza_instrumente(instrumente);
    std::cout << "Alege cu ce instrument vrei sa canti" << std::endl;
    std::cin >> i;
    std::cout << "Alege si cantecul" << std::endl;
    std::cin >> cantecel;
    if(i > instrumente.size()){
        std::cout << "Nu am instrumentul asta." << std::endl;
        return;
    }
    instrumente[i].playSong(cantecel);
}

const std::string &Cantaret::getNume() const {
    return nume;
}

const std::vector<std::string> &Cantaret::getCanteceCunoscute() const {
    return canteceCunoscute;
}

void Cantaret::setNume(const std::string &nume) {
    Cantaret::nume = nume;
}

void Cantaret::setCanteceCunoscute(const std::vector<std::string> &canteceCunoscute) {
    Cantaret::canteceCunoscute = canteceCunoscute;
}

Cantaret::Cantaret(const std::string &nume, std::vector<std::string> &canteceCunoscute) : nume(nume),
                                                                                                canteceCunoscute(
                                                                                                        canteceCunoscute) {}

Cantaret::Cantaret() {
    nume = "N/A";
}

std::ostream &operator<<(std::ostream &os, const Cantaret &cantaret) {
    os << "nume: " << cantaret.nume << " canteceCunoscute: " << std::endl;
    for(auto& cantec: cantaret.canteceCunoscute) {
        os << cantec << " ";
    }
    for(auto& instrument: cantaret.instrumente) {
        os << *instrument << " ";
    }
    return os;
}

const std::vector<std::unique_ptr<Instrument>> &Cantaret::getInstrumente() const {
    return instrumente;
}

