
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

<<<<<<< HEAD
//using namespace std;

=======
>>>>>>> 166a22804ed46be14747382f2ea63c5b2f0101e6
Desarrollador::Desarrollador() {}

Desarrollador::Desarrollador(std::string email, std::string password, std::string nombreEmpresa) : Usuario(email, password)
{
<<<<<<< HEAD
    this->nombreEmpresa;
}

std::string Desarrollador::getNombreEmpresa()
{
    return this->nombreEmpresa;
}

//Jugador::set<ContratoSuscripcion> obtenerSuscripciones(EstadoSuscripcion estado);

DataUsuario Desarrollador::*getData()
{
    return 0;
}

void Desarrollador::agregarVideojuegoPublicado(Videojuego *vj)
{
}
//Setters
//Operaciones
//set<ContratoSuscripcion> obtenerSuscripociones(EstadoSuscripcion estado);
=======
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
>>>>>>> 166a22804ed46be14747382f2ea63c5b2f0101e6
