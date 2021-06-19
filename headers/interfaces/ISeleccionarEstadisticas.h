#ifndef I_SELECCIONAR_ESTADISTICAS_H
#define I_SELECCIONAR_ESTADISTICAS_H

#include <string>
#include <set>
#include "../datatypes/DataEstadistica.h"

class ISeleccionarEstadisticas
{
public:
    virtual std::set<DataEstadistica *> listarEstadisticas() = 0;
    virtual void seleccionarEstadisticas(set<int> numeroEstadistica) = 0;

    virtual ~ISeleccionarEstadisticas(){};
};

#endif