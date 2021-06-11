#ifndef I_CONSULTAR_ESTADISTICAS_H
#define I_CONSULTAR_ESTADISTICAS_H

#include "../datatypes/DataVideojuego.h"
#include "../datatypes/DataEstadistica.h"

class IConsultarEstadisticas
{
public:
    virtual set<DataVideojuego *> obtenerVideojuegosPublicadosPorDesarrollador() = 0;
    virtual set<DataEstadistica *> calcularEstadisticas(string nomVideojuego) = 0;

    virtual ~IConsultarEstadisticas() {}
};

#endif