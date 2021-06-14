
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Desarrollador.h"
//#include "../../headers/entities/Usuario.h"
//#include "../../headers/utils/enums.h"
//#include "../../headers/datatypes/DataUsuario.h"
//#include "../../headers/datatypes/DataDesarrollador.h"
#include "../../headers/utils/Fecha.h"

Desarrollador::Desarrollador() : Usuario(){};

Desarrollador::Desarrollador(std::string email, std::string password, std::string nombreEmpresa) : Usuario(email, password)
{
    this->nombreEmpresa = nombreEmpresa;
}

//Getters
string Desarrollador::getNombreEmpresa()
{
    return this->nombreEmpresa;
}

//Setters
void Desarrollador::setNombreEmpresa(std::string nomEmpresa)
{
    this->nombreEmpresa = nomEmpresa;
}

//Operaciones

DataUsuario *Desarrollador::getData()
{
    return nullptr;
}

void Desarrollador::agregarVideojuegoPublicado(Videojuego *vj)
{
}

set<Videojuego*>  Desarrollador::getVideojuegoPublicados(){
    map<string,Videojuego *> vjs=this->publicaciones;
    map<string,Videojuego*>::iterator it;
    set<Videojuego*> res;
    for (it = vjs.begin(); it != vjs.end(); it++){
        Videojuego* video=it->second;
        res.insert(video);
    }
    return res;
}

void Desarrollador::eliminarVideojuegoPublicado(Videojuego *vj){
    this->publicaciones.erase(vj->getNombre());
}

Desarrollador::~Desarrollador(){};
