#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/utils/enums.h"
#include "../../headers/entities/Categoria.h"
#include "../../headers/handlers/VideojuegoHandler.h"
#include "../../headers/controllers/VideojuegoController.h"

VideojuegoHandler *VideojuegoHandler::instancia = nullptr;

VideojuegoHandler::VideojuegoHandler() {}

VideojuegoHandler *VideojuegoHandler::getInstance()
{
    if (instancia == nullptr)
        instancia = new VideojuegoHandler();

    return instancia;
}

void VideojuegoHandler::agregarVideojuego(Videojuego *videojuego)
{
    this->videojuegos.insert(pair<string, Videojuego *>(videojuego->getNombre(), videojuego));
}

map<string, Videojuego *> VideojuegoHandler::obtenerVideojuegos() { return this->videojuegos; }

Videojuego *VideojuegoHandler::obtenerVideojuegoPorId(string nombre)
{
    map<string, Videojuego *>::iterator it;
    it = this->videojuegos.find(nombre);
    if (it == this->videojuegos.end())
        return nullptr;
    else
        return it->second;
}

void VideojuegoHandler::eliminarVideojuego(Videojuego *videojuego)
{
    string nombre = videojuego->getNombre();
    this->videojuegos.erase(nombre);

    delete videojuego;
}

map<string, Jugador *> VideojuegoHandler::obtenerJugadoresVideojuego(Videojuego *vj)
{
    ///TODO: why?
    return map<string, Jugador *>();
}

set<string> VideojuegoHandler::obtenerNombresVideojuegos()
{
    map<string, Videojuego *>::iterator it;
    set<string> res;

    for (it = this->videojuegos.begin(); it != this->videojuegos.end(); it++)
    {
        res.insert(it->second->getNombre());
    }

    return res;
}

VideojuegoHandler::~VideojuegoHandler()
{
    /// TODO: Por que el handler conoce al controller ???

    // VideojuegoController *videojuegoController = VideojuegoController::getInstance();
    // map<string, Videojuego *>::iterator it;

    // for (it = this->videojuegos.begin(); it != this->videojuegos.end(); it++)
    // {
    //     videojuegoController->seleccionarVideojuego(it->second->getNombre());
    //     videojuegoController->eleminarVideojuegoGeneral();
    // }

    // this->videojuegos.clear();
}

void VideojuegoHandler::releaseInstance()
{
    if (instancia != nullptr)
    {
        delete instancia;
        instancia = nullptr;
    }
}
