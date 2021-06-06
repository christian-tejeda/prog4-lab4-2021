#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../datatypes/DataUsuario.h"

<<<<<<< HEAD
//using namespace std;

=======
>>>>>>> 166a22804ed46be14747382f2ea63c5b2f0101e6
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
    void setEmail(std::string email);
    void setPassword(std::string pwd);
    //Operaciones
    virtual DataUsuario getData() = 0;

    virtual ~Usuario(){};
};

#endif
