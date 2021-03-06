#ifndef DATA_PARTIDA_MULTIJUGADOR_H
#define DATA_PARTIDA_MULTIJUGADOR_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataPartida.h"
#include "../datatypes/DataJugador.h"
#include "../utils/Fecha.h"

using namespace std;

class DataPartidaMultijugador : public DataPartida
{
private:
    bool trasmitida;
    DataJugador creador;              //PREGUNTAR!
    set<DataJugador *> participantes; //PREGUNTAR!

public:
    DataPartidaMultijugador();
    DataPartidaMultijugador(int id, DataVideojuego * videojuego, Fecha fechaInicio, Fecha *fechaFin, float DuracionTotal, bool esTrasmitida, DataJugador creador, set<DataJugador *> participantes);
    //Getters
    //int getId();
    //DataVideojuego getVideojuego();
    //Fecha getFechaInicio();
    //Fecha getFechaFin();
    //float getDuracionTotal();
    bool getTramistida();
    DataJugador getCreador();
    set<DataJugador *> getParticipantes();

    //Setters

    //Destructor
    ~DataPartidaMultijugador();
};

#endif