#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/utils/enums.h"
#include "../../headers/entities/Categoria.h"
#include "../../headers/handlers/UsuarioHandler.h"
#include "../../headers/entities/Desarrollador.h"
#include "../../headers/entities/Jugador.h"
#include "../../headers/datatypes/DataDesarrollador.h"

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
    map<string, Usuario *> users = this->users;

    map<string, Usuario *>::iterator it;

    for (it = users.begin(); it != users.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);

        if (jugador != nullptr && jugador->getNickname() == nickname)
            return true;
    }

    return false;
}

void UsuarioHandler::agregarUsuario(DataUsuario usuario)
{
    Usuario *user;
    DataJugador dataJugador = dynamic_cast<DataJugador &>(usuario);
    DataDesarrollador dataDev = dynamic_cast<DataDesarrollador &>(usuario);
    if (dataJugador != DataJugador())
    {
        user = new Jugador(dataJugador.getEmail(), dataJugador.getPassword(), dataJugador.getNickname(), dataJugador.getDescripcion());
    }
    else
    {
        user = new Desarrollador(dataDev.getEmail(), dataDev.getPassword(), dataDev.getNombreEmpresa());
    }

    this->users.insert(pair<string, Usuario *>(user->getEmail(), user));
}

map<string, Usuario *> UsuarioHandler::obtenerJugadoresConSuscripcionActiva(Videojuego *videojuego)
{
    map<string, Usuario *> res;
    map<string, Usuario *>::iterator it;

    for (it = this->users.begin(); it != this->users.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        if (jugador != nullptr)
        {
            if (dynamic_cast<Jugador *>(it->second)->tieneSuscripcionActiva(videojuego))
            {
                res.insert(pair<string, Usuario *>(it->first, it->second));
            }
        }
    }

    return res;
}

Jugador *UsuarioHandler::obtenerJugadorPorNickname(string nickname)
{

    map<string, Usuario *> users = this->users;

    map<string, Usuario *>::iterator it;

    for (it = users.begin(); it != users.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);

        if (jugador != nullptr && jugador->getNickname() == nickname)
            return jugador;
    }

    return nullptr;
}

Usuario *UsuarioHandler::obtenerUsuarioPorId(string email)
{
    map<string, Usuario *>::iterator iter = this->users.find(email);

    if (iter != this->users.end())
        return iter->second;
    else
        return nullptr;
}

bool UsuarioHandler::tienePartidaSinFinalizar(Videojuego *videojuego)
{
    map<string, Usuario *> users = this->users;
    map<string, Usuario *>::iterator it;
    bool tiene = false;

    for (it = users.begin(); it != users.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        if (jugador != nullptr)
            if (!tiene)
            {
                tiene = jugador->tienePartidaSinFinalizar(videojuego);
            }
    }

    return tiene;
}

map<string, Usuario *> UsuarioHandler::obtenerUsuarios() { return this->users; }

Partida *UsuarioHandler::obtenerPartidaPorId(int idPartida)
{
    Partida *res = nullptr;
    map<string, Usuario *>::iterator it;
    for (it = this->users.begin(); it != this->users.end(); ++it)
    {
        Jugador *jug = dynamic_cast<Jugador *>(it->second);
        if (jug)
        {
            res = jug->obtenerPartidaPorId(idPartida);
            if (res && res->getId() == idPartida)
            {
                return res;
            }
        }
    }
    if (res)
        return res;
    else
        throw invalid_argument("Error: Partida no encontrada.\n");
}

void UsuarioHandler::eliminarUsuario(Usuario *usuario)
{
    ///TODO: vacio??
}

UsuarioHandler::~UsuarioHandler()
{
    map<string, Usuario *>::iterator it;
    for (it = users.begin(); it != users.end(); ++it)
    {
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

float UsuarioHandler::obtenerHoras(Videojuego *videojuego)
{
    map<string, Usuario *> coleccion = this->users;
    map<string, Usuario *>::iterator it;
    float res = 0;

    for (it = coleccion.begin(); it != coleccion.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        if (jugador != nullptr)
        {
            float duracion = jugador->obtenerDuracionPartida(videojuego);
            res += duracion;
        }
    }

    return res;
}

set<DataPartidaMultijugador> UsuarioHandler::obtenerPartidasMultijugadorActivasDeJugador(Jugador *jg)
{
    set<DataPartidaMultijugador> res = set<DataPartidaMultijugador>();

    map<string, Usuario *>::iterator it;
    for (it = this->users.begin(); it != this->users.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        if (jugador)
        {
            map<int, Partida *> pIniciadas = jugador->obtenerPartidasSinFinalizar();
            map<int, Partida *>::iterator it2;
            for (it2 = pIniciadas.begin(); it2 != pIniciadas.end(); it2++)
            {
                PartidaMultijugador *pm = dynamic_cast<PartidaMultijugador *>(it2->second);
                if (pm && pm->existeParticipante(jg))
                {
                    set<DuracionParticipante *> dps = pm->getDuracionParticipantes();
                    set<DuracionParticipante *>::iterator it3;
                    for (it3 = dps.begin(); it3 != dps.end(); it3++)
                    {
                        DuracionParticipante *dp = *it3;
                        if (dp && dp->getParticipante() == jg && dp->getHoraSalida() == Fecha())
                        {
                            res.insert(pm->getData());
                        }
                    }
                }
            }
        }
    }
    return res;
}
