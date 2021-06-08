<<<<<<< HEAD
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
=======

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

DuracionParticipante::DuracionParticipante(){}
DuracionParticipante::DuracionParticipante(Fecha &he, Fecha &hs, Jugador *jg){
        this->horaEntrada=he;
        this->horaSalida=hs;
        this->participante=jg;
    }

    //Getters
    Fecha DuracionParticipante::getHoraEntrada(){
        return this->horaEntrada;
    }
    Fecha DuracionParticipante::getHoraSalida(){
        return this->horaSalida;
    }
    Jugador * DuracionParticipante::getParticipante(){
        return this->participante;
    }

    //Setters
    void DuracionParticipante::setHoraEntrada(Fecha &f){
        this->horaEntrada=f;
    }
    void DuracionParticipante::setHoraSalida(Fecha &f){
        this->horaSalida=f;
    }
    void DuracionParticipante::setParticipante(Jugador *prt){
        this->participante=prt;
    }

    void DuracionParticipante::terminarParticipacion(Fecha &f){
        this->horaSalida=f;
    }

    DuracionParticipante::~DuracionParticipante(){}
>>>>>>> 40f0bf4582fe2e3b8754ed27b995905bae6f1e0e
