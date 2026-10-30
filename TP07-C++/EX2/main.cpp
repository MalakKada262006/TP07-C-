#include "Facture.hpp"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    std::cout << "=== Systeme de facturation (Surcharge de methodes) ===" << std::endl;

    Facture maFacture;

    std::cout << "\n--- Ajout d articles via les differentes surcharges ---" << std::endl;

    maFacture.ajouterArticle("Clavier mecanique", 75.0);

    maFacture.ajouterArticle("Souris sans fil", 25.0, 2);

    maFacture.ajouterArticle("Livre C++ Moderne", 42.0, 3, 5.5);

    maFacture.afficherTotal();

    return 0;
}
