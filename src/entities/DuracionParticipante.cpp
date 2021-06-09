
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/DuracionParticipante.h"
#include "../../headers/entities/Usuario.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataUsuario.h"
#include "../../headers/datatypes/DataDesarrollador.h"
#include "../../headers/utils/Fecha.h"

DuracionParticipante::DuracionParticipante() {}
DuracionParticipante::DuracionParticipante(Fecha &he, Fecha &hs, Jugador *jg)
{
    this->horaEntrada = he;
    this->horaSalida = hs;
    this->participante = jg;
}

//Getters
Fecha DuracionParticipante::getHoraEntrada()
{
    return this->horaEntrada;
}
Fecha DuracionParticipante::getHoraSalida()
{
    return this->horaSalida;
}
Jugador *DuracionParticipante::getParticipante()
{
    return this->participante;
}
<<<<<<< HEAD
=======

>>>>>>> 8a39bfa4d07de9d894115350d93fb7458ed8fcf0
//Setters
void DuracionParticipante::setHoraEntrada(Fecha &f)
{
    this->horaEntrada = f;
}
void DuracionParticipante::setHoraSalida(Fecha &f)
{
    this->horaSalida = f;
}
void DuracionParticipante::setParticipante(Jugador *prt)
{
    this->participante = prt;
}
<<<<<<< HEAD
=======

>>>>>>> 8a39bfa4d07de9d894115350d93fb7458ed8fcf0
void DuracionParticipante::terminarParticipacion(Fecha &f)
{
    this->horaSalida = f;
}
<<<<<<< HEAD
=======

>>>>>>> 8a39bfa4d07de9d894115350d93fb7458ed8fcf0
DuracionParticipante::~DuracionParticipante() {}
