#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/utils/enums.h"
#include "../../headers/entities/Categoria.h"
#include "../../headers/entities/Genero.h"
#include "../../headers/entities/Plataforma.h"
#include "../../headers/handlers/UsuarioHandler.h"

using namespace std;

UsuarioHandler::UsuarioHandler(){}
UsuarioHandler * UsuarioHandler::getInstance(){
    return nullptr;
}
bool UsuarioHandler::existeJugadorConNickname(string n){
    return false;
}
void UsuarioHandler::agregarUsuario(Usuario *usuario){
}
map<string, Usuario *> UsuarioHandler::obtenerJugadoresConSuscripcionActiva(Videojuego *vj){
    return nullptr;
}
Jugador *UsuarioHandler::obtenerJugadorPorNickname(string n) {
    return nullptr;
}
bool UsuarioHandler::tienePartidaSinFinalizar(Videojuego *vj){
    return false;
}
map<string, Usuario *> UsuarioHandler::obtenerUsuarios(){
    return nullptr;
}
void UsuarioHandler::actualizarUsuario(Usuario *usuario){
    
}
Partida *UsuarioHandler::obtenerPartidaPorId(int idPartida){
    return nullptr;;
}
void UsuarioHandler::eliminarUsuario(Usuario *usuario){

}

UsuarioHandler::~UsuarioHandler(){}