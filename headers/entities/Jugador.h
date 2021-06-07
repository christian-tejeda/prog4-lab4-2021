#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataUsuario.h"
#include "../datatypes/DataJugador.h"
#include "../entities/Usuario.h"
#include "../entities/Partida.h"
#include "../entities/PartidaIndividual.h"
#include "../entities/PartidaMultijugador.h"
//#include "../entities/ContratoSuscripcion.h"
#include "../entities/Videojuego.h"

class Jugador : public Usuario
{
private:
    std::string nickname;
    std::string descripcion;
    //set<Jugador*> sigue;  NO HAY QUE IMPLEMENTARLO
    map<int, Partida *> partidasIniciadas;
    //set<ContratoSuscripcion *> contratos;

public:
    //Constructores
    Jugador();
    Jugador(std::string nombre, std::string password, std::string nickname, std::string descripcion /*,set<ContratoSuscripcion *> contratos*/);
    //Getters
    //string getNombre();
    //string getPassword();
    std::string getNickname();
    std::string getDescripcion();
    //Setters
    void setNickname(std::string nick);
    void setDescripcion(std::string descripcion);
    //Operaciones
    void cancelarSuscripcionActiva(Videojuego *vj);
    //void contratarSuscripcion(Videojuego *vj, ContratoSuscripcion susc, TipoMetodoPago m);
    map<int, Partida *> obtenerPartidasSinFinalizar();
    void finalizarPartida(int idPartida);
    map<std::string, Videojuego *> obtenerVideojuegos();
    void eliminarContratosDeVideojuego(Videojuego *vj);
    void eliminarPartidasDeVideojuego(Videojuego *vj);
    DataUsuario getData();
    map<int, PartidaIndividual *> obtenerPartidasFinalizadas();
    PartidaIndividual *obtenerPartida(std::string id);
    bool tieneSuscripcionActiva(Videojuego *vj);
    ~Jugador();
};

#endif