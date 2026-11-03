#include "Facture.h"

int main() {
    Facture f;
    f.ajouterArticle("Stylo", 2.5);                 // version 1
    f.ajouterArticle("Cahier", 4.0, 3);             // version 2
    f.ajouterArticle("Clavier", 50.0, 2, 20.0);     // version 3
    f.ajouterArticle("Erreur", -5.0);               // refuse
    f.afficherTotal();
    return 0;
}
