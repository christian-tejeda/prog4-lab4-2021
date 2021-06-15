

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/controllers/UsuarioController.h"
#include "../../headers/handlers/UsuarioHandler.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

UsuarioController *UsuarioController::instancia = nullptr;

UsuarioController::UsuarioController() {}

//op de singleton
UsuarioController *UsuarioController::getInstance()
{
    if (instancia == nullptr)
        instancia = new UsuarioController();
    return instancia;
}

//Getters
Usuario *UsuarioController::getSesion() { return nullptr; }
DataDesarrollador *UsuarioController::getDataDesarrollador()
{
    return this->dataDesarrollador;
}
DataJugador *UsuarioController::getDataJugador()
{
    return this->dataJugador;
}
Videojuego *UsuarioController::getVideojuego()
{
    return this->videojuego;
}

pair<TipoPeriodoValidez, float> UsuarioController::getSuscripcion()
{
    return this->suscripcion;
}
TipoMetodoPago UsuarioController::getMetodoPago()
{
    return this->metodoP;
}

//métodos de ISeleccionarEstadisticas
std::set<DataEstadistica *> UsuarioController::listarEstadisticas()
{
    set<DataEstadistica *> res;
    return res;
}
void UsuarioController::seleccionarEstadisticas(std::set<std::string> nombresEstadisticas) {}

//métodos de IAltaUsuario
void UsuarioController::ingresarDatosJugador(DataJugador *dataJugador)
{

    UsuarioHandler *uh = UsuarioHandler::getInstance();
    bool existeNick = uh->existeJugadorConNickname(dataJugador->getNickname());

    if (existeNick)
    {
        throw std::invalid_argument("Error: Ya existe un jugador con ese nickname. Pruebe con uno distinto.");
    }
    else
    {
        this->dataJugador = dataJugador;
    }
}

void UsuarioController::ingresarDatosDesarrollador(DataDesarrollador *dataDesarrollador)
{
    this->dataDesarrollador = dataDesarrollador;
}

void UsuarioController::confirmarAltaUsuario(bool confirmar) {}

//métodos de ISuscribirseVideojuego
set<DataContratoSuscripcion *> UsuarioController::obtenerSuscripciones()
{
    set<DataContratoSuscripcion *> res;
    res.insert(nullptr);
    return res;
}
void UsuarioController::seleccionarVideojuego(string nombreVideojuego) {}
void UsuarioController::cancelarSuscripcion(bool cancelada) {}
void UsuarioController::contratarSuscripcion(pair<TipoPeriodoValidez, float> suscripcion, TipoMetodoPago m) {}
void UsuarioController::confirmarSuscripcion(bool confirmar) {}

//métodos de IConsultarEstadisticas
set<DataVideojuego *> UsuarioController::obtenerVideojuegosPublicadosPorDesarrollador()
{
    set<DataVideojuego *> res;
    res.insert(nullptr);
    return res;
}
set<DataEstadistica *> UsuarioController::calcularEstadisticas(string nomVideojuego)
{
    set<DataEstadistica *> res;
    res.insert(nullptr);
    return res;
}

// set<DataPartidaMultijugador *> UsuarioController::obtenerPartidasMultijugadorActivasDeJugador()
// {
//     set<DataPartidaMultijugador *> res;
//     res.insert(nullptr);
//     return res;
// }
// void UsuarioController::seleccionarPartida(int id) {}

//métodos de IIniciarSesion
bool UsuarioController::iniciarSesion(DataUsuario *dataUsuario) { return false; }
void UsuarioController::confirmarInicioSesion(bool confirmar) {}

UsuarioController::~UsuarioController() {}