#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H

#include <map>
#include <set>
#include <string>
#include <utility>

#include "../datatypes/DataDesarrollador.h"
#include "../datatypes/DataUsuario.h"
#include "../entities/Usuario.h"
#include "../entities/Videojuego.h"
#include "../utils/enums.h"
//#include "../entities/Individual.h"
//#include "../entities/Multijugador.h"
//#include "../entities/ContratoSuscripcion.h"
#include "../entities/Videojuego.h"

// using namespace std;

class Desarrollador : public Usuario {
private:
  std::string nombreEmpresa;
  map<string, Videojuego *> publicaciones;
  std::set<TipoEstadistica> estadisticasDeInteres;

public:
  // Constructores
  Desarrollador();
  Desarrollador(std::string email, std::string password,
                std::string nombreEmpresa);

  // Getters
  std::string getNombreEmpresa();
  std::set<TipoEstadistica> getEstadisticasDeInteres();

  // Setters
  void setEmail(std::string email);
  void setPassword(std::string password);
  void setNombreEmpresa(std::string nomEmpresa);

  // Operaciones
  DataUsuario *getData();
  void agregarVideojuegoPublicado(Videojuego *vj);
  set<Videojuego *> getVideojuegoPublicados();
  void eliminarVideojuegoPublicado(Videojuego *vj);
  void agregarEstadisticaDeInteres(TipoEstadistica estadistica);
  void removerEstadisticaDeInteres(TipoEstadistica estadistica);

  ~Desarrollador();
};

#endif