#ifndef CONTEXTO_ESTADISTICA_H
#define CONTEXTO_ESTADISTICA_H

#include "../interfaces/InterfazEstadistica.h"

class ContextoEstadistica {
    private:
        InterfazEstadistica estrategia;

    public:
        ContextoEstadistica();
        ContextoEstadistica(InterfazEstadistica est); // constructor con estrategia por paránmetro
        void setEstadistica(InterfazEstadistica est);  // <- this.estrategia = est
        float consultarEstadistica(Videojuego vj);
        ~ContextoEstadistica();
};

#endif