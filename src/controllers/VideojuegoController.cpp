

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/controllers/VideojuegoController.h"
#include "../../headers/utils/Fecha.h"
#include "../../headers/controllers/UsuarioController.h"
#include "../../headers/entities/Desarrollador.h"
#include "../../headers/handlers/UsuarioHandler.h"

using namespace std;

VideojuegoController::VideojuegoController() {}

//op de singleton
//VideojuegoController::VideojuegoController *getInstance() {}

//Getters
DataVideojuego *VideojuegoController::getDataVideojuego() { return nullptr; }
Videojuego *VideojuegoController::getVideojuego() { return nullptr; }
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

// set<DataContratoSuscripcion *> VideojuegoController::obtenerSuscripciones()
// {
//     set<DataContratoSuscripcion *> res;
//     res.insert(nullptr);
//     return res;
// }

set<DataVideojuego *> VideojuegoController::obtenerVideojuegosPublicadosPorDesarrolladorConPartidasFinalizadas()
{   
    
    UsuarioController uc;
    uc.getInstance();
    //Desarrollador * des = dynamic_cast<Desarrollador *>(des=dynamic_cast<uc.getSesion()>);
    Desarrollador * des;
    set<Videojuego*> vjs = des->getVideojuegoPublicados();
    UsuarioHandler * uh;
    uh->getInstance();
    set<DataVideojuego*> res;
    set<Videojuego*>::iterator it;
    it=vjs.begin();
    while (vjs.end()!=it) {
        Videojuego *vj= *it;
        bool tiene=uh->tienePartidaSinFinalizar(vj);
        if (tiene) {
            DataVideojuego* dvj= vj->getData();
            res.insert(dvj);
            it++;
        }
    }
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