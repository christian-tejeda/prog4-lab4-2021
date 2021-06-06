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
#include "../entities/Videojuego.h"
//#include "../entities/Individual.h"
//#include "../entities/Multijugador.h"
//#include "../entities/ContratoSuscripcion.h"
//#include "../entities/Videojuego.h"

class Desarrollador : public Usuario
{
private:
    std::string nombreEmpresa;
    map<std::string, Videojuego *> publicados;

public:
    //Constructores
    Desarrollador();
    Desarrollador(std::string nombre, std::string password, std::string nombreEmpresa);
    //Getters
    std::string getNombreEmpresa();
    map<std::string, Videojuego *> getJuegosPublicados();
    //Setters
    //Operaciones
    DataUsuario *getData();
    void agregarVideojuegoPublicado(Videojuego *vj);
    ~Desarrollador();
};

#endif