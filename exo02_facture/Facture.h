#ifndef FACTURE_H
#define FACTURE_H

#include <iostream>
#include <string>
#include <vector>

struct Article {
    std::string nom;
    double prixUnitaire;
    int quantite;
    double tva; // en pourcentage (ex : 20 pour 20 %)
};

class Facture {
private:
    std::vector<Article> articles;

public:
    // 1) nom + prix unitaire (quantite = 1, TVA = 0 %)
    void ajouterArticle(const std::string& nom, double prixUnitaire) {
        ajouterArticle(nom, prixUnitaire, 1, 0.0);
    }

    // 2) nom + prix unitaire + quantite (TVA = 0 %)
    void ajouterArticle(const std::string& nom, double prixUnitaire, int quantite) {
        ajouterArticle(nom, prixUnitaire, quantite, 0.0);
    }

    // 3) nom + prix unitaire + quantite + taux de TVA
    void ajouterArticle(const std::string& nom, double prixUnitaire, int quantite, double tva) {
        if (prixUnitaire < 0 || quantite <= 0 || tva < 0) {
            std::cout << "Article invalide : " << nom << std::endl;
            return;
        }
        Article a = {nom, prixUnitaire, quantite, tva};
        articles.push_back(a);
    }

    void afficherTotal() const {
        double totalHT = 0.0, totalTVA = 0.0;
        std::cout << "=== FACTURE ===" << std::endl;
        for (size_t i = 0; i < articles.size(); i++) {
            const Article& a = articles[i];
            double ht = a.prixUnitaire * a.quantite;
            double tva = ht * a.tva / 100.0;
            totalHT += ht;
            totalTVA += tva;
            std::cout << a.nom << " : " << a.quantite << " x " << a.prixUnitaire
                      << " = " << ht << " EUR HT (TVA " << a.tva << " %)" << std::endl;
        }
        std::cout << "Total HT  : " << totalHT << " EUR" << std::endl;
        std::cout << "Total TVA : " << totalTVA << " EUR" << std::endl;
        std::cout << "Total TTC : " << totalHT + totalTVA << " EUR" << std::endl;
    }
};

#endif
