
#include <map>
#include <set>
#include <string>
#include <utility>

#include "../../headers/entities/Desarrollador.h"
//#include "../../headers/entities/Usuario.h"
//#include "../../headers/utils/enums.h"
//#include "../../headers/datatypes/DataUsuario.h"
//#include "../../headers/datatypes/DataDesarrollador.h"
#include "../../headers/utils/Fecha.h"

Desarrollador::Desarrollador() : Usuario(){};

Desarrollador::Desarrollador(std::string email, std::string password,
                             std::string nombreEmpresa)
    : Usuario(email, password) {
  this->nombreEmpresa = nombreEmpresa;
  this->estadisticasDeInteres = std::set<TipoEstadistica>();
}

// Getters
string Desarrollador::getNombreEmpresa() { return this->nombreEmpresa; }

// Setters
void Desarrollador::setNombreEmpresa(std::string nomEmpresa) {
  this->nombreEmpresa = nomEmpresa;
}

// Operaciones

DataUsuario *Desarrollador::getData() {
    return new DataDesarrollador(this->getEmail(), this->getPassword(), this->getNombreEmpresa());
}

std::set<TipoEstadistica> Desarrollador::getEstadisticasDeInteres() {
  return this->estadisticasDeInteres;
}

void Desarrollador::agregarEstadisticaDeInteres(TipoEstadistica estadistica) {
  this->estadisticasDeInteres.insert(estadistica);
}

void Desarrollador::removerEstadisticaDeInteres(TipoEstadistica estadistica) {
  std::set<TipoEstadistica>::iterator it;

  bool removido = false;
  std::set<TipoEstadistica> estadisticas = this->estadisticasDeInteres;
  for (it = estadisticas.begin(); it != estadisticas.end(); it++) {
    TipoEstadistica tipoEs = (*it);

    if (tipoEs == estadistica) {
      this->estadisticasDeInteres.erase(it);
      removido = true;
    }
  }
}

void Desarrollador::agregarVideojuegoPublicado(Videojuego *vj) {}

set<Videojuego *> Desarrollador::getVideojuegoPublicados() {
  map<string, Videojuego *> vjs = this->publicaciones;
  map<string, Videojuego *>::iterator it;
  set<Videojuego *> res;
  for (it = vjs.begin(); it != vjs.end(); it++) {
    Videojuego *video = it->second;
    res.insert(video);
  }
  return res;
}

void Desarrollador::eliminarVideojuegoPublicado(Videojuego *vj) {
  this->publicaciones.erase(vj->getNombre());
}

Desarrollador::~Desarrollador(){};
