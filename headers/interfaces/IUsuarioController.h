#ifndef I_USUARIO_CONTROLLER_H
#define I_USUARIO_CONTROLLER_H

#include <string>
#include <set>
#include <utility>

#include "../datatypes/DataPartidaMultijugador.h"
#include "../datatypes/DataVideojuego.h"
#include "../datatypes/DataJugador.h"
#include "../datatypes/DataDesarrollador.h"
#include "../datatypes/DataContratoSuscripcion.h"
#include "../datatypes/DataEstadistica.h"

using namespace std;

class IUsuarioController
{ //interface
public:
    virtual void ingresarDatosJugador(DataJugador *dataJugador) = 0;
    virtual void ingresarDatosDesarrollador(DataDesarrollador *dataDesarrollador) = 0;
    virtual void confirmarAltaUsuario(bool confirmar) = 0;
    virtual set<DataContratoSuscripcion *> obtenerSuscripciones() = 0;
    virtual void cancelarSuscripcion(bool cancelada) = 0;
    virtual void contratarSuscripcion(pair<TipoPeriodoValidez, float> suscripcion, TipoMetodoPago m) = 0;
    virtual void confirmarSuscripcion(bool confirmar) = 0;
    virtual set<DataVideojuego *> obtenerVideojuegosPublicadosPorDesarrollador() = 0;
    virtual set<DataEstadistica *> calcularEstadisticas(string nomVideojuego) = 0;
    virtual set<DataPartidaMultijugador *> obtenerPartidasMultijugadorActivasDeJugador() = 0;
    virtual void seleccionarPartida(int id) = 0;
    virtual void seleccionarVideojuego(string nombreVideojuego) = 0;
    virtual bool iniciarSesion(DataUsuario *dataUsuario) = 0;
    virtual void confirmarInicioSesion(bool confirmar) = 0;
};

#endif