#ifndef I_SELECCIONAR_ESTADISTICAS_H
#define I_SELECCIONAR_ESTADISTICAS_H

#include <set>

#include "../datatypes/DataEstadistica.h"

class ISeleccionarEstadisticas
{
public:
    virtual set<DataEstadistica> obtenerEstadisticas() = 0;

    virtual void seleccionarEstadisticas(set<TipoEstadistica> tipoEstadisticas) = 0;

    virtual ~ISeleccionarEstadisticas(){};
};

#endif