#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../datatypes/DataUsuario.h"

using namespace std;

class Usuario
{
private:
    string email;
    string password;
    //string nombre;
    //string nombre;

public:
    //Constructores
    Usuario();
    Usuario(string nombre, string password);
    //Getters
    string getEmail();
    string getPassword();
    //Setters
    //Operaciones
    virtual DataUsuario getData() = 0;

    virtual ~Usuario();
};

#endif
