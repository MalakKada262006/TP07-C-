#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
private:
    std::string nom;
    std::string telephone;
    std::string email;

public:
    Contact(const std::string& nom);
    Contact(const std::string& nom, const std::string& telephone);
    Contact(const std::string& nom, const std::string& telephone, const std::string& email);

    void afficher() const;
};

#endif
