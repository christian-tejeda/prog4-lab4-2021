#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H

#include <map>
#include <set>
#include <string>

#include "../entities/Usuario.h"
#include "../entities/Videojuego.h"
#include "../utils/enums.h"
#include "../datatypes/DataDesarrollador.h"

class Desarrollador : public Usuario
{
private:
  string nombreEmpresa;
  map<string, Videojuego *> publicaciones;
  set<TipoEstadistica> estadisticasDeInteres;

public:
  Desarrollador();
  Desarrollador(string email, string password, string nombreEmpresa);

  string getNombreEmpresa();
  set<TipoEstadistica> getEstadisticasDeInteres();

  void setEmail(string email);
  void setPassword(string password);
  void setNombreEmpresa(string nombreEmpresa);

  void agregarVideojuegoPublicado(Videojuego *videojuego);
  set<Videojuego *> getVideojuegoPublicados();
  void eliminarVideojuegoPublicado(Videojuego *videojuego);
  void agregarEstadisticaDeInteres(TipoEstadistica estadistica);
  void removerEstadisticaDeInteres(TipoEstadistica estadistica);

  DataDesarrollador getData();

  ~Desarrollador();
};

#endif