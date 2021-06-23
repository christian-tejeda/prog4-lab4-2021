#ifndef USUARIO_HANDLER_H
#define USUARIO_HANDLER_H

#include <string>
#include <map>
#include <set>

#include "../utils/enums.h"
#include "../datatypes/DataPartidaMultijugador.h"
#include "../entities/Usuario.h"
#include "../entities/Videojuego.h"
#include "../entities/Partida.h"

class UsuarioHandler
{
private:
    static UsuarioHandler *instancia;
    map<string, Usuario *> users;

    UsuarioHandler();
    ~UsuarioHandler();

public:
    static UsuarioHandler *getInstance();

    bool existeJugadorConNickname(string nickname);

    void agregarUsuario(DataUsuario usuario);

    map<string, Usuario *> obtenerJugadoresConSuscripcionActiva(Videojuego *videojuego);

    Jugador *obtenerJugadorPorNickname(string nickname);

    Usuario *obtenerUsuarioPorId(string email);

    bool tienePartidaSinFinalizar(Videojuego *videojuego);

    map<string, Usuario *> obtenerUsuarios();

    Partida *obtenerPartidaPorId(int idPartida);

    void eliminarUsuario(Usuario *usuario);

    static void releaseInstance();

    float obtenerHoras(Videojuego *videojuego);

    set<DataPartidaMultijugador> obtenerPartidasMultijugadorActivasDeJugador(Jugador *jugador);
};

#endif