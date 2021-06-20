#ifndef PARTIDA_H
#define PARTIDA_H

#include "../utils/Fecha.h"
//#include "../entities/Jugador.h"
//#include "../entities/Videojuego.h"
#include "../datatypes/DataPartida.h"

class Videojuego;  //forward declaration
class Jugador;     //forward declaration
class DataPartida; //forward declaration

class Partida
{

private:
    int id;
    Fecha fechaInicio;
    Fecha *fechaFin;
    float duracionTotal;
    Videojuego *videojuego;
    Jugador *host;

public:
    Partida();
    // DATA PARTIDA NO TIENE LOS REQUERIMIENTOS NECESARIOS PARA COONSTUIR LE FALTAN INSTANCIA A VIDEOJUEGO Y A JUGADORESPartida(DataPartida dataPartida);
    Partida(int id, Fecha fechaInicio, Fecha *fechaFin, float duracionTotal, Videojuego *vj, Jugador *host);

    //Getters
    int getId();
    Fecha getFechaInicio();
    Fecha *getFechaFin();
    float getDuracionTotal();
    Videojuego *getVideojuego();
    Jugador *getHost();

    //Setters
    void setId(int id);
    void setFechaInicio(Fecha fechaInicio);
    void setFechaFin(Fecha *fechaFin);
    void setDuracionTotal(float duracionTotal);
    void setHost(Jugador *host);

    bool esFinalizada();
    bool perteneceAVideojuego(Videojuego *videojuego);

    virtual void finalizar(Fecha * fecha) = 0;
    virtual void eliminarPartidasVideojuego(Videojuego *videojuego) = 0;

    virtual DataPartida *getData() = 0;

    virtual ~Partida();
};

#endif