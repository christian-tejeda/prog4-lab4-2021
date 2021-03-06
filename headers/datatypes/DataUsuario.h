#ifndef DATA_USUARIO_H
#define DATA_USUARIO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
//#include "../datatypes/DataVideojuego.h"

using namespace std;

class DataUsuario
{
private:
    string email;
    string password;

public:
    DataUsuario();
    DataUsuario(string email, string password);
    string getEmail();
    string getPassword();
    virtual ~DataUsuario(){};
};

#endif