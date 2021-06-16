#ifndef VIDEOJUEGO_HANDLER_H
#define VIDEOJUEGO_HANDLER_H

#include <string>
#include <map>

#include "../entities/Videojuego.h"

using namespace std;

class VideojuegoHandler
{
private:
    static VideojuegoHandler *instancia;
    map<string, Videojuego *> vjs;
    VideojuegoHandler();
    ~VideojuegoHandler();

public:
    static VideojuegoHandler *getInstance();

    void agregarVideojuego(Videojuego *vj);

    map<string, Videojuego *> obtenerVideojuegos();

    Videojuego *obtenerVideojuegoPorId(string nombre);

    void eliminarVideojuego(Videojuego *vj);

    map<string, Jugador *> obtenerJugadoresVideojuego(Videojuego *vj);

    set<std::string> obtenerNombresVideojuegos();
};

#endif