#ifndef DURACION_PARTICIPANTE_H
#define DURACION_PARTICIPANTE_H

#include "../utils/Fecha.h"
#include "../entities/Jugador.h"

class Jugador;

class DuracionParticipante
{
private:
    Fecha entrada;
    Fecha salida;
    Jugador *participante;

public:
    DuracionParticipante();
    DuracionParticipante(Fecha fechaEntrada, Fecha fechaSalida, Jugador *participante);

    Fecha getHoraEntrada();
    Fecha getHoraSalida();
    Jugador *getParticipante();

    void setHoraEntrada(Fecha fechaEntrada);
    void setHoraSalida(Fecha fechaSalida);
    void setParticipante(Jugador *participante);

    void terminarParticipacion(Fecha fecha);
    float calcularDuracion();

    ~DuracionParticipante();
};

#endif