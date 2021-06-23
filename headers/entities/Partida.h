#ifndef PARTIDA_H
#define PARTIDA_H

#include "../utils/Fecha.h"
#include "../datatypes/DataPartida.h"

class Videojuego;
class Jugador;
class DataPartida;

class Partida
{

private:
    int id;
    Fecha fechaInicio;
    Fecha fechaFin;
    float duracionTotal;
    Videojuego *videojuego;
    Jugador *host;

public:
    Partida();
    Partida(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, Videojuego *videojuego, Jugador *host);

    int getId();
    Fecha getFechaInicio();
    Fecha getFechaFin();
    float getDuracionTotal();
    Videojuego *getVideojuego();
    Jugador *getHost();

    void setId(int id);
    void setFechaInicio(Fecha fechaInicio);
    void setFechaFin(Fecha fechaFin);
    void setDuracionTotal(float duracionTotal);
    void setHost(Jugador *host);

    bool esFinalizada();
    bool perteneceAVideojuego(Videojuego *videojuego);

    virtual void finalizar(Fecha fecha) = 0;
    virtual void eliminarPartidasVideojuego(Videojuego *videojuego) = 0;

    virtual ~Partida();
};

#endif