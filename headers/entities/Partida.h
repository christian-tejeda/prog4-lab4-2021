#ifndef PARTIDA_H
#define PARTIDA_H

#include "../utils/Fecha.h"

class Partida
{

    Partida::Partida();

    Partida::Partida(DataPartida dataPartida);

    Partida::Partida(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal);

private:
    int id;
    Fecha fechaInicio;
    Fecha fechaFin;
    float duracionTotal;

public:
    int getId();
    Fecha getFechaInicio();
    Fecha getFechaFin();
    float getDuracionTotal();
    Videojuego getVideojuego();

    void setId(int id);
    void setFechaInicio(Fecha fechaInicio);
    void setFechaFin(Fecha fechaFin);
    void setDuracionTotal(float duracionTotal);

    bool esFinalizada();
    bool perteneceAVideojuego(Videojuego videojuego);

    virtual void finalizar() = 0;
    virtual void eliminarPartidasVideojuego(Videojuego videojuego) = 0;

    virtual DataPartida getData() = 0;

    ~Partida();
};

#endif