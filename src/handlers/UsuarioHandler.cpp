#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/utils/enums.h"
#include "../../headers/entities/Categoria.h"
#include "../../headers/entities/Genero.h"
#include "../../headers/entities/Plataforma.h"
#include "../../headers/handlers/UsuarioHandler.h"
#include "../../headers/entities/Desarrollador.h"

using namespace std;

UsuarioHandler *UsuarioHandler::instancia = nullptr;

UsuarioHandler::UsuarioHandler() {}

UsuarioHandler *UsuarioHandler::getInstance()
{
    if (instancia == nullptr)
        instancia = new UsuarioHandler();

    return instancia;
}

bool UsuarioHandler::existeJugadorConNickname(string nickname)
{
    map<std::string, Usuario *> users = this->users;

    map<std::string, Usuario *>::iterator it;

    for (it = users.begin(); it != users.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);

        if (jugador != nullptr && jugador->getNickname() == nickname)
            return true;
    }

    return false;
}

void UsuarioHandler::agregarUsuario(DataUsuario *usuario)
{
    Usuario *user;
    DataJugador *dtJg = dynamic_cast<DataJugador *>(usuario);
    DataDesarrollador *dtDev = dynamic_cast<DataDesarrollador *>(usuario);
    if (dtJg)
    {
        user = new Jugador(dtJg->getEmail(), dtJg->getPassword(), dtJg->getNickname(), dtJg->getDescripcion());
    }
    else
    {
        user = new Desarrollador(dtDev->getEmail(), dtDev->getPassword(), dtDev->getNombreEmpresa());
    }

    this->users.insert(std::pair<std::string, Usuario *>(user->getEmail(), user));
}

map<string, Usuario *> UsuarioHandler::obtenerJugadoresConSuscripcionActiva(Videojuego *vj) { 
    map<string,Usuario*>::iterator it;
    map<string,Usuario*> res;
    for(it = this->users.begin();it != this->users.end(); it++){
        Jugador * testJugador = dynamic_cast<Jugador*>(it->second);
        if(testJugador != nullptr){
            if(dynamic_cast<Jugador*>(it->second)->tieneSuscripcionActiva(vj)){
                res.insert({it->first,it->second});
            }
        }
    }
    return res;
}

Jugador *UsuarioHandler::obtenerJugadorPorNickname(string nickname)
{

    map<std::string, Usuario *> users = this->users;

    map<std::string, Usuario *>::iterator it;

    for (it = users.begin(); it != users.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);

        if (jugador != nullptr && jugador->getNickname() == nickname)
            return jugador;
    }

    return nullptr;
}

bool UsuarioHandler::tienePartidaSinFinalizar(Videojuego *vj) { return false; }

map<string, Usuario *> UsuarioHandler::obtenerUsuarios() { return this->users; }

Partida *UsuarioHandler::obtenerPartidaPorId(int idPartida) { return nullptr; }

void UsuarioHandler::eliminarUsuario(Usuario *usuario) {}

UsuarioHandler::~UsuarioHandler() {}
