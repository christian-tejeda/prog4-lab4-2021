

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/controllers/UsuarioController.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

UsuarioController::UsuarioController() {}
//op de singleton
UsuarioController *UsuarioController::getInstance() { return nullptr; }
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
//ops de interface
void UsuarioController::ingresarDatosJugador(DataJugador *dataJugador) {}
void UsuarioController::ingresarDatosDesarrollador(DataDesarrollador *dataDesarrollador) {}
void UsuarioController::confirmarAltaUsuario(bool confirmar) {}
set<DataContratoSuscripcion *> UsuarioController::obtenerSuscripciones()
{
    set<DataContratoSuscripcion *> res;
    res.insert(nullptr);
    return res;
}
void UsuarioController::cancelarSuscripcion(bool cancelada) {}
void UsuarioController::contratarSuscripcion(pair<TipoPeriodoValidez, float> suscripcion, TipoMetodoPago m) {}
void UsuarioController::confirmarSuscripcion(bool confirmar) {}
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
void UsuarioController::seleccionarVideojuego(string nombreVideojuego) {}
bool UsuarioController::iniciarSesion(DataUsuario *dataUsuario) { return false; }
void UsuarioController::confirmarInicioSesion(bool confirmar) {}
UsuarioController::~UsuarioController() {}