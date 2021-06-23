#include "../../headers/datatypes/DataPartidaMultijugador.h"

using namespace std;

DataPartidaMultijugador::DataPartidaMultijugador() {}

DataPartidaMultijugador::DataPartidaMultijugador(const DataPartidaMultijugador &data) : DataPartida(data)
{
    transmitida = data.transmitida;
    creador = data.creador;
    participantes = data.participantes;
}

DataPartidaMultijugador::DataPartidaMultijugador(int id, DataVideojuego dataVideojuego, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, bool trasmitida, DataJugador creador, set<DataJugador> participantes) : DataPartida(id, dataVideojuego, fechaInicio, fechaFin, duracionTotal)
{
    trasmitida = trasmitida;
    creador = creador;
    participantes = participantes;
}

bool DataPartidaMultijugador::getTransmitida() const { return transmitida; }

DataJugador DataPartidaMultijugador::getCreador() const { return creador; }

set<DataJugador> DataPartidaMultijugador::getParticipantes() const { return participantes; }

bool operator<(const DataPartidaMultijugador &d1, const DataPartidaMultijugador &d2)
{
    return &d1 < &d2;
}

bool operator!=(const DataPartidaMultijugador &d1, const DataPartidaMultijugador &d2)
{
    return d1.getId() != d2.getId() || d1.getFechaInicio() != d2.getFechaInicio() || d1.getFechaFin() != d2.getFechaFin() || d1.getDuracionTotal() != d2.getDuracionTotal() || d1.getDataVideojuego() != d2.getDataVideojuego() || d1.getCreador() != d2.getCreador() || d1.getTransmitida() != d2.getTransmitida() || d1.getParticipantes() != d2.getParticipantes();
}

DataPartidaMultijugador::~DataPartidaMultijugador() {}
