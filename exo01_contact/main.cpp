#include "Contact.h"

int main() {
    Contact c1("Alice");
    Contact c2("Bob", "0612345678");
    Contact c3("Charlie", "0698765432", "charlie@example.com");

    c1.afficher();
    std::cout << "-----" << std::endl;
    c2.afficher();
    std::cout << "-----" << std::endl;
    c3.afficher();
    return 0;
}
