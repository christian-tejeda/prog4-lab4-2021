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

using namespace std;

class Jugador : public Usuario
{
private:
    string nickname;
    string descripcion;
    //set<Jugador*> sigue;  NO HAY QUE IMPLEMENTARLO
    set<Partida *> partidasIniciadas;
    //set<ContratoSuscripcion*> contratos;

public:
    //Constructores
    Jugador();
    Jugador(string nombre, string password, string nickname, string descripcion);
    //Getters
    string getNombre();
    string getPassword();
    string getNickname();
    string getDescripcion();
    //Setters
    //Operaciones
    //set<ContratoSuscripcion> obtenerSuscripociones(EstadoSuscripcion estado);
    void cancelarSuscripcionActiva(Videojuego *vj);
    //void contratarSuscripcion(Videojuego *vj, ContratoSuscripcion susc, TipoMetodoPago m);
    set<Partida *> obtenerPartidasSinFinalizar();
    void finalizarPartida(int idPartida);
    set<Videojuego *> obtenerVIdeojuegos();
    void eliminarContratosDeVideojuego(Videojuego *vj);
    void eliminarPartidasDeVideojuego(Videojuego *vj);
    DataUsuario getData();
    set<PartidaIndividual *> obtenerPartidasFinalizadas();
    PartidaIndividual obtenerPartida(string id);
    bool tieneSuscripcionActiva(Videojuego *vj);
    ~Jugador();
};

#endif