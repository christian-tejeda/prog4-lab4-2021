#include "../../headers/datatypes/DataJugador.h"

DataJugador::DataJugador()
{
    nickname = "";
    descripcion = "";
}

DataJugador::DataJugador(const DataJugador &data) : DataUsuario(data)
{
    nickname = data.nickname;
    descripcion = data.descripcion;
}

DataJugador::DataJugador(string email, string password, string nickname, string descripcion) : DataUsuario(email, password)
{
    nickname = nickname;
    descripcion = descripcion;
}

string DataJugador::getNickname() const { return nickname; }

string DataJugador::getDescripcion() const { return descripcion; }

bool operator<(const DataJugador &d1, const DataJugador &d2)
{
    return &d1 < &d2;
}

bool operator!=(const DataJugador &d1, const DataJugador &d2)
{
    return d1.getEmail() != d2.getEmail() || d1.getNickname() != d2.getNickname() || d1.getDescripcion() != d2.getDescripcion() || d1.getPassword() != d2.getPassword();
}

bool operator==(const DataJugador &d1, const DataJugador &d2)
{
    return !(d1 != d2);
}

DataJugador::~DataJugador(){};
