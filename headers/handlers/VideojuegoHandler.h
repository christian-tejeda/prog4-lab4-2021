#ifndef VIDEOJUEGO_HANDLER_H
#define VIDEOJUEGO_HANDLER_H

#include <string>
#include <map>

#include "../entities/Videojuego.h"

using namespace std;

class VideojuegoHandler
{ //singleton
private:
    static VideojuegoHandler *instancia;
    map<string, Videojuego *> vjs;

public:
    VideojuegoHandler();

    //op de singleton
    static VideojuegoHandler *getInstance();

    //ops del manejador
    void agregarrVideojuego(Videojuego *vj);
    map<string, Videojuego *> obtenerVideojuegos();
    Videojuego *obtenerVideojuegoPorId(string nombre);
    void eliminarVideojuego(Videojuego *vj);
    void actualizarVideojuego(Videojuego *vj);
    map<string, Jugador *> obtenerJugadoresVideojuego(Videojuego *vj);

    ~VideojuegoHandler();
};

#endif