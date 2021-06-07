#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/utils/enums.h"
#include "../../headers/entities/Categoria.h"
#include "../../headers/entities/Genero.h"
#include "../../headers/entities/Plataforma.h"
#include "../../headers/handlers/VideojuegoHandler.h"

using namespace std;

VideojuegoHandler::VideojuegoHandler(){

}

static VideojuegoHandler * VideojuegoHandler::getInstance(){
    return nullptr;
}

void VideojuegoHandler::agregarrVideojuego(Videojuego *vj){

}
map<string, Videojuego *> VideojuegoHandler::obtenerVideojuegos(){
    return nullptr;
}
Videojuego *VideojuegoHandler::obtenerVideojuegoPorId(string nombre){
    return nullptr;
}
void VideojuegoHandler::eliminarVideojuego(Videojuego *vj){

}
void VideojuegoHandler::actualizarVideojuego(Videojuego *vj){

}
map<string, Jugador *> VideojuegoHandler::obtenerJugadoresVideojuego(Videojuego *vj){
    return nullptr;
}
VideojuegoHandler::~VideojuegoHandler(){}

