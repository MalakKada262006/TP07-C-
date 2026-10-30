#include "CompteBancaire.hpp"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    std::cout << "=== Test de la classe CompteBancaire (Surcharge et Logique Metier) ===\n" << std::endl;

    CompteBancaire c1("FR111");
    CompteBancaire c2("FR222", 1500.0);
    CompteBancaire c3("FR333", 3000.0, "9999");

    std::cout << "\n--- Affichage des soldes initiaux ---" << std::endl;
    c1.afficherSolde();
    c2.afficherSolde();
    c3.afficherSolde();

    std::cout << "\n--- Tests des operations de retrait ---" << std::endl;

    c2.retrait(200.0);
    c2.retrait(2000.0);

    c3.retrait(500.0, "0000");
    c3.retrait(500.0, "9999");

    std::cout << "\n--- Etat final des comptes ---" << std::endl;
    c2.afficherSolde();
    c3.afficherSolde();

    return 0;
}
