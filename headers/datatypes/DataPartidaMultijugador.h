#ifndef DATA_PARTIDA_MULTIJUGADOR_H
#define DATA_PARTIDA_MULTIJUGADOR_H

#include <set>

#include "../datatypes/DataPartida.h"
#include "../datatypes/DataJugador.h"
#include "../utils/Fecha.h"

using namespace std;

class DataPartidaMultijugador : public DataPartida
{
private:
    bool transmitida;
    DataJugador creador;
    set<DataJugador> participantes;

public:
    DataPartidaMultijugador();
    DataPartidaMultijugador(const DataPartidaMultijugador &data);
    DataPartidaMultijugador(int id, DataVideojuego videojuego, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, bool esTransmitida, DataJugador creador, set<DataJugador> participantes);

    bool getTransmitida() const;
    DataJugador getCreador() const;
    set<DataJugador> getParticipantes() const;

    friend bool operator<(const DataPartidaMultijugador &d1, const DataPartidaMultijugador &d2);
    friend bool operator!=(const DataPartidaMultijugador &d1, const DataPartidaMultijugador &d2);

    ~DataPartidaMultijugador();
};

#endif