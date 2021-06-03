#ifndef INTERFAZ_ESTADISTICA_H
#define INTERFAZ_ESTADISTICA_H

class InterfazEstadistica {
    public:
        InterfazEstadistica();
        virtual float calcularEstadistica(Videojuego vj); // no puede ser virtual pura si es un paránetro del contexto?
        ~InterfazEstadistica();
};

#endif
