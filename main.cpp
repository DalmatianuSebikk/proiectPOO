#include <iostream>
#include "instrument.h"
#include <string>
#include <vector>
int main() {

    //------------MENIU -------------
    char s;
    int lungime, latime;
    int i;
    Instrument instrument;
    std::vector<Instrument> instrumente;
    std::string categorie, nume, material, culoare;
    bool acordat;
    Dimensiuni dimensiune;

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
            case '1':
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
                break;


            case '2':
                for(i = 0; i < instrumente.size(); ++i){
                    std::cout << instrumente[i] << std::endl;
                }
                break;
            case '3':

                std::cout << "Alege cu ce instrument vrei sa canti" << std::endl;
                std::cin >> i;
                instrument.produNota("LA");
                break;
            case '4':
                int i;
                std::cout << "Alege ce instrument vrei sa acordezi" << std::endl;
                std::cin >> i;
                instrument.acordeaza();
                break;
            case '5':
                std::cout << "Alege ce instrument vrei sa vopsesti" << std::endl;
                std::cin >> i;
                instrument.vopseste("negru");
                break;
            case '6':
                std::cout << "Alege ce instrument vrei sa vopsesti" << std::endl;
                std::cin >> i;
                instrument.playSong("cantecel");
                break;
        }
    }while(s != '0');
    return 0;
}
