
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Desarrollador.h"
#include "../../headers/entities/Usuario.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

Desarrollador::Desarrollador() {}

Desarrollador::Desarrollador(std::string email, std::string password, std::string nombreEmpresa) : Usuario(email, password)
{
    this->nombreEmpresa = nombreEmpresa;
}

std::string Desarrollador::getNombreEmpresa()
{
    return this->nombreEmpresa;
}

map<std::string, Videojuego *> Desarrollador::getJuegosPublicados()
{
    return this->publicados;
}
