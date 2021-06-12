
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataPartida.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataPartidaIndividual.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

DataPartidaIndividual::DataPartidaIndividual() {}

DataPartidaIndividual::DataPartidaIndividual(int id, DataVideojuego videojuego, Fecha fechaInicio, Fecha *fechaFin, float DuracionTotal, bool esContinuacion) : DataPartida(id, videojuego, fechaInicio, fechaFin, DuracionTotal)
{
    this->esContinuacion = esContinuacion;
}

bool DataPartidaIndividual::getContinuacion()
{
    return this->esContinuacion;
}

DataPartidaIndividual::~DataPartidaIndividual() {}
