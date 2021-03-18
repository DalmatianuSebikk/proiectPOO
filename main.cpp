#include <iostream>
#include "instrument.h"
#include <string>
int main() {

    //------------MENIU -------------
    char s;
    Instrument instrument;
    std::cin >> s;
    do{
        std::cout << "------------MENIU -------------" << std::endl;
        std::cout << "1. Citeste instrumentul muzical" << std::endl;
        std::cout << "2. Afiseaza instrumentul muzical" << std::endl;
        std::cout << "3. Canta o melodie" << std::endl;
        std::cout << "4. Acordeaza" << std::endl;
        std::cout << "5. vopseste-o" << std::endl;

        switch(s){
            case '1':
                std::cin >> instrument;
                break;
            case '2':
                std::cout << instrument;
                break;
            case '3':
                instrument.playSong("misto");
                break;
            case '4':
                instrument.acordeaza();
                break;
            case '5':
                instrument.vopseste("negru");
                break;
        }
    }while(s != '0');
    return 0;
}
