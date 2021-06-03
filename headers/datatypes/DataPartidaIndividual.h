#ifndef DATA_PARTIDA_INDIVIDUAL_H
#define DATA_PARTIDA_INDIVIDUAL_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../enums.h"
#include "../datatypes/DataPartida.h"
#include "../datatypes/DataVideojuego.h"

using namespace std;

class DataPartidaIndividual : public DataPartida
{
private:
    bool esContinuacion;

public:
    DataPartidaIndividual();
    DataPartidaIndividual(int id, DataVideojuego videojuego, DataFecha fechaInicio, DataFecha fechaFin, float DuracionTotal, bool continuacion);
    //Getters
    int getId() const;
    DataVideojuego getVideojuego() conts;
    //DataFecha getFechaInicio();
    //DataFecha getFechaFin();
    float getDuracionTotal();
    bool getContinuacion();
    //Setters

    //Destructor
    ~DataPartidaIndividual();
};

#endif