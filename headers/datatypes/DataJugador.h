#ifndef DATA_JUGADOR_H
#define DATA_JUGADOR_H

#include <string>

#include "../datatypes/DataUsuario.h"

using namespace std;

class DataJugador : public DataUsuario
{
private:
    string nickname;
    string descripcion;

public:
    DataJugador();
    DataJugador(const DataJugador &data);
    DataJugador(string email, string password, string nickname, string descripcion);

    string getNickname() const;
    string getDescripcion() const;

    friend bool operator<(const DataJugador &d1, const DataJugador &d2);
    friend bool operator!=(const DataJugador &d1, const DataJugador &d2);
    friend bool operator==(const DataJugador &d1, const DataJugador &d2);

    ~DataJugador();
};

#endif