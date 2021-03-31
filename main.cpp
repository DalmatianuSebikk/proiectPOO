#include <iostream>
#include "instrument.h"
#include <string>
#include <vector>

void adauga_instrument(std::vector<Instrument> &instrumente){
    Instrument instrument;
    int lungime, latime;
    std::string categorie, nume, material, culoare;
    bool acordat;
    Dimensiuni dimensiune;
    std::cout << "categorie:" << std::endl;
    std::cin >> categorie;
    std::cout << "nume:" << std::endl;
    std::cin >> nume;
    std::cout << "material:" << std::endl;
    std::cin >> material;
    std::cout << "culoare:" << std::endl;
    std::cin >> culoare;

    std::cout << "Dimensiuni:" << std::endl;
    std::cout << "lungime:" << std::endl;
    std::cin >> lungime;
    std::cout << "latime:" << std::endl;
    std::cin >> latime;
    dimensiune.setLungime(lungime);
    dimensiune.setLatime(latime);
    instrument = Instrument(categorie, nume, material, culoare, acordat, dimensiune);
    instrumente.push_back(instrument);
}

void afiseaza_instrumente(std::vector<Instrument> &instrumente){
    std::cout << "----------------INSTRUMENTE----------------"<<std::endl;
    for(int i = 0; i < instrumente.size(); ++i){
        std::cout << "INSTRUMENTUL 1:";
        std::cout << instrumente[i] << std::endl;
    }
}

void produ_nota(std::vector<Instrument> &instrumente, int i){
    std::cout << "Alege cu ce instrument vrei sa canti" << std::endl;
    std::cin >> i;
    if(i > instrumente.size()){
        std::cout << "Nu am instrumentul asta." << std::endl;
        return;
    }
    instrumente[i].produNota("LA");
}

void acordeaza(std::vector<Instrument> &instrumente, int i){
    std::cout << "Alege ce instrument vrei sa acordezi" << std::endl;
    std::cin >> i;
    instrumente[i].acordeaza();
}

void vopseste(std::vector<Instrument> &instrumente, int i, std::string culoare){
    afiseaza_instrumente(instrumente);
    std::cout << "Alege ce instrument vrei sa vopsesti" << std::endl;
    std::cin >> i;
    std::cout << "Alege si culoarea" << std::endl;
    std::cin >> culoare;
    instrumente[i].vopseste("negru");
}

void canta(std::vector<Instrument> &instrumente, int i, std::string cantecel){
    afiseaza_instrumente(instrumente);
    std::cout << "Alege cu ce instrument vrei sa canti" << std::endl;
    std::cin >> i;
    std::cout << "Alege si cantecul" << std::endl;
    std::cin >> cantecel;
    instrumente[i].playSong(cantecel);
}

int main() {

    //------------MENIU -------------
    char s;
    int lungime, latime;
    int i;
    Instrument instrument;
    std::vector<Instrument> instrumente;
    std::string culoare, cantecel;


    do{
        std::cout << "------------MENIU -------------" << std::endl;
        std::cout << "1. Citeste instrument muzical" << std::endl;
        std::cout << "2. Afiseaza instrumentele muzicale" << std::endl;
        std::cout << "3. Canta o melodie" << std::endl;
        std::cout << "4. Acordeaza" << std::endl;
        std::cout << "5. Vopseste-o" << std::endl;
        std::cout << "6. Canta o melodie" << std::endl;
        std::cout << "0. Iesire" << std::endl;
        std::cin >> s;
        switch(s){
            case '0':
                std::cout << "paaa"<<std::endl;
                break;
            case '1':
                adauga_instrument(instrumente);
                break;
            case '2':
                afiseaza_instrumente(instrumente);
                break;
            case '3':
                produ_nota(instrumente, i);
                break;
            case '4':
                acordeaza(instrumente, i);
                break;
            case '5':
                vopseste(instrumente, i, culoare);
                break;
            case '6':
                canta(instrumente, i, cantecel);
                break;
        }
    }while(s != '0');
    return 0;
}
