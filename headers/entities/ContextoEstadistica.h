#ifndef CONTEXTO_ESTADISTICA_H
#define CONTEXTO_ESTADISTICA_H

#include "../interfaces/InterfazEstadistica.h"

class ContextoEstadistica {
    private:
        InterfazEstadistica estrategia;

    public: 
        void setEstadistica(InterfazEstadistica est);  // <- this.estrategia = est
        float consultarEstadistica(Videojuego vj);
};

#endif