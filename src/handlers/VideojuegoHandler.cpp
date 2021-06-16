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

VideojuegoHandler *VideojuegoHandler::instancia = nullptr;

VideojuegoHandler::VideojuegoHandler() {}

VideojuegoHandler *VideojuegoHandler::getInstance()
{
    if (instancia == nullptr)
    {
        instancia = new VideojuegoHandler();
    }

    return instancia;
}

void VideojuegoHandler::agregarVideojuego(Videojuego *vj)
{
    this->vjs.insert(std::pair<std::string, Videojuego *>(vj->getNombre(), vj));
}

map<string, Videojuego *> VideojuegoHandler::obtenerVideojuegos() { return this->vjs; }

Videojuego *VideojuegoHandler::obtenerVideojuegoPorId(string nombre) { return this->vjs[nombre]; }

void VideojuegoHandler::eliminarVideojuego(Videojuego *vj)
{
    string clave = vj->getNombre();
    this->vjs.erase(clave);
    delete vj;
}

map<string, Jugador *> VideojuegoHandler::obtenerJugadoresVideojuego(Videojuego *vj) { return map<string, Jugador *>(); }

VideojuegoHandler::~VideojuegoHandler() {}

void VideojuegoHandler::releaseInstance()
{
    if (instancia != nullptr)
    {
        delete instancia;
        instancia = nullptr;
    }
}
