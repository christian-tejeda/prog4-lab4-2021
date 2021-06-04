#ifndef DURACION_PARTICIPANTE_H
#define DURACION_PARTICIPANTE_H

#include "../utils/Fecha.h"
#include "../entities/Jugador.h"

class DuracionParticipante
{
private:
    Fecha horaEntrada;
    Fecha horaSalida;
    Jugador *participante;

public:
    DuracionParticipante();
    DuracionParticipante(Fecha &he, Fecha &hs, Jugador *jg);

    //Getters
    Fecha getHoraEntrada();
    Fecha getHoraSalida();
    Jugador *getParticipante();

    //Setters
    void setHoraEntrada(Fecha &f);
    void setHoraSalida(Fecha &f);
    void setParticipante(Jugador *prt);

    void terminarParticipacion(Fecha &f);

    ~DuracionParticipante();
};

#endif