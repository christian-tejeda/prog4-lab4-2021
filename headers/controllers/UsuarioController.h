#ifndef USUARIO_CONTROLLER_H
#define USUARIO_CONTROLLER_H

#include "../interfaces/ISeleccionarEstadisticas.h"
#include "../interfaces/IConsultarEstadisticas.h"
#include "../interfaces/ISuscribirseVideojuego.h"
#include "../interfaces/IIniciarSesion.h"
#include "../interfaces/IAltaUsuario.h"
#include "../entities/Usuario.h"
#include "../entities/Videojuego.h"

class UsuarioController : public ISeleccionarEstadisticas, public IConsultarEstadisticas, public ISuscribirseVideojuego, public IIniciarSesion, public IAltaUsuario
{ //singleton
private:
    static UsuarioController *instancia;

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

    //ops de ISeleccionarEstadisticas
    std::set<DataEstadistica *> listarEstadisticas();
    void seleccionarEstadisticas(std::set<std::string> nombresEstadisticas);

    //ops de IConsultarEstadisticas
    set<DataVideojuego *> obtenerVideojuegosPublicadosPorDesarrollador();
    set<DataEstadistica *> calcularEstadisticas(string nomVideojuego);

    //ops de ISuscribirseVideojuego
    set<DataContratoSuscripcion *> obtenerSuscripciones();
    void seleccionarVideojuego(string nombreVideojuego);
    void cancelarSuscripcion(bool cancelada);
    void contratarSuscripcion(pair<TipoPeriodoValidez, float> suscripcion, TipoMetodoPago m);
    void confirmarSuscripcion(bool confirmar);

    //ops de IIniciarSesion
    bool iniciarSesion(DataUsuario *dataUsuario);
    void confirmarInicioSesion(bool confirmar);

    //ops de IAltaUsuario
    void ingresarDatosJugador(DataJugador *dataJugador);
    void ingresarDatosDesarrollador(DataDesarrollador *dataDesarrollador);
    void confirmarAltaUsuario(bool confirmar);

    ~UsuarioController();
};

#endif