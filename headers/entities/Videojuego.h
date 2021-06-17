#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataVideojuego.h"
#include "Categoria.h"
//#include "Plataforma.h"
//#include "Genero.h"
#include "Jugador.h"
#include "ContextoEstadistica.h"
#include "ContratoSuscripcion.h"

class ContextoEstadistica; //forward declaration
class ContratoSuscripcion; //forward declaration
class Jugador;             //forward declaration

class Videojuego
{
private:
    std::string nombre;
    std::string descripcion;
    map<TipoPeriodoValidez, float> suscripciones;
    //rating.first = promedio
    //rating.second = totalVotos
    pair<float, int> rating;

    //pseudoatributos
    set<ContratoSuscripcion *> contratos;
    map<string, Categoria *> categorias;
    ContextoEstadistica *ctx;
    std::string nombreEmpresa;

public:
    Videojuego();
    Videojuego(std::string nombre,
               std::string descripcion,
               map<TipoPeriodoValidez, float> suscripciones,
               pair<float, int> rating,
               set<ContratoSuscripcion *> contratos,
               map<string, Categoria *> categorias,
               ContextoEstadistica *ctx,
               std::string nombreEmpresa);

    //Getters
    std::string getNombre();
    std::string getDescripcion();
    map<TipoPeriodoValidez, float> getSuscripciones();
    pair<float, int> getRating();
    set<ContratoSuscripcion *> getContratos();
    map<string, Categoria *> getCategorias();
    set<string> getNombreCategorias();
    ContextoEstadistica *getContextoEstadistica();
    map<TipoPeriodoValidez, float> getPeriodoValidez();

    //Setters
    void setNombre(std::string nombre);
    void setDescripcion(std::string desc);
    void setSuscripciones(TipoPeriodoValidez validez, float precio);
    void setRating(float prom, int cantVotos);
    void setContrato(ContratoSuscripcion *);
    void setCategoria(Categoria *);
    void setContextoEstadistica(ContextoEstadistica *);

    //Ops
    //void agregarGenero(Genero g);
    //void agregarPlataforma(Plataforma p);
    void agregarCategoria(Categoria o);
    set<Jugador *> getSuscriptores();
    int getCantidadSuscriptores();
    DataVideojuego *getData();

    ~Videojuego();
};

#endif