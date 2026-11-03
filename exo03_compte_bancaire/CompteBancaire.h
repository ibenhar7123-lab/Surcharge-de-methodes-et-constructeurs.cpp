#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

#include <iostream>
#include <string>

class CompteBancaire {
private:
    std::string titulaire;
    double solde;
    int codeSecurite;

    static const int CODE_PAR_DEFAUT = 1234;
    static const int PLAFOND_SANS_CODE = 1000;

public:
    // Compte sans solde initial
    CompteBancaire(const std::string& titulaire)
        : titulaire(titulaire), solde(0.0), codeSecurite(CODE_PAR_DEFAUT) {}

    // Compte avec solde initial
    CompteBancaire(const std::string& titulaire, double soldeInitial)
        : titulaire(titulaire), solde(soldeInitial >= 0 ? soldeInitial : 0.0),
          codeSecurite(CODE_PAR_DEFAUT) {
        if (soldeInitial < 0)
            std::cout << "Solde initial negatif refuse : compte ouvert a 0." << std::endl;
    }

    void afficherSolde() const {
        std::cout << "Titulaire : " << titulaire << ", Solde : " << solde << " EUR" << std::endl;
    }

    // Retrait simple : limite a 1000 EUR par operation
    bool retrait(double montant) {
        if (montant <= 0) {
            std::cout << "Montant invalide." << std::endl;
            return false;
        }
        if (montant > PLAFOND_SANS_CODE) {
            std::cout << "Plafond depasse : code de securite requis au-dela de "
                      << PLAFOND_SANS_CODE << " EUR." << std::endl;
            return false;
        }
        if (montant > solde) {
            std::cout << "Fonds insuffisants." << std::endl;
            return false;
        }
        solde -= montant;
        return true;
    }

    // Retrait avec code de securite : pas de plafond, code verifie
    bool retrait(double montant, int code) {
        if (code != codeSecurite) {
            std::cout << "Code de securite incorrect." << std::endl;
            return false;
        }
        if (montant <= 0) {
            std::cout << "Montant invalide." << std::endl;
            return false;
        }
        if (montant > solde) {
            std::cout << "Fonds insuffisants." << std::endl;
            return false;
        }
        solde -= montant;
        return true;
    }
};

#endif
