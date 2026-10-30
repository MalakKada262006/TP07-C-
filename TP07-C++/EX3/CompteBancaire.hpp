#ifndef COMPTE_BANCAIRE_HPP
#define COMPTE_BANCAIRE_HPP

#include <string>
#include <iostream>

class CompteBancaire {
private:
    std::string numero;
    double solde;
    std::string codeSecurite;

public:
    CompteBancaire(const std::string& num);
    CompteBancaire(const std::string& num, double soldeInitial);
    CompteBancaire(const std::string& num, double soldeInitial, const std::string& code);

    void afficherSolde() const;

    void retrait(double montant);
    void retrait(double montant, const std::string& codeFourni);
};

#endif
