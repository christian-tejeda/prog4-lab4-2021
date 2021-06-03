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
//#include "../entities/Partida.h"
//#include "../entities/Individual.h"
//#include "../entities/Multijugador.h"
//#include "../entities/ContratoSuscripcion.h"
//#include "../entities/Videojuego.h"

using namespace std;

class Jugador
{
private:
    string nombre;
    string password;
    string nombreEmpresa;
    set<Videojuego> *publicaciones;

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