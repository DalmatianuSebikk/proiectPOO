//
// Created by sebas on 4/20/2021.
//

#include <utility>
#include <vector>
#include <algorithm>
#include "Cantaret.h"
#include "Instrument.h"
#include "Chitara.h"
#include "Percutie.h"
using namespace std::string_literals;


void Cantaret::adauga_instrument(std::string tip) {
    std::unique_ptr<Instrument> instrument;

    if(tip == "Chitara"){
        Chitara chitara("Acustica"s, "albastrica"s, "mahon"s, "verde"s, true, {205, 50}, 6, "pt copii"s, false);
        instrument = std::make_unique<Chitara>(chitara);
    }
    else if (tip == "Percutie"){
        instrument = std::make_unique<Percutie>();
    }
    instrumente.emplace_back(std::move(instrument));
}

void Cantaret::afiseaza_instrumente() {
    std::cout << "----------------INSTRUMENTE----------------"<<std::endl;
    for(int i = 0; i < instrumente.size(); ++i){
        std::cout << "INSTRUMENTUL 1:";
        std::cout << *instrumente[i] << std::endl;
    }
}

void Cantaret::produ_nota(int i) {
    std::cout << "Alege cu ce instrument vrei sa canti" << std::endl;
    std::cin >> i;
    if(i > instrumente.size()){
        std::cout << "Nu am instrumentul asta." << std::endl;
        return;
    }
    instrumente[i]->produNota("LA");
}

void Cantaret::acordeaza(int i) {
    std::cout << "Alege ce instrument vrei sa acordezi" << std::endl;
    std::cin >> i;
    if(i > instrumente.size()){
        std::cout << "Nu am instrumentul asta." << std::endl;
        return;
    }
    instrumente[i]->acordeaza();
}

void Cantaret::vopseste(int i, std::string culoare) {
    afiseaza_instrumente();
    std::cout << "Alege ce instrument vrei sa vopsesti" << std::endl;
    std::cin >> i;
    std::cout << "Alege si culoarea" << std::endl;
    std::cin >> culoare;
    if(i > instrumente.size()){
        std::cout << "Nu am instrumentul asta." << std::endl;
        return;
    }
    instrumente[i]->vopseste("negru");
}

void Cantaret::canta(int i, std::string cantecel) {
    afiseaza_instrumente();
    std::cout << "Cantaretul va canta cu instrumentul " <<  i << std::endl;
    std::cout << "Alegem si cantecul" << cantecel << std::endl;
    instrumente.at(i)->playSong(cantecel);
    auto caut = std::find(std::begin(canteceCunoscute), std::end(canteceCunoscute), cantecel);
    if (caut != canteceCunoscute.end()){
        std::cout << "cantecul exista"<<std::endl;
    }
}

const std::string &Cantaret::getNume() const {
    if(nume == "N/A")
        throw std::invalid_argument("Nu stim numele cantaretului. Pune-i un nume, te rog.");
    return nume;
}

const std::vector<std::string> &Cantaret::getCanteceCunoscute() const {
    if(canteceCunoscute.empty())
        throw std::length_error("Nu stie nici un cantec? Adauga un cantec.");
    return canteceCunoscute;
}

void Cantaret::setNume(const std::string &nume) {
    Cantaret::nume = nume;
}

void Cantaret::setCanteceCunoscute(const std::vector<std::string> &canteceCunoscute) {
    Cantaret::canteceCunoscute = canteceCunoscute;
}

Cantaret::Cantaret(std::string nume, std::vector<std::string> &canteceCunoscute) : nume(std::move(nume)),
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
    if(instrumente.empty()){
        throw std::length_error("Nu stie sa cante la nici un instrument? Adauga un instrument.");
    }
    return instrumente;
}

