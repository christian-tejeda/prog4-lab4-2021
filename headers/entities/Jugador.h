#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../datatypes/DataUsuario.h"
#include "../entities/Usuario.h"
//#include "../entities/Partida.h"
//#include "../entities/Individual.h"
//#include "../entities/Multijugador.h"
//#include "../entities/ContratoSuscripcion.h"
//#include "../entities/Videojuego.h"

using namespace std;

class Jugador : public Usuario
{
private:
    string nombre;
    string password;
    string nickname;
    string descripcion;

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
    void cancelarSuscripcionActiva(Videojuego vj);
    void contratarSuscripcion(Videojuego vj, Suscripcion susc, TipoMetodoPago m);
    set<Partida> obtenerPartidasSinFinalizar();
    void finalizarPartida(idPartida id);
    set<Videojuego> obtenerVIdeojuegos();
    void eliminarContratosDeVideojuego(Videojuego vj);
    void eliminarPartidasDeVideojuego(Videojuego vj);
    DataUsuario getData();
    set<Individual> obtenerPartidasFinalizadas();
    Individual obtenerPartida(string id);
    bool tieneSuscripcionActiva(Videojuego vj);
    ~Usuario();
};

#endif