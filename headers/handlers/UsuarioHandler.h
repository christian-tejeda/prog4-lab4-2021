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
    UsuarioHandler *instancia;
    map<string, Usuario *> users;

public:
    UsuarioHandler();

    //op de singleton, static para hacerla op de clase
    static UsuarioHandler *getInstance();

    //ops del manejador
    bool existeJugadorConNickname(string n);
    void agregarUsuario(Usuario *usuario);
    map<string, Usuario *> obtenerJugadoresConSuscripcionActiva(Videojuego *vj);
    Jugador *obtenerJugadorPorNickname(string n);
    bool tienePartidaSinFinalizar(Videojuego *vj);
    map<string, Usuario *> obtenerUsuarios();
    void actualizarUsuario(Usuario *usuario);
    Partida *obtenerPartidaPorId(int idPartida);
    void eliminarUsuario(Usuario *usuario);

    ~UsuarioHandler();
};

#endif