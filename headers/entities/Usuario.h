#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../datatypes/DataUsuario.h"

class Usuario
{
private:
    std::string email;
    std::string password;

public:
    //Constructores
    Usuario();
    Usuario(std::string nombre, std::string password);
    //Getters
    std::string getEmail();
    std::string getPassword();
    //Setters
    virtual void setEmail(std::string email);
    virtual void setPassword(std::string password);
    //Operaciones
    virtual DataUsuario getData() = 0;

    virtual ~Usuario(){};
};

#endif
