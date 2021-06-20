#ifndef I_PUBLICAR_VIDEOJUEGO_H
#define I_PUBLICAR_VIDEOJUEGO_H

#include "../datatypes/DataVideojuego.h"
#include "../datatypes/DataCategoria.h"

class IPublicarVideojuego
{
public:
    virtual void ingresarDatosVideojuego(DataVideojuego *DataV) = 0;
    virtual set<DataCategoria *> obtenerCategorias() = 0;
    // virtual void agregarPlataformaAVideojuego(string plataforma) = 0;
    // virtual void agregarGeneroAVideojuego(string genero) = 0;
    // virtual void agregarOtraCategoriaAVideojuego(string cat) = 0;
    virtual void agregarCategoriaAVideojuego(string cat) = 0;
    virtual void obtenerDataVideojuegoIngresada() = 0;
    virtual void confirmarPublicacionVideojuego(bool confirmar) = 0;

    virtual ~IPublicarVideojuego(){};
};

#endif