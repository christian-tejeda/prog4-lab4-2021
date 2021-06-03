#ifndef I_VIDEOJUEGO_CONTROLLER_H
#define I_VIDEOJUEGO_CONTROLLER_H

#include "../datatypes/DataVideojuego.h"
#include "../datatypes/DataContratoSuscripcion.h"

#include <set>

class IVideojuegoController
{ //interface
public:
    virtual void ingresarDatosVideojuego(DataVideojuego DataV) = 0;
    //virtual set<DataCategoria>  obtenerCategorias() = 0;
    virtual void agregarPlataformaAVideojuego(string plataforma) = 0;
    virtual void agregarGeneroAVideojuego(string genero) = 0;
    virtual void agregarOtraCategoriaAVideojuego(string cat) = 0;
    virtual DataVideojuego obtenerDataVideojuegoIngresada() = 0;
    virtual void confirmarPublicacionVideojuego(bool cancelada) = 0;
    virtual set<DataContratoSuscripcion> obtenerSuscripciones() = 0;
    virtual set<DataVideojuego> obtenerVideojuegosPublicadosPorDesarrolladorConPartidasFinalizadas() = 0;
    virtual void seleccionarVideojuego(string nombre) = 0;
    virtual void confirmarEliminarVideojuego(bool confirmar) = 0;
    virtual void puntuarVideojuego(string nombre, int puntaje) = 0;
    virtual set<DataVideojuego> obtenerVideojuegos() = 0;
    virtual DataVideojuego obtenerDataVideojuego(string nombre) = 0;
    //    virtual void agregarPlataforma(DataPlataforma plataforma)= 0;
    //    virtual void agregarGenero(DataGenero genero)= 0;
    //    virtual void agregarOtraCategoria(DataCategoria otra)= 0;
    virtual void confirmarAgregarCategoria(bool confirmar) = 0;

    virtual ~IVideojuegoController() {}
};

#endif