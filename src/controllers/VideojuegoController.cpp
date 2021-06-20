

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

VideojuegoController::VideojuegoController() {

}

//op de singleton
//VideojuegoController::VideojuegoController *getInstance() {}

//Getters
DataVideojuego *VideojuegoController::getDataVideojuego() { 
    DataVideojuego res;
    return nullptr; }
Videojuego *VideojuegoController::getVideojuego() { return nullptr; }
//ops del interface
void VideojuegoController::ingresarDatosVideojuego(DataVideojuego *DataV) {
   DataVideojuego *nuevoDataVdj = DataV;
   this->dataVideojuego = nuevoDataVdj;
   UsuarioController * uc;
   uc=uc->getInstance();
   Desarrollador *des = dynamic_cast<Desarrollador *>(uc->getSesion());
   this->dataVideojuego->setNombreEmpresa(des->getNombreEmpresa());
}

set<DataCategoria *> VideojuegoController::obtenerCategorias()
{
    CategoriaHandler * cH;
    cH=cH->getInstance();
    map<std::string, Categoria*> cats= cH->obtenerCategorias();
    set<DataCategoria *> res;
    map<std::string, Categoria*>::iterator it;
    for(it = cats.begin(); it != cats.end(); it++){
        Categoria * cat=it->second;

        DataCategoria* data= new DataCategoria(cat->getNombre(),cat->getDescripcion(),cat->getTipo());
        res.insert(data);
        //delete data;
    }
    return res;
}

void VideojuegoController::agregarCategoriaAVideojuego(string cat) {
    this->dataVideojuego->agregarCategoria(cat);
};

void VideojuegoController::obtenerDataVideojuegoIngresada() {
    std::cout << "Datos ingresados del videojuego:\n";
    std::cout << "Nombre: " << this->dataVideojuego->getNombre() << "\n";
    std::cout << "Descripcion: " << this->dataVideojuego->getDescripcion() << "\n";
    std::cout << "Costes de suscripcion:\n";
    std::cout << "\t Mensual:" << this->dataVideojuego->getSuscripciones()[mensual] << "\n";
    std::cout << "\t Trimestral:" << this->dataVideojuego->getSuscripciones()[trimestral] << "\n";
    std::cout << "\t Anual:" << this->dataVideojuego->getSuscripciones()[anual] << "\n";
    std::cout << "\t Vitalicia:" << this->dataVideojuego->getSuscripciones()[vitalicia] << "\n";

    std::set<string> cats = this->dataVideojuego->getNombreCategorias();
    std::set<string>::iterator it;
    std::cout << "Categorias:";
    for (it = cats.begin(); it != cats.end(); it++) {
        std::cout << " " << (*it) << " ";
    }
    std::cout << "\n";
}
void VideojuegoController::confirmarPublicacionVideojuego(bool confirmar) {
    if (confirmar) {
        set<ContratoSuscripcion *> nuevoContratos;
        CategoriaHandler *ch;
        VideojuegoHandler *vjh;
        ch = ch->getInstance();
        std::map<string, Categoria *> nuevasCategorias;
        set<std::string>::iterator iter;
        set<std::string> nombrescat=this->dataVideojuego->getNombreCategorias();
        for (iter = nombrescat.begin(); iter != nombrescat.end(); iter++) {
            Categoria *nuevaCat = ch->obtenerCategoriaPorId(*iter);
            nuevasCategorias.insert(pair<string, Categoria *>(*iter,nuevaCat));            
        };
        Videojuego *vdj = new Videojuego(
            this->dataVideojuego->getNombre(),
            this->dataVideojuego->getDescripcion(),
            this->dataVideojuego->getSuscripciones(),
            this->dataVideojuego->getRating(),
            nuevoContratos,
            nuevasCategorias,
            this->dataVideojuego->getNombreEmpresa());
        vjh = vjh->getInstance();
        vjh->agregarVideojuego(vdj);
        UsuarioController* uC;
        uC=uC->getInstance();
        Desarrollador *des = dynamic_cast<Desarrollador *>(uC->getSesion());
        des->agregarVideojuegoPublicado(vdj);

        std::cout << "Videojuego publicado exitosamente.\n";
    }
}

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
    for (it = vjs.begin(); it != vjs.end(); it++)
    {
        Videojuego *vj = *it;
        bool tiene = uh->tienePartidaSinFinalizar(vj);
        if (!tiene)
        {
            DataVideojuego *dvj = vj->getData();
            res.insert(dvj);
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
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        if (jugador!=nullptr) {
            jugador->eliminarContratosDeVideojuego(video);
            std::cout << "Paso EliminarContratos.\n";
            jugador->eliminarPartidasDeVideojuego(video);
            
            std::cout << "Paso EliminarPartidas.\n";
        }
    }
    VideojuegoHandler *vH;
    vH = vH->getInstance();
    vH->eliminarVideojuego(video);
    std::cout << "Paso EliminarJuego.\n";
    video->~Videojuego();
}
void VideojuegoController::puntuarVideojuego(int puntaje) {
    this->videojuego->agregarPuntaje(puntaje);
}

set<DataVideojuego *> VideojuegoController::obtenerVideojuegos()
{   
    VideojuegoHandler *vH;
    vH = vH->getInstance();
    map<std::string, Videojuego*> vjs = vH->obtenerVideojuegos();
    map<std::string, Videojuego*>::iterator it;
    set<DataVideojuego *> res;
    for (it = vjs.begin(); it != vjs.end(); it++)
    {
        Videojuego * video = it->second;
        DataVideojuego * data = new DataVideojuego(video->getNombre(),video->getDescripcion(),video->getSuscripciones(),video->getNombreCategorias(),video->getRating());
        res.insert(data);
    }
    return res;
}
DataVideojuego *VideojuegoController::obtenerDataVideojuego(string nombre)
{
    this->seleccionarVideojuego(nombre);
    Videojuego* este=this->videojuego;//string nombre, string descripcion, map<TipoPeriodoValidez, float> suscripciones, set<string> nombreCategorias, pair<float, int> rating);
    DataVideojuego *res= new DataVideojuego(este->getNombre(),este->getDescripcion(),este->getSuscripciones(),este->getNombreCategorias(),este->getRating());
    UsuarioController * uc;
    uc=uc->getInstance();
    Desarrollador* des= dynamic_cast<Desarrollador*>(uc->getSesion());
    res->setNombreEmpresa(des->getNombreEmpresa()); 
    if (des!=nullptr){
        UsuarioHandler * uH;
        uH=uH->getInstance();
        res->setHorasTotales(uH->obtenerHoras(este));
    }else{
        res->setHorasTotales(-1);
    }  
    return res;
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
    //delete this->dataCategoria;
}
VideojuegoController::~VideojuegoController() {
    //if (this->dataVideojuego!=nullptr) delete this->dataVideojuego;
    //if (this->dataCategoria!=nullptr) delete this->dataCategoria;
    this->videojuego=nullptr;
}

set<std::string> VideojuegoController::obtenerNombreVideojuegos(){
    VideojuegoHandler * vH;
    vH=vH->getInstance();
    return vH->obtenerNombresVideojuegos();
}
