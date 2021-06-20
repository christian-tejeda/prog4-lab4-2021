#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <map>
#include <set>
#include <string>
#include <utility>

#include "../datatypes/DataVideojuego.h"
#include "../utils/enums.h"
#include "Categoria.h"
#include "Jugador.h"

class ContratoSuscripcion;
class Jugador;

class Videojuego
{
private:
  std::string nombre;
  std::string descripcion;
  map<TipoPeriodoValidez, float> suscripciones;
  pair<float, int> rating;

  set<ContratoSuscripcion *> contratos;
  map<string, Categoria *> categorias;
  std::string nombreEmpresa;

public:
  Videojuego();
  Videojuego(std::string nombre, std::string descripcion,
             map<TipoPeriodoValidez, float> suscripciones,
             pair<float, int> rating, set<ContratoSuscripcion *> contratos,
             map<string, Categoria *> categorias, std::string nombreEmpresa);

  // Getters
  std::string getNombre();
  std::string getDescripcion();
  map<TipoPeriodoValidez, float> getSuscripciones();
  pair<float, int> getRating();
  set<ContratoSuscripcion *> getContratos();
  map<string, Categoria *> getCategorias();
  set<string> getNombreCategorias();
  map<TipoPeriodoValidez, float> getPeriodoValidez();
  std::string getNombreEmpresa();

  void setNombre(std::string nombre);
  void setDescripcion(std::string desc);
  void setSuscripciones(TipoPeriodoValidez validez, float precio);
  void setRating(float prom, int cantVotos);
  void setContrato(ContratoSuscripcion *);
  void setCategoria(Categoria *cat);

  void agregarCategoria(Categoria o);
  set<Jugador *> getSuscriptores();
  int getCantidadSuscriptores();
  void agregarPuntaje(float puntaje);
  DataVideojuego *getData();

  float calcularEstadistica(TipoEstadistica tipoEstadistica);

  ~Videojuego();
};

#endif