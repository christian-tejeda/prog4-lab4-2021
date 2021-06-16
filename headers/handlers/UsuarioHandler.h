#ifndef USUARIO_HANDLER_H
#define USUARIO_HANDLER_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataVideojuego.h"
#include "../entities/Usuario.h"
#include "../entities/Videojuego.h"
#include "../utils/Fecha.h"

using namespace std;

class UsuarioHandler
{ //singleton
private:
    static UsuarioHandler *instancia;
    map<string, Usuario *> users;
    UsuarioHandler();
    ~UsuarioHandler();

public:
    static UsuarioHandler *getInstance();

    bool existeJugadorConNickname(string n);

    void agregarUsuario(DataUsuario *usuario);

    map<string, Usuario *> obtenerJugadoresConSuscripcionActiva(Videojuego *vj);

    Jugador *obtenerJugadorPorNickname(string n);

    bool tienePartidaSinFinalizar(Videojuego *vj);

    map<string, Usuario *> obtenerUsuarios();

    Partida *obtenerPartidaPorId(int idPartida);

    void eliminarUsuario(Usuario *usuario);

    int obtenerHoras(Videojuego* vj);
};

#endif