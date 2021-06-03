
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Jugador.h"
#include "../../headers/entities/Usuario.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

Jugador::Jugador() {}

Jugador::Jugador(std::string email, std::string password,std::string nickname, std::string descripcion) : Usuario(email,password)
{
    this->nickname = nickname;
    this->descripcion = descripcion;
}

std::string Jugador::getNickname()
{
    return this->nickname;
}
std::string Jugador::getDescripcion()
{
    return this->descripcion;
}

//Jugador::set<ContratoSuscripcion> obtenerSuscripociones(EstadoSuscripcion estado);

void Jugador::cancelarSuscripcionActiva(Videojuego *vj){

}

//void Juador::contratarSuscripcion(Videojuego *vj, ContratoSuscripcion susc, TipoMetodoPago m);
    
set<Partida *> Jugador::obtenerPartidasSinFinalizar(){
    return NULL;
}

void Jugador::finalizarPartida(int idPartida){

}

set<Videojuego *> Jugador::obtenerVIdeojuegos(){
    return NULL;
}
    
void Jugador::eliminarContratosDeVideojuego(Videojuego *vj){

}

void Jugador::eliminarPartidasDeVideojuego(Videojuego *vj){

}
    
DataUsuario Jugador::getData(){
    return NULL;
}
    
set<PartidaIndividual *> Jugador::obtenerPartidasFinalizadas(){
    return NULL;
}
    
PartidaIndividual Jugador::obtenerPartida(string id){
    return NULL;
}

bool tieneSuscripcionActiva(Videojuego *vj){
    return false;
}

Jugador::~Jugador(){

}





Jugador::~Jugador(){};




    