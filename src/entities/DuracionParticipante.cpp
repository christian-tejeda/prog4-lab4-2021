
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
DuracionParticipante::DuracionParticipante(Fecha *he, Fecha *hs, Jugador *jg)
{
    this->horaEntrada = new Fecha(he->getDia(), he->getMes(), he->getAnio(), he->getHora(), he->getMinuto());
    this->horaSalida = hs;
    this->participante = jg;
}

//Getters
Fecha *DuracionParticipante::getHoraEntrada()
{
    return this->horaEntrada;
}
Fecha *DuracionParticipante::getHoraSalida()
{
    return this->horaSalida;
}
Jugador *DuracionParticipante::getParticipante()
{
    return this->participante;
}
//Setters
void DuracionParticipante::setHoraEntrada(Fecha *f)
{
    this->horaEntrada = f;
}
void DuracionParticipante::setHoraSalida(Fecha *f)
{
    this->horaSalida = f;
}
void DuracionParticipante::setParticipante(Jugador *prt)
{
    this->participante = prt;
}
void DuracionParticipante::terminarParticipacion(Fecha *f)
{
    this->horaSalida = f;
}
DuracionParticipante::~DuracionParticipante()
{
    this->participante = nullptr;
    delete this->horaEntrada;
    delete this->horaSalida;
}
float DuracionParticipante::calcularDuracion()
{
    return *this->horaSalida - *this->horaEntrada;
}
//DuracionParticipante::~DuracionParticipante() {}
