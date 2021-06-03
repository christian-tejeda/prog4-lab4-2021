#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../enums.h"
#include "../datatypes/DataVideojuego.h"

using namespace std;

class Videojuego
{
private:
    string nombre;
    string descripcion;
    map<TipoPeriodoValidez, float> suscripciones;
    //rating.first = promedio
    //rating.second = totalVotos
    pair<float, int> rating;

    //pseudoatributos
    // set<ContratoSuscripcion*> contratos;
    // set<Categoria *> categorias;
    // ContextoEstadistica* ctx;
public:
    Videojuego();
    Videojuego(string nombre,
               string descripcion,
               map<TipoPeriodoValidez, float> suscripciones,
               pair<float, int> rating /*, 
                   set<ContratoSuscripcion*> contratos, 
                   set<Categoria *> categorias, 
                   ContextoEstadistica* ctx */
    );

    //Getters
    string getNombre();
    string getDescripcion();
    map<TipoPeriodoValidez, float> getSuscripciones();
    pair<float, int> getRating();
    // set<ContratoSuscripcion *> getContratos();
    // set<Categoria *> getCategorias();
    // ContextoEstadistica * getContextoEstadistica();

    //Setters
    void setNombre(string nombre);
    void setDescripcion(string desc);
    void setSuscripciones(TipoPeriodoValidez validez, float precio);
    void setRating(float prom, int cantVotos);
    // void setContrato(ContratoSuscripcion *);
    // void setCategoria(Categoria *);
    // void setContextoEstadistica(ContextoEstadistica *);

    //Ops
    // void agregarGenero(Genero g);
    // void agregarPlataforma(Plataforma p);
    // void agregarOtraCategoria(Categoria o);
    // set<Jugador*> getSuscriptores();
    int getCantidadSuscriptores();
    DataVideojuego getData();

    ~Videojuego();
};

#endif