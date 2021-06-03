#ifndef INTERFAZ_ESTADISTICA_H
#define INTERFAZ_ESTADISTICA_H

class InterfazEstadistica {
    public:
        InterfazEstadistica();
        virtual float calcularEstadistica(Videojuego vj); // no puede ser virtual pura si es un paránetro del contexto?
        ~InterfazEstadistica();
};

class CantidadSuscritos: public InterfazEstadistica {
    public:
        float calcularEstadistica(Videojuego vj);
};

class TotalHorasJugadas: public InterfazEstadistica {
    public:
        float calcularEstadistica(Videojuego vj);
};

class PromedioRating: public InterfazEstadistica {
    public:
        float calcularEstadistica(Videojuego vj);
};

#endif
