
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataPartida.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataPartidaMultijugador.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

DataPartidaMultijugador::DataPartidaMultijugador() {}

DataPartidaMultijugador::DataPartidaMultijugador(int id, DataVideojuego * videojuego, Fecha fechaInicio, Fecha *fechaFin, float DuracionTotal, bool esTrasmitida, DataJugador creador, set<DataJugador *> participantes) : DataPartida(id, videojuego, fechaInicio, fechaFin, DuracionTotal)
{
    this->trasmitida = esTrasmitida;
    this->creador = creador;
    this->participantes = participantes;
}

bool DataPartidaMultijugador::getTramistida()
{
    return this->trasmitida;
}
DataJugador DataPartidaMultijugador::getCreador()
{
    return this->creador;
}

set<DataJugador *> DataPartidaMultijugador::getParticipantes()
{
    return this->participantes;
}

DataPartidaMultijugador::~DataPartidaMultijugador() {}
