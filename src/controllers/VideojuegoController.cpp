

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/controllers/VideojuegoController.h"
#include "../../headers/utils/Fecha.h"
#include "../../headers/controllers/UsuarioController.h"
#include "../../headers/entities/Desarrollador.h"
#include "../../headers/handlers/UsuarioHandler.h"
#include "../../headers/handlers/VideojuegoHandler.h"

using namespace std;

VideojuegoController::VideojuegoController() {}

//op de singleton
//VideojuegoController::VideojuegoController *getInstance() {}

//Getters
DataVideojuego *VideojuegoController::getDataVideojuego() { return nullptr; }
Videojuego *VideojuegoController::getVideojuego() { return nullptr; }
//ops del interface
void VideojuegoController::ingresarDatosVideojuego(DataVideojuego *DataV) {
    this->dataVideojuego = DataV;

    // VideojuegoHandler *vh;
    // vh = vh->getInstance();
    // std::pair<float, int> rating;
    // std::set<ContratoSuscripcion *> contratos;
    // std::map<string, Categoria *> categorias;
    // ContextoEstadistica contexto = nullptr;
    // Videojuego *vj = new Videojuego(
    //     DataV->getNombre(),
    //     DataV->getDescripcion(),
    //     DataV->getSuscripciones(),
    //     DataV->getRating(),
    //     contratos,
    //     categorias,
    //     &contexto);
    // vh->agregarVideojuego(vj);
}

void VideojuegoController::agregarGeneroAVideojuego(string genero) {

}

// set<DataCategoria *> VideojuegoController::obtenerCategorias()
// {
//     set<DataCategoria *> res;
//     res.insert(nullptr);
//     return res;
// }

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
    Desarrollador * des = dynamic_cast<Desarrollador *>(uc.getSesion());   
    set<Videojuego*> vjs = des->getVideojuegoPublicados();
    UsuarioHandler * uh;
    uh=uh->getInstance();
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

void VideojuegoController::seleccionarVideojuego(string nombre) {
    VideojuegoHandler * vH;
    vH=vH->getInstance();
    Videojuego * res=vH->obtenerVideojuegoPorId(nombre);
    this->videojuego=res;
}

void VideojuegoController::confirmarEliminarVideojuego(bool confirmar) {
    //en proceso
    UsuarioController uc;
    uc.getInstance();
    Desarrollador * dev = dynamic_cast<Desarrollador *>(uc.getSesion());    
    Videojuego * video= this->videojuego;
    dev->eliminarVideojuegoPublicado(video);
    UsuarioHandler * uH;
    uH=uH->getInstance();
    map<string,Usuario*> users=uH->obtenerUsuarios();
    map<string,Usuario*>::iterator it;
    for (it = users.begin(); it != users.end(); it++)
    {
        Jugador *user = dynamic_cast<Jugador *>(it->second);
        user->eliminarContratosDeVideojuego(video);
        user->eliminarPartidasDeVideojuego(video);
    }
    VideojuegoHandler * vH;
    vH=vH->getInstance();
    vH->eliminarVideojuego(video);
    video->~Videojuego();
}
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