#include "CompteBancaire.hpp"

CompteBancaire::CompteBancaire(const std::string& num)
    : numero(num), solde(0.0), codeSecurite("1234") {
    std::cout << "[Creation] Compte " << numero << " ouvert avec un solde par defaut de 0.0 €.\n";
}

CompteBancaire::CompteBancaire(const std::string& num, double soldeInitial)
    : numero(num), codeSecurite("1234") {
    if (soldeInitial >= 0.0) {
        solde = soldeInitial;
    } else {
        std::cerr << "[Erreur] Solde initial negatif interdit. Initialise a 0.0 €.\n";
        solde = 0.0;
    }
    std::cout << "[Creation] Compte " << numero << " ouvert avec un solde initial de " << solde << " €.\n";
}

CompteBancaire::CompteBancaire(const std::string& num, double soldeInitial, const std::string& code)
    : numero(num), codeSecurite(code) {
    if (soldeInitial >= 0.0) {
        solde = soldeInitial;
    } else {
        std::cerr << "[Erreur] Solde initial negatif interdit. Initialise à 0.0 €.\n";
        solde = 0.0;
    }
    std::cout << "[Creation] Compte securise " << numero << " ouvert avec un solde de " << solde << " €.\n";
}

void CompteBancaire::afficherSolde() const {
    std::cout << "Compte n° " << numero << " | Solde actuel : " << solde << " €\n";
}

void CompteBancaire::retrait(double montant) {
    std::cout << "\n[Tentative de retrait standard] Montant : " << montant << " €\n";
    if (montant <= 0) {
        std::cerr << "[Erreur] Le montant du retrait doit etre strictement positif.\n";
        return;
    }
    if (montant > solde) {
        std::cerr << "[Erreur] Fonds insuffisants sur le compte " << numero << ".\n";
        return;
    }
    solde -= montant;
    std::cout << "[Succes] Retrait de " << montant << " € effectue. Nouveau solde : " << solde << " €\n";
}

void CompteBancaire::retrait(double montant, const std::string& codeFourni) {
    std::cout << "\n[Tentative de retrait securise] Montant : " << montant << " €\n";

    if (codeFourni != codeSecurite) {
        std::cerr << "[Alerte Securite] Code de securite incorrect ! Retrait refuse.\n";
        return;
    }

    if (montant <= 0) {
        std::cerr << "[Erreur] Le montant du retrait doit etre strictement positif.\n";
        return;
    }

    if (montant > solde) {
        std::cerr << "[Erreur] Fonds insuffisants sur le compte " << numero << ".\n";
        return;
    }

    solde -= montant;
    std::cout << "[Succes Securise] Retrait de " << montant << " € valide par code. Nouveau solde : " << solde << " €\n";
}
