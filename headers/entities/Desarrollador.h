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
#include "../entities/Videojuego.h"

//using namespace std;

class Desarrollador : public Usuario
{
private:
    std::string nombreEmpresa;
    map<string, Videojuego *> publicaciones;

public:
    //Constructores
    Desarrollador();
    Desarrollador(std::string email, std::string password, std::string nombreEmpresa);

    //Getters
    std::string getNombreEmpresa();

    //Setters
    void setEmail(std::string email);
    void setPassword(std::string password);
    void setNombreEmpresa(std::string nomEmpresa);

    //Operaciones
    DataUsuario *getData();
    void agregarVideojuegoPublicado(Videojuego *vj);
    set<Videojuego*> getVideojuegoPublicados();

    ~Desarrollador();
};

#endif