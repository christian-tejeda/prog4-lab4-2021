#ifndef INTERFAZ_ESTADISTICA_H
#define INTERFAZ_ESTADISTICA_H

class InterfazEstadistica {
    public:
        InterfazEstadistica();
        virtual float calcularEstadistica(Videojuego vj) = 0;
        ~InterfazEstadistica();
};

#endif
