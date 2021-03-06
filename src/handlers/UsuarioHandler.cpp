#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/utils/enums.h"
#include "../../headers/entities/Categoria.h"
//#include "../../headers/entities/Genero.h"
//#include "../../headers/entities/Plataforma.h"
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

map<string, Usuario *> UsuarioHandler::obtenerJugadoresConSuscripcionActiva(Videojuego *vj)
{ //deberia estar bien
    map<string, Usuario *>::iterator it;
    map<string, Usuario *> res;
    for (it = this->users.begin(); it != this->users.end(); it++)
    {
        Jugador *testJugador = dynamic_cast<Jugador *>(it->second);
        if (testJugador != nullptr)
        {
            if (dynamic_cast<Jugador *>(it->second)->tieneSuscripcionActiva(vj))
            {
                //std::cout << "metimos algun jugador con sus activa uh";paso
                res.insert(std::pair<std::string, Usuario *>(it->first, it->second));
                //std::cout << dynamic_cast<Jugador*>(it->second)->getNickname();//FUNCIONA
                //std::cout << it->second->getEmail(); se imprimen los mail correctamente
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

//Retorna un puntero a la instancia Usuario.
//En caso de no encontrarla, retorna nullptr.
Usuario *UsuarioHandler::obtenerUsuarioPorId(string mail)
{
    std::map<string, Usuario *>::iterator iter = this->users.find(mail);
    if (iter != this->users.end())
        return iter->second;
    else
        return nullptr;
}

bool UsuarioHandler::tienePartidaSinFinalizar(Videojuego *vj)
{
    map<std::string, Usuario *> users = this->users;
    map<std::string, Usuario *>::iterator it;
    bool tiene = false;
    for (it = users.begin(); it != users.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        if (jugador != nullptr)
            if (!tiene)
                tiene = jugador->tienePartidaSinFinalizar(vj);
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
    throw std::invalid_argument("Error: Partida no encontrada.\n");
}

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

float UsuarioHandler::obtenerHoras(Videojuego *vj)
{
    map<string, Usuario *> coleccion = this->users;
    map<string, Usuario *>::iterator it;
    float res = 0;
    for (it = coleccion.begin(); it != coleccion.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        if (jugador != nullptr)
        {
            float duracion = jugador->obtenerDuracionPartida(vj);
            res = res + duracion;
        }
    }
    return res;
}

set<DataPartidaMultijugador *> UsuarioHandler::obtenerPartidasMultijugadorActivasDeJugador(Jugador *jg)
{
    set<DataPartidaMultijugador *> res;
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
                        if (dp && dp->getParticipante() == jg && dp->getHoraSalida() == nullptr)
                        {
                            DataPartidaMultijugador *dtpm = dynamic_cast<DataPartidaMultijugador *>(pm->getData());
                            res.insert(dtpm);
                        }
                    }
                }
            }
        }
    }
    return res;
}
