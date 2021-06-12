#ifndef INTERFAZ_ESTADISTICA_H
#define INTERFAZ_ESTADISTICA_H

#include "../entities/Videojuego.h"

class Videojuego; //forward declaration

class InterfazEstadistica
{
public:
    InterfazEstadistica();
    virtual float calcularEstadistica(Videojuego *vj) = 0; // no puede ser virtual pura si es un parámetro del contexto?
    virtual ~InterfazEstadistica(){};
};

class CantidadSuscritos : public InterfazEstadistica
{
public:
    CantidadSuscritos();
    float calcularEstadistica(Videojuego *vj) override;
    ~CantidadSuscritos();
};

class TotalHorasJugadas : public InterfazEstadistica
{
public:
    TotalHorasJugadas();
    float calcularEstadistica(Videojuego *vj) override;
    ~TotalHorasJugadas();
};

class PromedioRating : public InterfazEstadistica
{
public:
    PromedioRating();
    float calcularEstadistica(Videojuego *vj) override;
    ~PromedioRating();
};

#endif
