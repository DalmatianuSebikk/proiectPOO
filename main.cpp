#include <iostream>
#include "Instrument.h"
#include "Cantaret.h"
#include <string>
#include <vector>
#include <memory>
#include "factory.h"
using namespace std::string_literals;




int main() {

    Cantaret c;//{"Antonio Banderas"s, {{"Bamboleo"s}, {"Am bani de ma enerveaza"s}}};
    //------------MENIU -------------
    char s;
    int lungime, latime;
    int i;
    Instrument instrument;
//    std::vector<Instrument> instrumente;
//    std::vector<std::unique_ptr<Instrument>> instrumente;
    std::string culoare, cantecel;


    try{
        std::string numeCantaret = c.getNume();
        std::vector<std::string> canteceCunoscuteDeCantaret = c.getCanteceCunoscute();
        auto& instrumente = c.getInstrumente(); // auto pentruca am declarat un vector de instrumente separat si nu e referinta si incearca sa copieze
        c.canta(3, "Bamboleo");
    }
    catch(std::invalid_argument &err){
        std::cout << err.what() << std::endl;
        return 0;
    }
    catch(std::length_error &err){
        std::cout << err.what() << std::endl;
        return 0;
    }
    catch(std::exception &err){
        std:: cout << err.what();
        return 0;
    }
    std::cout << c;

//    try {
//        if(c.getNume() == "N/A"){
//            throw 1;
//        }
//
//    }
//    catch(int x){
//        std::cout << "numele cantaretului nu a fost gasit. Error " << x << std::endl;
//        std::cout << "setez numele cantaretului la Antonio Banderas" << std::endl;
//        c.setNume("Antonio Banderas");
//    }

//    try {
//        if(c.getCanteceCunoscute().size() == 0) {
//            throw 2;
//        }
//    }
//    catch(int x) {
//        std::cout << "Nu stie sa cante nici un cantec. Trist, dar rezolvam acum." << std::endl;
//        std::cout << "Adaug niste cantece" << std::endl;
//        c.setCanteceCunoscute({{"Bamboleo"s}, {"Am bani de ma enerveaza"s}});
//    }

//    try {
//        if(c.getInstrumente().size() == 0) {
//            throw 3;
//        }
//    }
//    catch(int x) {
//        std::cout << "Nu stie sa cante la nici un instrument. Trist, dar rezolvam acum." << std::endl;
//        std::cout << "Adaug niste cantece";
//        c.adauga_instrument("Chitara");
//    }
    try{
        c.canta(3, "Bamboleo");
    }
    catch(std::exception &err){
        std:: cout << err.what();
    }
    std::cout << c;


    // NU E BINE SA FACI TRY TRY TRY ... TRY, pentru ca e si greu de citit si .. nu e ok :)))
    // FACI UN SINGUR TRY DUPA CARE FACI CATCH
//    try {
//        if(c.getNume() == "N/A"){
//            throw 1;
//        }
//
//    }
//    catch(int x){
//        std::cout << "numele cantaretului nu a fost gasit. Error " << x << std::endl;
//        std::cout << "setez numele cantaretului la Antonio Banderas" << std::endl;
//        c.setNume("Antonio Banderas");
//    }
//
//    try {
//        if(c.getCanteceCunoscute().size() == 0) {
//            throw 2;
//        }
//    }
//    catch(int x) {
//        std::cout << "Nu stie sa cante nici un cantec. Trist, dar rezolvam acum." << std::endl;
//        std::cout << "Adaug niste cantece" << std::endl;
//        c.setCanteceCunoscute({{"Bamboleo"s}, {"Am bani de ma enerveaza"s}});
//    }
//
//    try {
//        if(c.getInstrumente().size() == 0) {
//            throw 3;
//        }
//    }
//    catch(int x) {
//        std::cout << "Nu stie sa cante la nici un instrument. Trist, dar rezolvam acum." << std::endl;
//        std::cout << "Adaug niste cantece";
//        c.adauga_instrument("Chitara");
//    }
//    try{
//        c.canta(3, "Bamboleo");
//    }
//    catch(std::exception &err){
//        std:: cout << err.what();
//    }
//    std::cout << c;



//    do{
//        std::cout << "------------MENIU -------------" << std::endl;
//        std::cout << "1. Citeste instrument muzical" << std::endl;
//        std::cout << "2. Afiseaza instrumentele muzicale" << std::endl;
//        std::cout << "3. Canta o melodie" << std::endl;
//        std::cout << "4. Acordeaza" << std::endl;
//        std::cout << "5. Vopseste-o" << std::endl;
//        std::cout << "6. Canta o melodie" << std::endl;
//        std::cout << "0. Iesire" << std::endl;
//        std::cin >> s;
//        switch(s){
//            case '0':
//                std::cout << "paaa"<<std::endl;
//                break;
//            case '1':
//                adauga_instrument(instrumente);
//                break;
//            case '2':
//                afiseaza_instrumente(instrumente);
//                break;
//            case '3':
//                produ_nota(instrumente, i);
//                break;
//            case '4':
//                acordeaza(instrumente, i);
//                break;
//            case '5':
//                vopseste(instrumente, i, culoare);
//                break;
//            case '6':
//                canta(instrumente, i, cantecel);
//                break;
//        }
//    }while(s != '0');


    return 0;
}
