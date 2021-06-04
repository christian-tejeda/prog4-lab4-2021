#ifndef VIDEOJUEGO_CONTROLLER_H
#define VIDEOJUEGO_CONTROLLER_H

#include "../interfaces/IVideojuegoController.h"
#include "../entities/Videojuego.h"

class VideojuegoController : public IVideojuegoController
{ //singleton
private:
    VideojuegoController *instancia;

    DataVideojuego *dataVideojuego; //se borra la instancia al terminar el CU
    Videojuego *videojuego;         //se borra la referencia

public:
    VideojuegoController();
    //op de singleton
    static VideojuegoController *getInstance();
    //Getters
    DataVideojuego *getDataVideojuego();
    Videojuego *getVideojuego();
    //ops del interface
    void ingresarDatosVideojuego(DataVideojuego *DataV);
    set<DataCategoria *> obtenerCategorias();
    void agregarPlataformaAVideojuego(string plataforma);
    void agregarGeneroAVideojuego(string genero);
    void agregarOtraCategoriaAVideojuego(string cat);
    DataVideojuego *obtenerDataVideojuegoIngresada();
    void confirmarPublicacionVideojuego(bool cancelada);
    set<DataContratoSuscripcion *> obtenerSuscripciones();
    set<DataVideojuego *> obtenerVideojuegosPublicadosPorDesarrolladorConPartidasFinalizadas();
    void seleccionarVideojuego(string nombre);
    void confirmarEliminarVideojuego(bool confirmar);
    void puntuarVideojuego(string nombre, int puntaje);
    set<DataVideojuego *> obtenerVideojuegos();
    DataVideojuego *obtenerDataVideojuego(string nombre);
    void agregarPlataforma(DataPlataforma *plataforma);
    void agregarGenero(DataGenero *genero);
    void agregarOtraCategoria(DataCategoria *otra);
    void confirmarAgregarCategoria(bool confirmar);

    ~VideojuegoController();
};

#endif