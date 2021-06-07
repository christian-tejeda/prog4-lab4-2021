#include "../../headers/entities/ContextoEstadistica.h"
#include "../../headers/utils/enums.h"

ContextoEstadistica::ContextoEstadistica(){
    this->estrategia = nullptr;
}

ContextoEstadistica::ContextoEstadistica(InterfazEstadistica *est) { // revisar sobre punteros
    this->estrategia = est;
}

void ContextoEstadistica::setEstadistica(InterfazEstadistica *est) { // borrar la anterior? puede perder memoria
    this->estrategia = est;
}

float ContextoEstadistica::consultarEstadistica(Videojuego *vj) {
    return 0;
}

ContextoEstadistica::~ContextoEstadistica() { }