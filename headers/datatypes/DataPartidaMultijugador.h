#ifndef DATA_PARTIDA_MULTIJUGADOR_H
#define DATA_PARTIDA_MULTIJUGADOR_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataPartida.h"
#include "../datatypes/DataVideojuego.h"
#include "../utils/Fecha.h"

using namespace std;

class DataPartidaMultijugador : public DataPartida
{
private:
    bool trasmitida;
    //DataJugador creador; //PREGUNTAR!
    //Set<DataJugador> participantes;//PREGUNTAR!

public:
    DataPartidaMultijugador();
    DataPartidaMultijugador(int id, DataVideojuego videojuego, Fecha fechaInicio, Fecha fechaFin, float DuracionTotal);
    //Getters
    int getId();
    DataVideojuego getVideojuego();
    Fecha getFechaInicio();
    Fecha getFechaFin();
    float getDuracionTotal();
    bool getTramistida();
    //DataJugador getCreador();
    //set<DataJugador> getParticipantes();

    //Setters

    //Destructor
    ~DataPartidaMultijugador();
};

#endif