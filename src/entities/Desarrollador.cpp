
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Desarrollador.h"
#include "../../headers/entities/Usuario.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

Desarrollador::Desarrollador() {}

Desarrollador::Desarrollador(std::string email, std::string password, std::string nombreEmpresa) : Usuario(email, password)
{
    this->= nickname;
}

std::string Jugador::getNickname()
{
    return this->nickname;
}
std::string Jugador::getDescripcion()
{
    return this->descripcion;
}

//Jugador::set<ContratoSuscripcion> obtenerSuscripciones(EstadoSuscripcion estado);

void Jugador::cancelarSuscripcionActiva(Videojuego *vj)
{
}

//void Jugador::contratarSuscripcion(Videojuego *vj, ContratoSuscripcion susc, TipoMetodoPago m);

map<int, Partida *> Jugador::obtenerPartidasSinFinalizar()
{
    return map<int, Partida *>(); //retorna un map vacío
}

void Jugador::finalizarPartida(int idPartida)
{
}

Jugador::~Jugador(){};

public:
//Constructores
Jugador();
Jugador(string nombre, string password, string nickname, string descripcion);
//Getters
string getNombre();
string getPassword();
string getNombreEmpresa();
//Setters
//Operaciones
//set<ContratoSuscripcion> obtenerSuscripociones(EstadoSuscripcion estado);
DataDesarrollador getData();
void agregarVideojuegoPublicado(Videojuego *vj);
~Usuario();
}
;