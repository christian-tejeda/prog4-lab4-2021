#ifndef DATA_ESTADISTICA_H
#define DATA_ESTADISTICA_H

#include <string>

#include "../enums.h"

class DataEstadistica {
    private:
        std::string nombre;
        std::string descripcion;
        float valor;

    public:
        DataEstadistica();
        TipoEstadisticaVideojuego getEstadistica();
        float getResultado();
        ~DataEstadistica();
}

#endif