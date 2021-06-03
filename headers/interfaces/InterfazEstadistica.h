#ifndef INTERFAZ_ESTADISTICA_H
#define INTERFAZ_ESTADISTICA_H

class InterfazEstadistica {
    public:
        InterfazEstadistica();
        virtual float calcularEstadistica(Videojuego vj) = 0; // no puede ser virtual pura si es un paránetro del contexto?
        virtual ~InterfazEstadistica();
};

class CantidadSuscritos: public InterfazEstadistica {
    public:
        float calcularEstadistica(Videojuego vj) override;
};

class TotalHorasJugadas: public InterfazEstadistica {
    public:
        float calcularEstadistica(Videojuego vj) override;
};

class PromedioRating: public InterfazEstadistica {
    public:
        float calcularEstadistica(Videojuego vj) override;
};

#endif
