#ifndef VIDEOJUEGO_CONTROLLER_H
#define VIDEOJUEGO_CONTROLLER_H

#include "../interfaces/IAgregarCategoria.h"
#include "../interfaces/IVerInfoVideojuego.h"
#include "../interfaces/IAsignarPuntaje.h"
#include "../interfaces/IEliminarVideojuego.h"
#include "../interfaces/IPublicarVideojuego.h"
#include "../entities/Videojuego.h"

class VideojuegoController : public IAgregarCategoria, public IVerInfoVideojuego, public IAsignarPuntaje, public IEliminarVideojuego, public IPublicarVideojuego
{
private:
    Videojuego *videojuego;
    DataVideojuego dataVideojuego;
    DataCategoria dataCategoria;

public:
    VideojuegoController();

    DataVideojuego getDataVideojuego();

    Videojuego *getVideojuego();

    //IAgregarCategoria
    set<DataCategoria> obtenerCategorias();

    void agregarCategoria(string nombre, string descripcion, TipoCategoria tipoCategoria);

    void confirmarAgregarCategoria();

    //IVerInfoVideojuego
    set<DataVideojuego> obtenerVideojuegos();

    DataVideojuego obtenerDataVideojuego(string nombreVideojuego);

    set<string> obtenerNombreVideojuegos();

    //IAsignarPuntaje
    void puntuarVideojuego(int puntaje);

    //IEliminarVideojuego
    set<DataVideojuego> obtenerVideojuegosPublicadosPorDesarrolladorConPartidasFinalizadas();

    void seleccionarVideojuego(string nombreVideojuego);

    void confirmarEliminarVideojuego();

    //IPublicarVideojuego
    void ingresarDatosVideojuego(DataVideojuego dataVideojuego);

    void agregarCategoriaAVideojuego(string categoria);

    DataVideojuego obtenerDataVideojuegoIngresada();

    void confirmarPublicacionVideojuego();

    void eleminarVideojuegoGeneral();

    ~VideojuegoController();
};

#endif