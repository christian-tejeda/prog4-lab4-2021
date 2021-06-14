#ifndef VIDEOJUEGO_CONTROLLER_H
#define VIDEOJUEGO_CONTROLLER_H

#include "../interfaces/IAgregarCategoria.h"
#include "../interfaces/IVerInfoVideojuego.h"
#include "../interfaces/IAsignarPuntaje.h"
#include "../interfaces/IEliminarVideojuego.h"
#include "../interfaces/IPublicarVideojuego.h"
#include "../entities/Videojuego.h"

class VideojuegoController : public IAgregarCategoria, public IVerInfoVideojuego, public IAsignarPuntaje, public IEliminarVideojuego, public IPublicarVideojuego
{ //singleton
private:
    DataVideojuego *dataVideojuego; //se borra la instancia al terminar el CU
    Videojuego *videojuego;         //se borra la referencia

public:
    VideojuegoController();

    //Getters
    DataVideojuego *getDataVideojuego();
    Videojuego *getVideojuego();

    //ops de IAgregarCategoria
    set<DataCategoria *> obtenerCategorias();
    void agregarPlataforma(DataPlataforma *plataforma);
    void agregarGenero(DataGenero *genero);
    void agregarOtraCategoria(DataCategoria *otra);
    void confirmarAgregarCategoria(bool confirmar);

    //ops de IVerInfoVideojuego
    set<DataVideojuego *> obtenerVideojuegos();
    DataVideojuego *obtenerDataVideojuego(string nombre);

    //ops de IAsignarPuntaje
    void puntuarVideojuego(string nombre, int puntaje);

    //ops de IEliminarVideojuego
    set<DataVideojuego *> obtenerVideojuegosPublicadosPorDesarrolladorConPartidasFinalizadas();
    void seleccionarVideojuego(string nombre);
    void confirmarEliminarVideojuego(bool confirmar);

    //ops de IPublicarVideojuego
    void ingresarDatosVideojuego(DataVideojuego *DataV);
    //set<DataCategoria *> obtenerCategorias();
    void agregarPlataformaAVideojuego(string plataforma);
    void agregarGeneroAVideojuego(string genero);
    void agregarOtraCategoriaAVideojuego(string cat);
    DataVideojuego *obtenerDataVideojuegoIngresada();
    void confirmarPublicacionVideojuego(bool cancelada);

    ~VideojuegoController();
};

#endif