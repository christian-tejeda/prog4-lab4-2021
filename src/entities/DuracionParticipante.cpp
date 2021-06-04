#include "../../headers/entities/DuracionParticipante.h"
#include <string>

DuracionParticipante::DuracionParticipante(){}
//Getters
DuracionParticipante::DuracionParticipante(Fecha &he,Fecha &hs,Jugador* jg){}
Fecha DuracionParticipante::getHoraEntrada(){}
Fecha DuracionParticipante::getHoraSalida(){}
Jugador* DuracionParticipante::getParticipante(){}
//Setters
void DuracionParticipante::setHoraEntrada(Fecha &f){}
void DuracionParticipante::setHoraSalida(Fecha &f){}
void DuracionParticipante::setParticipante(Jugador* prt){}
void DuracionParticipante::terminarParticipacion(Fecha &f){}

DuracionParticipante::~DuracionParticipante(){}