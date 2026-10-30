#ifndef FACTURE_HPP
#define FACTURE_HPP

#include <string>
#include <vector>
#include <iostream>

struct Article {
    std::string nom;
    double prixUnitaire;
    int quantite;
    double tauxTVA;
};

class Facture {
private:
    std::vector<Article> articles;

public:

    void ajouterArticle(const std::string& nom, double prixUnitaire);

    void ajouterArticle(const std::string& nom, double prixUnitaire, int quantite);

    void ajouterArticle(const std::string& nom, double prixUnitaire, int quantite, double tauxTVA);

    void afficherTotal() const;
};

#endif
