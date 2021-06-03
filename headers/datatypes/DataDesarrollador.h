#ifndef DATA_DESARROLLADOR_H
#define DATA_DESARROLLADOR_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataVideojuego.h"
#include "../datatypes/DataUsuario.h"
#include "../utils/Fecha.h"

using namespace std;

class DataDesarrollador : public DataUsuario
{
private:
    //string email;
    //string password;
    string nombreEmpresa;
    string descripcion;

public:
    DataDesarrollador();
    DataDesarrollador(string email, string password, string nombreEmpresa);
    //getters
    string getEmail();
    string getPassword();
    string getNombreEmpresa();
    //descripcion
    ~DataDesarrollador();
};

#endif