
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

DuracionParticipante::DuracionParticipante(Fecha entrada, Fecha salida, Jugador *participante)
{
    this->entrada = entrada;
    this->salida = salida;
    this->participante = participante;
}

Fecha DuracionParticipante::getHoraEntrada() { return this->entrada; }

Fecha DuracionParticipante::getHoraSalida() { return this->salida; }

Jugador *DuracionParticipante::getParticipante() { return this->participante; }

void DuracionParticipante::setHoraEntrada(Fecha entrada) { this->entrada = entrada; }

void DuracionParticipante::setHoraSalida(Fecha salida) { this->salida = salida; }

void DuracionParticipante::setParticipante(Jugador *participante) { this->participante = participante; }

void DuracionParticipante::terminarParticipacion(Fecha fecha) { this->salida = fecha; }

DuracionParticipante::~DuracionParticipante() { this->participante = nullptr; }

float DuracionParticipante::calcularDuracion() { return this->salida - this->entrada; }
