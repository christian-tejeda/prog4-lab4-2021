#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataUsuario.h"
#include "../datatypes/DataDesarrollador.h"
#include "../entities/Usuario.h"
#include "../entities/Partida.h"
#include "../entities/PartidaIndividual.h"
#include "../entities/PartidaMultijugador.h"
//#include "../entities/ContratoSuscripcion.h"
#include "../entities/Videojuego.h"

using namespace std;

class Desarrollador : public Usuario
{
private:
    string nombreEmpresa;
    set<Videojuego *> juegosPublicados;

public:
    //Constructores
    Jugador();
    Jugador(string nombre, string password, string nickname, string descripcion);
    //Getters
    string getNombre();
    string getPassword();
    string getNombreEmpresa();
    //Setters
    //Operaciones
    //set<ContratoSuscripcion> obtenerSuscripociones(EstadoSuscripcion estado);
    DataDesarrollador getData();
    agregarVideojuegoPublicado(Videojuego *vj);
    ~Usuario();
};

#endif