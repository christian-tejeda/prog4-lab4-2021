
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Desarrollador.h"
#include "../../headers/entities/Usuario.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataUsuario.h"
#include "../../headers/datatypes/DataDesarrollador.h"
#include "../../headers/utils/Fecha.h"

Desarrollador::Desarrollador() {}

Desarrollador::Desarrollador(std::string email, std::string password, std::string nombreEmpresa) : Usuario(email, password)
{
    this->nombreEmpresa;
}

std::string Desarrollador::getNombreEmpresa()
{
    return this->nombreEmpresa;
}

//Jugador::set<ContratoSuscripcion> obtenerSuscripciones(EstadoSuscripcion estado);

DataUsuario Desarrollador::*getData()
{
    return nullptr;
}

void Desarrollador::agregarVideojuegoPublicado(Videojuego *vj)
{
}
//Setters
//Operaciones
//set<ContratoSuscripcion> obtenerSuscripociones(EstadoSuscripcion estado);
