

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/controllers/VideojuegoController.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

VideojuegoController::VideojuegoController() {}
//op de singleton
VideojuegoController::VideojuegoController *getInstance() {}
//Getters
DataVideojuego *VideojuegoController::getDataVideojuego() {}
Videojuego *VideojuegoController::getVideojuego()
{
}
//ops del interface
void VideojuegoController::ingresarDatosVideojuego(DataVideojuego *DataV) {}
set<DataCategoria *> VideojuegoController::obtenerCategorias()
{
    set<DataCategoria *> res;
    res.insert(nullptr);
    return res;
}
void VideojuegoController::agregarPlataformaAVideojuego(string plataforma) {}
void VideojuegoController::agregarGeneroAVideojuego(string genero) {}
void VideojuegoController::agregarOtraCategoriaAVideojuego(string cat) {}
DataVideojuego *VideojuegoController::obtenerDataVideojuegoIngresada()
{
    return nullptr;
}
void VideojuegoController::confirmarPublicacionVideojuego(bool cancelada) {}
set<DataContratoSuscripcion *> VideojuegoController::obtenerSuscripciones()
{
    set<DataContratoSuscripcion *> res;
    res.insert(nullptr);
    return res;
}
set<DataVideojuego *> VideojuegoController::obtenerVideojuegosPublicadosPorDesarrolladorConPartidasFinalizadas()
{
    set<DataVideojuego *> res;
    res.insert(nullptr);
    return res;
}
void VideojuegoController::seleccionarVideojuego(string nombre) {}
void VideojuegoController::confirmarEliminarVideojuego(bool confirmar) {}
void VideojuegoController::puntuarVideojuego(string nombre, int puntaje) {}
set<DataVideojuego *> VideojuegoController::obtenerVideojuegos()
{
    set<DataVideojuego *> res;
    res.insert(nullptr);
    return res;
}
DataVideojuego *VideojuegoController::obtenerDataVideojuego(string nombre)
{
    return nullptr;
}
void VideojuegoController::agregarPlataforma(DataPlataforma *plataforma) {}
void VideojuegoController::agregarGenero(DataGenero *genero) {}
void VideojuegoController::agregarOtraCategoria(DataCategoria *otra) {}
void VideojuegoController::confirmarAgregarCategoria(bool confirmar) {}
VideojuegoController::~VideojuegoController() {}