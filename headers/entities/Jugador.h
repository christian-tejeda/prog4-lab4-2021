#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <map>
#include <set>
#include <utility>

class Partida; //fwd dec

#include "../utils/enums.h"
//#include "../datatypes/DataUsuario.h"
#include "../datatypes/DataJugador.h"
#include "../entities/Usuario.h"
//#include "../entities/Partida.h"
#include "../entities/PartidaIndividual.h"
#include "../entities/PartidaMultijugador.h"
#include "../entities/ContratoSuscripcion.h"
#include "../entities/Videojuego.h"

class Videojuego; //fwd dec

class Jugador : public Usuario
{
private:
    std::string nickname;
    std::string descripcion;
    map<int, Partida *> partidasIniciadas;
    set<ContratoSuscripcion *> contratos;

public:
    //Constructores
    Jugador();
    Jugador(std::string email, std::string password, std::string nickname, std::string descripcion);

    //Getters
    std::string getNickname();
    std::string getDescripcion();

    //Setters
    void setNickname(std::string nick);
    void setDescripcion(std::string descripcion);

    //Operaciones
    PartidaIndividual * crearPartidaIndividual(int idPartida,Fecha fechaActual,Videojuego * vj,Jugador *host,PartidaIndividual * cont);
    PartidaMultijugador * crearPartidaMultijugador(int idPartida, Fecha fechaActual, Fecha *fechaFin, Videojuego * vj, bool transmitida, Jugador * host, set<DuracionParticipante *> durpart);
    void cancelarSuscripcionActiva(Videojuego *vj);
    void contratarSuscripcion(Videojuego *vj, ContratoSuscripcion susc, TipoMetodoPago m);
    map<int, Partida *> obtenerPartidasSinFinalizar();
    void finalizarPartida(int idPartida);
    map<std::string, Videojuego *> obtenerVideojuegos();
    void eliminarContratosDeVideojuego(Videojuego *vj);
    void eliminarPartidasDeVideojuego(Videojuego *vj);
    DataUsuario *getData();
    map<int, PartidaIndividual *> obtenerPartidasFinalizadas();
    PartidaIndividual *obtenerPartida(int id);
    bool tieneSuscripcionActiva(Videojuego *vj);
    map<std::string,Videojuego*> obtenerVideojuegosConSuscripcionActiva();

    ~Jugador();
};

#endif