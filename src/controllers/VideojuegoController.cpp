

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
#include "../../headers/handlers/CategoriaHandler.h"

using namespace std;

VideojuegoController::VideojuegoController() {}

//op de singleton
//VideojuegoController::VideojuegoController *getInstance() {}

//Getters
DataVideojuego *VideojuegoController::getDataVideojuego() { 
    DataVideojuego res;
    return nullptr; }
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

    UsuarioController *uc = UsuarioController::getInstance();
    Desarrollador *des = dynamic_cast<Desarrollador *>(uc->getSesion());
    set<Videojuego *> vjs = des->getVideojuegoPublicados();
    UsuarioHandler *uh;
    uh = uh->getInstance();
    set<DataVideojuego *> res;
    set<Videojuego *>::iterator it;
    it = vjs.begin();
    while (vjs.end() != it)
    {
        Videojuego *vj = *it;
        bool tiene = uh->tienePartidaSinFinalizar(vj);
        if (tiene)
        {
            DataVideojuego *dvj = vj->getData();
            res.insert(dvj);
            it++;
        }
    }
    return res;
}
void VideojuegoController::seleccionarVideojuego(string nombre)
{
    VideojuegoHandler *vH;
    vH = vH->getInstance();
    Videojuego *res = vH->obtenerVideojuegoPorId(nombre);
    this->videojuego = res;
}
void VideojuegoController::confirmarEliminarVideojuego(bool confirmar)
{
    //en proceso
    UsuarioController * uc;
    uc=uc->getInstance();
    Desarrollador * dev = dynamic_cast<Desarrollador *>(uc->getSesion());    
    Videojuego * video= this->videojuego;
    dev->eliminarVideojuegoPublicado(video);
    UsuarioHandler *uH;
    uH = uH->getInstance();
    map<string, Usuario *> users = uH->obtenerUsuarios();
    map<string, Usuario *>::iterator it;
    for (it = users.begin(); it != users.end(); it++)
    {
        Jugador *user = dynamic_cast<Jugador *>(it->second);
        user->eliminarContratosDeVideojuego(video);
        user->eliminarPartidasDeVideojuego(video);
    }
    VideojuegoHandler *vH;
    vH = vH->getInstance();
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
    Videojuego* este=this->videojuego;//string nombre, string descripcion, map<TipoPeriodoValidez, float> suscripciones, set<string> nombreCategorias, pair<float, int> rating);
    DataVideojuego res=DataVideojuego(este->getNombre(),este->getDescripcion(),este->getSuscripciones(),este->getNombreCategorias(),este->getRating());
    UsuarioController * uc;
    uc=uc->getInstance();
    Desarrollador* des= dynamic_cast<Desarrollador*>(uc->getSesion());
    //res.setNombreEmpresa(des->getNombreEmpresa()); ESTO IMPORTANTE VER COMO SE HACE CUANDO SE PUBLICA...
    if (des!=nullptr){
        UsuarioHandler * uH;
        uH=uH->getInstance();
        res.setHorasTotales(uH->obtenerHoras(este));
    }else{
        res.setHorasTotales(-1);
    }
    DataVideojuego * punter= &res;
    return punter;
}
void VideojuegoController::agregarCategoria(std::string nombre,std::string descripcion, TipoCategoria tipo) {
    this->dataCategoria=new DataCategoria(nombre,descripcion,tipo);
}
//void VideojuegoController::agregarGenero(DataGenero *genero) {}
//void VideojuegoController::agregarOtraCategoria(DataCategoria *otra) {}

void VideojuegoController::confirmarAgregarCategoria(bool confirmar) {
    if (confirmar){
        CategoriaHandler * ch;
        ch=ch->getInstance();
        ch->crearNuevaCategoria(this->dataCategoria->getNombre(), this->dataCategoria->getDescripcion(),this->dataCategoria->getTipo());
    }
    delete this->dataCategoria;
}
VideojuegoController::~VideojuegoController() {}

/*ESTO SI QUEDA COMENTADO EL 18062021 A LAS 1500 SE PUEDE BORRAR
int VideojuegoController::obtenerHoras(){
    Videojuego * vj=this->videojuego;
    UsuarioHandler * uH;
    uH=uH->getInstance();
    int res=uH->obtenerHoras(vj);  
    return res;
}*/

set<std::string> VideojuegoController::obtenerNombreVideojuegos(){
    VideojuegoHandler * vH;
    vH=vH->getInstance();
    return vH->obtenerNombresVideojuegos();
}
