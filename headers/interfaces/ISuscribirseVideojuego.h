#ifndef I_SUSCRIBIRSE_VIDEOJUEGO_H
#define I_SUSCRIBIRSE_VIDEOJUEGO_H

#include <set>
#include "../datatypes/DataContratoSuscripcion.h"

class ISuscribirseVideojuego
{
public:
    virtual set<DataContratoSuscripcion *> obtenerSuscripciones() = 0;
    virtual void seleccionarVideojuego(string nombreVideojuego) = 0;
    virtual void cancelarSuscripcion(bool cancelada) = 0;
    virtual void contratarSuscripcion(pair<TipoPeriodoValidez, float> suscripcion, TipoMetodoPago m) = 0;
    virtual void confirmarSuscripcion(bool confirmar) = 0;

    virtual ~ISuscribirseVideojuego() {}
};

#endif