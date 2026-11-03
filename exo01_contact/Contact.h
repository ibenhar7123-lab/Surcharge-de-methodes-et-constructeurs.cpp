#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
private:
    std::string nom;
    std::string telephone;
    std::string email;

public:
    // 1) nom uniquement
    Contact(const std::string& nom)
        : nom(nom), telephone(""), email("") {}

    // 2) nom + telephone
    Contact(const std::string& nom, const std::string& telephone)
        : nom(nom), telephone(telephone), email("") {}

    // 3) nom + telephone + email
    Contact(const std::string& nom, const std::string& telephone, const std::string& email)
        : nom(nom), telephone(telephone), email(email) {}

    void afficher() const {
        std::cout << "Nom : " << nom << std::endl;
        std::cout << "Telephone : " << (telephone.empty() ? "non renseigne" : telephone) << std::endl;
        std::cout << "Email : " << (email.empty() ? "non renseigne" : email) << std::endl;
    }
};

#endif
