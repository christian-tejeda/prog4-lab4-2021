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

map<string, Usuario *> UsuarioHandler::obtenerJugadoresConSuscripcionActiva(Videojuego *vj) { return map<string, Usuario *>(); }

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

bool UsuarioHandler::tienePartidaSinFinalizar(Videojuego *vj)
{

    map<std::string, Usuario *> users = this->users;

    map<std::string, Usuario *>::iterator it;
    Jugador *jugador = dynamic_cast<Jugador *>(it->second);
    bool tiene = jugador->tienePartidaSinFinalizar(vj);
    while (it != users.end() && !tiene)
    {
        it++;
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        tiene = jugador->tienePartidaSinFinalizar(vj);
    }

    return tiene;
}

map<string, Usuario *> UsuarioHandler::obtenerUsuarios() { return this->users; }

Partida *UsuarioHandler::obtenerPartidaPorId(int idPartida) { return nullptr; }

void UsuarioHandler::eliminarUsuario(Usuario *usuario) {}

UsuarioHandler::~UsuarioHandler()
{
    map<std::string, Usuario *>::iterator it;
    Usuario *toDelete = nullptr;

    for (it = users.begin(); it != users.end(); ++it)
    {
        //toDelete = it->second;
        //this->users.erase(it->first);
        delete it->second;
        it->second = nullptr;
    }

    this->users.clear();
}

void UsuarioHandler::releaseInstance()
{
    if (instancia != nullptr)
    {
        delete instancia;
        instancia = nullptr;
    }
}


float UsuarioHandler::obtenerHoras(Videojuego* vj){
    map<string,Usuario*> coleccion=this->users;
    map<string,Usuario*>::iterator it;
    float res=0;
    for (it = coleccion.begin(); it != coleccion.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        if (jugador!=nullptr){
            float duracion =jugador->obtenerDuracionPartida(vj);
            res=res+duracion;
        }
    }
    return res;
}
