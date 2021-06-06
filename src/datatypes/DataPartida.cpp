
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataPartida.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

DataPartida::DataPartida() {}

DataPartida::DataPartida(int id, DataVideojuego videojuego, Fecha fechaInicio, Fecha fechaFin, float DuracionTotal)
{
    this->id = id;
    this->videojuego = videojuego;
    this->fechaInicio = fechaInicio;
    this->fechaInicio = fechaFin;
    this->DuracionTotal = DuracionTotal;
}

int DataPartida::getId()
{
    return this->id;
}

Fecha DataPartida::getFechaInicio()
{
    return this->fechaInicio;
}

Fecha DataPartida::getFechaFin()
{
    return this->fechaFin;
}
DataVideojuego DataPartida::getVideojuego()
{
    return this->videojuego;
}

float DataPartida::getDuracionTotal()
{
    return this->DuracionTotal;
}

DataPartida::~DataPartida(){}

;
