#ifndef JUGADOR_H
#define JUGADOR_H

#include <map>
#include <set>
#include <string>

#include "../datatypes/DataJugador.h"
#include "../entities/ContratoSuscripcion.h"
#include "../entities/PartidaIndividual.h"
#include "../entities/PartidaMultijugador.h"
#include "../entities/Usuario.h"
#include "../utils/enums.h"

class Partida;
class Videojuego;
class ContratoSuscripcion;

class Jugador : public Usuario
{
private:
    string nickname;
    string descripcion;
    map<int, Partida *> partidasIniciadas;
    set<ContratoSuscripcion *> contratos;

public:
    Jugador();
    Jugador(string email, string password, string nickname, string descripcion);

    string getNickname();
    string getDescripcion();

    void setNickname(string nickname);
    void setDescripcion(string descripcion);

    set<ContratoSuscripcion *> obtenerContratosActivos();

    void contratarSuscripcion(Videojuego *videojuego, TipoPeriodoValidez validez, TipoMetodoPago metodoPago, Fecha fecha);

    void crearPartidaIndividual(int idPartida, Fecha fechaActual, Videojuego *videojuego, Jugador *host, PartidaIndividual *continuacion);

    void crearPartidaMultijugador(int idPartida, Fecha fechaActual, Fecha fechaFin, Videojuego *videojuego, bool transmitida, Jugador *host, map<string, Jugador *> participantes);

    void cancelarSuscripcionActiva(Videojuego *videojuego);

    void contratarSuscripcion(Videojuego *videojuego, ContratoSuscripcion *contrato, TipoMetodoPago metodoPago);

    map<int, Partida *> obtenerPartidasSinFinalizar();

    void finalizarPartida(int idPartida, Fecha fecha);

    map<string, Videojuego *> obtenerVideojuegos();

    void eliminarContratosDeVideojuego(Videojuego *videojuego);

    void eliminarPartidasDeVideojuego(Videojuego *videojuego);

    map<int, PartidaIndividual *> obtenerPartidasFinalizadas();

    PartidaIndividual *obtenerPartida(int id);

    bool tieneSuscripcionActiva(Videojuego *videojuego);

    float calcularTotalHorasPartidasIniciadas(Videojuego *videojuego);

    bool tienePartidaSinFinalizar(Videojuego *videojuego);

    map<string, Videojuego *> obtenerVideojuegosConSuscripcionActiva(Fecha fechaActual);

    int obtenerDuracionPartida(Videojuego *videojuego);

    Partida *obtenerPartidaPorId(int id);

    DataJugador getData();

    ~Jugador();
};

#endif