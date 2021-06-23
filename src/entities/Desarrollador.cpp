
#include <map>
#include <set>
#include <string>
#include <utility>

#include "../../headers/entities/Desarrollador.h"
#include "../../headers/datatypes/DataDesarrollador.h"

Desarrollador::Desarrollador() : Usuario(){};

Desarrollador::Desarrollador(string email, string password, string nombreEmpresa) : Usuario(email, password)
{
  this->nombreEmpresa = nombreEmpresa;
  this->estadisticasDeInteres = set<TipoEstadistica>();
}

string Desarrollador::getNombreEmpresa() { return this->nombreEmpresa; }

void Desarrollador::setNombreEmpresa(string nombreEmpresa) { this->nombreEmpresa = nombreEmpresa; }

DataDesarrollador Desarrollador::getData() { return DataDesarrollador(this->getEmail(), this->getPassword(), this->getNombreEmpresa()); }

set<TipoEstadistica> Desarrollador::getEstadisticasDeInteres() { return this->estadisticasDeInteres; }

void Desarrollador::agregarEstadisticaDeInteres(TipoEstadistica estadistica) { this->estadisticasDeInteres.insert(estadistica); }

void Desarrollador::removerEstadisticaDeInteres(TipoEstadistica estadistica)
{
  bool removido = false;
  set<TipoEstadistica>::iterator it;
  set<TipoEstadistica> estadisticas = this->estadisticasDeInteres;

  for (it = estadisticas.begin(); it != estadisticas.end(); it++)
  {
    TipoEstadistica tipoEs = (*it);

    if (tipoEs == estadistica)
    {
      this->estadisticasDeInteres.erase(it);
      removido = true;
    }
  }
}

void Desarrollador::agregarVideojuegoPublicado(Videojuego *videojuego)
{
  this->publicaciones.insert(pair<string, Videojuego *>(videojuego->getNombre(), videojuego));
}

set<Videojuego *> Desarrollador::getVideojuegoPublicados()
{
  map<string, Videojuego *> videojuegosPublicados = this->publicaciones;

  map<string, Videojuego *>::iterator it;
  set<Videojuego *> res;
  for (it = videojuegosPublicados.begin(); it != videojuegosPublicados.end(); it++)
  {
    Videojuego *videojuego = it->second;
    res.insert(videojuego);
  }

  return res;
}

void Desarrollador::eliminarVideojuegoPublicado(Videojuego *videojuego)
{
  map<string, Videojuego *>::iterator it;
  it = this->publicaciones.find(videojuego->getNombre());
  this->publicaciones.erase(it);
}

Desarrollador::~Desarrollador(){};
