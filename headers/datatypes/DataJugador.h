#ifndef DATA_JUGADOR_H
#define DATA_JUGADOR_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataVideojuego.h"
#include "../datatypes/DataUsuario.h"
#include "../utils/Fecha.h"

using namespace std;

class DataJugador : public DataUsuario
{
private:
    //string email;
    //string password;
    string nickname;
    string descripcion;

public:
    DataJugador();
    DataJugador(string email, string password, string nickname, string descripcion);
    //getters
    //string getEmail();
    //string getPassword();
    string getNickname();
    string getDescripcion();
    //descripcion
    ~DataJugador();
};

#endif