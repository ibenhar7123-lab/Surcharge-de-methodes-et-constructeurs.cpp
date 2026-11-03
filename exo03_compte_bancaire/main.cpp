#include "CompteBancaire.h"

int main() {
    CompteBancaire c1("Ali");           // sans solde initial
    CompteBancaire c2("Sara", 5000);    // avec solde initial

    c1.afficherSolde();
    c2.afficherSolde();

    std::cout << "\n--- Retraits sur le compte de Sara ---" << std::endl;
    c2.retrait(200);          // OK
    c2.retrait(2000);         // refuse : plafond sans code
    c2.retrait(2000, 1111);   // refuse : mauvais code
    c2.retrait(2000, 1234);   // OK : bon code
    c2.retrait(-50);          // refuse : montant invalide
    c2.afficherSolde();

    std::cout << "\n--- Retrait sur le compte d'Ali ---" << std::endl;
    c1.retrait(10);           // refuse : fonds insuffisants
    return 0;
}
