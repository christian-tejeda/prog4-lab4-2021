#ifndef USUARIO_CONTROLLER_H
#define USUARIO_CONTROLLER_H

#include "../interfaces/IUsuarioController.h"
#include "../entities/Usuario.h"
#include "../entities/Videojuego.h"

class UsuarioController : public IUsuarioController
{ //singleton
private:
    UsuarioController *instancia;

    Usuario *sesion;
    DataDesarrollador *dataDesarrollador; //se borra la instacnia al terminar el CU
    DataJugador *dataJugador;             //se borra la instacnia al terminar el CU
    Videojuego *videojuego;               //se borra la referencia
    pair<TipoPeriodoValidez, float> suscripcion;
    TipoMetodoPago metodoP;

public:
    UsuarioController();
    //op de singleton
    static UsuarioController *getInstance();
    //Getters
    Usuario *getSesion();
    DataDesarrollador *getDataDesarrollador();
    DataJugador *getDataJugador();
    Videojuego *getVideojuego();
    pair<TipoPeriodoValidez, float> getSuscripcion();
    TipoMetodoPago getMetodoPago();
    //ops de interface
    void ingresarDatosJugador(DataJugador *dataJugador);
    void ingresarDatosDesarrollador(DataDesarrollador *dataDesarrollador);
    void confirmarAltaUsuario(bool confirmar);
    set<DataContratoSuscripcion *> obtenerSuscripciones();
    void cancelarSuscripcion(bool cancelada);
    void contratarSuscripcion(pair<TipoPeriodoValidez, float> suscripcion, TipoMetodoPago m);
    void confirmarSuscripcion(bool confirmar);
    set<DataVideojuego *> obtenerVideojuegosPublicadosPorDesarrollador();
    set<DataEstadistica *> calcularEstadisticas(string nomVideojuego);
    set<DataPartidaMultijugador *> obtenerPartidasMultijugadorActivasDeJugador();
    void seleccionarPartida(int id);
    void seleccionarVideojuego(string nombreVideojuego);
    bool iniciarSesion(DataUsuario *dataUsuario);
    void confirmarInicioSesion(bool confirmar);

    ~UsuarioController();
};

#endif