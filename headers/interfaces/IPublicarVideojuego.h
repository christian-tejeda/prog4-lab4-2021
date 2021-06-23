#ifndef I_PUBLICAR_VIDEOJUEGO_H
#define I_PUBLICAR_VIDEOJUEGO_H

#include "../datatypes/DataVideojuego.h"
#include "../datatypes/DataCategoria.h"

class IPublicarVideojuego
{
public:
    virtual void ingresarDatosVideojuego(DataVideojuego data) = 0;

    virtual set<DataCategoria> obtenerCategorias() = 0;

    virtual void agregarCategoriaAVideojuego(string categoria) = 0;

    virtual DataVideojuego obtenerDataVideojuegoIngresada() = 0;

    virtual void confirmarPublicacionVideojuego() = 0;

    virtual ~IPublicarVideojuego(){};
};

#endif