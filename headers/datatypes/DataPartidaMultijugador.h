#ifndef DATA_PARTIDA_MULTIJUGADOR_H
#define DATA_PARTIDA_MULTIJUGADOR_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../enums.h"
#include "../datatypes/DataPartida.h"
#include "../datatypes/DataVideojuego.h"

using namespace std;

class DataPartidaMultijugador : public DataPartida
{
private:
    bool trasmitida;
    //DataJugador creador; //PREGUNTAR!
    //Set<DataJugador> participantes;//PREGUNTAR!

public:
    DataPartidaMultijugador();
    DataPartidaMultijugador(int id, DataVideojuego videojuego, DataFecha fechaInicio, DataFecha fechaFin, float DuracionTotal);
    //Getters
    int getId() const;
    DataVideojuego getVideojuego() conts;
    //DataFecha getFechaInicio();
    //DataFecha getFechaFin();
    float getDuracionTotal();
    bool getTramistida();
    DataJugador getCreador();
    set<DataJugador> getParticipantes();

    //Setters

    //Destructor
    ~DataPartidaMultijugador();
};

#endif