#include "Facture.hpp"
#include <iomanip>

void Facture::ajouterArticle(const std::string& nom, double prixUnitaire) {
    ajouterArticle(nom, prixUnitaire, 1, 20.0);
}

void Facture::ajouterArticle(const std::string& nom, double prixUnitaire, int quantite) {
    ajouterArticle(nom, prixUnitaire, quantite, 20.0);
}

void Facture::ajouterArticle(const std::string& nom, double prixUnitaire, int quantite, double tauxTVA) {
    Article art;
    art.nom = nom;
    art.prixUnitaire = prixUnitaire;
    art.quantite = (quantite > 0) ? quantite : 1;
    art.tauxTVA = (tauxTVA >= 0) ? tauxTVA : 0.0;

    articles.push_back(art);
    std::cout << "[Ajout] " << art.nom << " (x" << art.quantite << ") - "
              << art.prixUnitaire << " €/u, TVA : " << art.tauxTVA << "%" << std::endl;
}

void Facture::afficherTotal() const {
    if (articles.empty()) {
        std::cout << "La facture est vide.\n";
        return;
    }

    std::cout << "\n================== FACTURE ==================" << std::endl;
    std::cout << std::left << std::setw(20) << "Article"
              << std::right << std::setw(10) << "P.U. HT"
              << std::setw(8) << "Qte"
              << std::setw(8) << "TVA"
              << std::setw(12) << "Total TTC" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    double totalGeneralTTC = 0.0;

    for (const auto& art : articles) {
        double totalHT = art.prixUnitaire * art.quantite;
        double montantTVA = totalHT * (art.tauxTVA / 100.0);
        double totalTTC = totalHT + montantTVA;
        totalGeneralTTC += totalTTC;

        std::cout << std::left << std::setw(20) << art.nom
                  << std::right << std::setw(10) << std::fixed << std::setprecision(2) << art.prixUnitaire
                  << std::setw(8) << art.quantite
                  << std::setw(7) << art.tauxTVA << "%"
                  << std::setw(12) << totalTTC << " €" << std::endl;
    }

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "TOTAL GENERAL A PAYER : " << std::fixed << std::setprecision(2)
              << totalGeneralTTC << " €" << std::endl;
    std::cout << "=============================================\n" << std::endl;
}
