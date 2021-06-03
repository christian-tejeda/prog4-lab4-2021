#ifndef DATA_PARTIDA_H
#define DATA_PARTIDA_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../enums.h"
#include "../datatypes/DataVideojuego.h"
#include "../datatypes/DataFecha.h"

using namespace std;

class DataPartida
{
private:
    int id;
    DataVideojuego videojuego;
    //DataFecha fechaInicio;
    //DataFecha fechaFin;
    float DuracionTotal;

public:
    DataPartida();
    DataPartida(int id, DataVideojuego videojuego, DataFecha fechaInicio, DataFecha fechaFin, float DuracionTotal);
    //Getters
    int getId() const;
    DataVideojuego getVideojuego() conts;
    //DataFecha getFechaInicio();
    //DataFecha getFechaFin();
    float getDuracionTotal();
    //Setters

    //Destructor
    ~DataVideojuego();
};

#endif