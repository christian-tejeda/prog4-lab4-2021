#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../datatypes/DataUsuario.h"
#include "../entities/Usuario.h"
//#include "../entities/ContratoSuscripcion.h"
//#include "../entities/Videojuego.h"

using namespace std;

class Jugador
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
    cancelarSuscripcionActiva(Videojuego vj);
    contratarSuscripcion(Videojuego vj, Suscripcion susc, TipoMetodoPago m);
    set<Partida> obtenerPartidasSinFinalizar();
    finalizarPartida(idPartida id);
    obte()

        ~Usuario();
};

#endif