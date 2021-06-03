
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataUsuario.h"
#include "../../headers/datatypes/DataJugador.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

DataJugador::DataJugador() {}

DataJugador::DataJugador(std::string email, std::string password, std::string nickname, std::string descripcion) : DataUsuario(email, password)
{
    this->nickname = nickname;
    this->descripcion = descripcion;
}

std::string DataJugador::getNickname()
{
    return this->nickname;
}
std::string DataJugador::getDescripcion()
{
    return this->descripcion;
}
DataJugador::~DataJugador(){};
