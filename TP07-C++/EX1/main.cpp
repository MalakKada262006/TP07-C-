#include "Contact.hpp"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {


    std::cout << "=== Gestion d un carnet d adresses (Surcharge de constructeurs) ===" << std::endl;

    Contact c1("Alice");

    Contact c2("Amine", "0612345678");

    Contact c3("Aya", "0698765432", "aya@email.com");

    std::cout << "\nAffichage du carnet :" << std::endl;
    c1.afficher();
    c2.afficher();
    c3.afficher();

    return 0;
}
