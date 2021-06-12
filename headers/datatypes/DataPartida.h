#ifndef DATA_PARTIDA_H
#define DATA_PARTIDA_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataVideojuego.h"
#include "../utils/Fecha.h"
//#include "../entities/Videojuego.h"

using namespace std;

class DataPartida
{
private:
    int id;
    DataVideojuego videojuego;
    Fecha fechaInicio;
    Fecha *fechaFin;
    float DuracionTotal;

public:
    DataPartida();
    DataPartida(int id, DataVideojuego videojuego, Fecha fechaInicio, Fecha *fechaFin, float DuracionTotal);
    //Getters
    int getId();
    DataVideojuego getVideojuego();
    Fecha getFechaInicio();
    Fecha *getFechaFin();
    float getDuracionTotal();
    //Setters

    //Destructor
    virtual ~DataPartida();
};

#endif