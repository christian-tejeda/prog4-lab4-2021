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
    Desarrollador();
    Desarrollador(string nombre, string password, string nomEmpresa);
    //Getters
    string getNombreEmpresa();
    //Setters
    void setNombreEmpresa(string nomEmpresa);
    //Operaciones
    //set<ContratoSuscripcion> obtenerSuscripociones(EstadoSuscripcion estado);
    DataUsuario *getData();
    void agregarVideojuegoPublicado(Videojuego *vj);
    ~Desarrollador();
};

#endif