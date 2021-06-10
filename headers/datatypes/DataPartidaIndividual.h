#ifndef DATA_PARTIDA_INDIVIDUAL_H
#define DATA_PARTIDA_INDIVIDUAL_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataPartida.h"

using namespace std;

class DataPartidaIndividual : public DataPartida
{
private:
    bool esContinuacion;

public:
    DataPartidaIndividual();
    DataPartidaIndividual(int id, DataVideojuego videojuego, Fecha fechaInicio, Fecha fechaFin, float DuracionTotal, bool esContinuacion);
    //Getters
    //int getId() const;
    //DataVideojuego getVideojuego();
    //DataFecha getFechaInicio();
    //DataFecha getFechaFin();
    //float getDuracionTotal();
    bool getContinuacion();
    //Setters

    //Destructor
    ~DataPartidaIndividual();
};

#endif