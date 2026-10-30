#include "Contact.hpp"

Contact::Contact(const std::string& nom)
    : nom(nom), telephone("Non renseigne"), email("Non renseigne") {}

Contact::Contact(const std::string& nom, const std::string& telephone)
    : nom(nom), telephone(telephone), email("Non renseigne") {}

Contact::Contact(const std::string& nom, const std::string& telephone, const std::string& email)
    : nom(nom), telephone(telephone), email(email) {}

void Contact::afficher() const {
    std::cout << "Nom : " << nom
              << " | Telephone : " << telephone
              << " | Email : " << email << std::endl;
}
