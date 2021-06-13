
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Desarrollador.h"
//#include "../../headers/entities/Usuario.h"
//#include "../../headers/utils/enums.h"
//#include "../../headers/datatypes/DataUsuario.h"
//#include "../../headers/datatypes/DataDesarrollador.h"
#include "../../headers/utils/Fecha.h"

Desarrollador::Desarrollador() : Usuario(){};

Desarrollador::Desarrollador(std::string email, std::string password, std::string nombreEmpresa) : Usuario(email, password)
{
    // this->email = email;
    // this->password = password;
    this->nombreEmpresa = nombreEmpresa;
}

std::string Desarrollador::getNombreEmpresa()
{
    return this->nombreEmpresa;
}

//Jugador::set<ContratoSuscripcion> obtenerSuscripciones(EstadoSuscripcion estado);

DataUsuario *Desarrollador::getData()
{
    return nullptr;
}

void Desarrollador::agregarVideojuegoPublicado(Videojuego *vj)
{
}
//Setters

void Desarrollador::setNombreEmpresa(std::string nomEmpresa)
{
    this->nombreEmpresa = nomEmpresa;
}

//Operaciones
//set<ContratoSuscripcion> obtenerSuscripociones(EstadoSuscripcion estado);
