#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include "../datatypes/DataUsuario.h"

class Usuario
{
private:
    string email;
    string password;

public:
    Usuario();
    Usuario(string email, string password);

    string getEmail();
    string getPassword();

    void setEmail(string email);
    void setPassword(string password);

    virtual ~Usuario(){};
};

#endif
