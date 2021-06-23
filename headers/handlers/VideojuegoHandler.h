#ifndef VIDEOJUEGO_HANDLER_H
#define VIDEOJUEGO_HANDLER_H

#include <string>
#include <map>

#include "../entities/Videojuego.h"

class VideojuegoHandler
{
private:
    static VideojuegoHandler *instancia;

    map<string, Videojuego *> videojuegos;

    VideojuegoHandler();
    ~VideojuegoHandler();

public:
    static VideojuegoHandler *getInstance();

    void agregarVideojuego(Videojuego *videojuego);

    map<string, Videojuego *> obtenerVideojuegos();

    Videojuego *obtenerVideojuegoPorId(string nombre);

    void eliminarVideojuego(Videojuego *videojuego);

    map<string, Jugador *> obtenerJugadoresVideojuego(Videojuego *videojuego);

    static void releaseInstance();

    set<string> obtenerNombresVideojuegos();
};

#endif