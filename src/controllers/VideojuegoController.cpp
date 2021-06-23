

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

DataVideojuego VideojuegoController::getDataVideojuego()
{
    DataVideojuego res;
    return res;
}

Videojuego *VideojuegoController::getVideojuego() { return nullptr; }

void VideojuegoController::ingresarDatosVideojuego(DataVideojuego data)
{
    UsuarioController *usuarioController = UsuarioController::getInstance();
    Desarrollador *dev = dynamic_cast<Desarrollador *>(usuarioController->getSesion());

    this->dataVideojuego = data;
    this->dataVideojuego.setNombreEmpresa(dev->getNombreEmpresa());
}

set<DataCategoria> VideojuegoController::obtenerCategorias()
{
    CategoriaHandler *categoriaHandler = CategoriaHandler::getInstance();

    map<string, Categoria *> categorias = categoriaHandler->obtenerCategorias();

    set<DataCategoria> res;
    map<string, Categoria *>::iterator it;
    for (it = categorias.begin(); it != categorias.end(); it++)
    {
        Categoria *cat = it->second;
        DataCategoria data = DataCategoria(cat->getNombre(), cat->getDescripcion(), cat->getTipo());
        res.insert(data);
    }

    return res;
}

void VideojuegoController::agregarCategoriaAVideojuego(string categoria) { this->dataVideojuego.agregarCategoria(categoria); };

DataVideojuego VideojuegoController::obtenerDataVideojuegoIngresada() { return this->dataVideojuego; }

void VideojuegoController::confirmarPublicacionVideojuego()
{
    UsuarioController *usuarioController = UsuarioController::getInstance();
    CategoriaHandler *categoriaHandler = CategoriaHandler::getInstance();
    VideojuegoHandler *videojuegoHandler = VideojuegoHandler::getInstance();

    set<ContratoSuscripcion *> nuevosContratos;
    map<string, Categoria *> nuevasCategorias;
    set<string>::iterator iter;

    set<string> nombrescat = this->dataVideojuego.getNombreCategorias();

    for (iter = nombrescat.begin(); iter != nombrescat.end(); iter++)
    {
        Categoria *nuevaCat = categoriaHandler->obtenerCategoriaPorId(*iter);
        nuevasCategorias.insert(pair<string, Categoria *>(*iter, nuevaCat));
    };

    Videojuego *videojuego = new Videojuego(this->dataVideojuego.getNombre(), this->dataVideojuego.getDescripcion(), this->dataVideojuego.getSuscripciones(), this->dataVideojuego.getRating(), nuevosContratos, nuevasCategorias, this->dataVideojuego.getNombreEmpresa());

    videojuegoHandler->agregarVideojuego(videojuego);

    Desarrollador *dev = dynamic_cast<Desarrollador *>(usuarioController->getSesion());

    dev->agregarVideojuegoPublicado(videojuego);
}

set<DataVideojuego> VideojuegoController::obtenerVideojuegosPublicadosPorDesarrolladorConPartidasFinalizadas()
{

    UsuarioController *usuarioController = UsuarioController::getInstance();
    UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();

    Desarrollador *dev = dynamic_cast<Desarrollador *>(usuarioController->getSesion());
    set<Videojuego *> vjs = dev->getVideojuegoPublicados();

    set<DataVideojuego> res;
    set<Videojuego *>::iterator it;

    for (it = vjs.begin(); it != vjs.end(); it++)
    {
        Videojuego *videojuego = *it;
        bool tiene = usuarioHandler->tienePartidaSinFinalizar(videojuego);
        if (!tiene)
        {
            DataVideojuego dvj = videojuego->getData();
            res.insert(dvj);
        }
    }
    return res;
}
void VideojuegoController::seleccionarVideojuego(string nombreVideojuego)
{
    VideojuegoHandler *videojuegoHandler = VideojuegoHandler::getInstance();

    Videojuego *videojuego = videojuegoHandler->obtenerVideojuegoPorId(nombreVideojuego);
    this->videojuego = videojuego;
}

void VideojuegoController::confirmarEliminarVideojuego()
{

    UsuarioController *usuarioController = UsuarioController::getInstance();
    UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();
    VideojuegoHandler *videojuegoHandler = VideojuegoHandler::getInstance();

    Desarrollador *dev = dynamic_cast<Desarrollador *>(usuarioController->getSesion());
    Videojuego *videojuego = this->videojuego;

    dev->eliminarVideojuegoPublicado(videojuego);

    map<string, Usuario *> usuarios = usuarioHandler->obtenerUsuarios();
    map<string, Usuario *>::iterator it;

    for (it = usuarios.begin(); it != usuarios.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        if (jugador != nullptr)
        {
            jugador->eliminarContratosDeVideojuego(videojuego);
            jugador->eliminarPartidasDeVideojuego(videojuego);
        }
    }

    videojuegoHandler->eliminarVideojuego(videojuego);
}

void VideojuegoController::puntuarVideojuego(int puntaje) { this->videojuego->agregarPuntaje(puntaje); }

set<DataVideojuego> VideojuegoController::obtenerVideojuegos()
{
    VideojuegoHandler *videojuegoHandler = VideojuegoHandler::getInstance();

    map<string, Videojuego *> videojuegos = videojuegoHandler->obtenerVideojuegos();

    set<DataVideojuego> res = set<DataVideojuego>();
    map<string, Videojuego *>::iterator it;
    for (it = videojuegos.begin(); it != videojuegos.end(); it++)
    {
        Videojuego *videojuego = it->second;
        DataVideojuego dataVideojuego = DataVideojuego(videojuego->getNombre(), videojuego->getDescripcion(), videojuego->getSuscripciones(), videojuego->getNombreCategorias(), videojuego->getRating());
        res.insert(dataVideojuego);
    }

    return res;
}

DataVideojuego VideojuegoController::obtenerDataVideojuego(string nombreVideojuego)
{
    UsuarioController *usuarioController = UsuarioController::getInstance();

    this->seleccionarVideojuego(nombreVideojuego);
    DataVideojuego res = DataVideojuego(this->videojuego->getNombre(), this->videojuego->getDescripcion(), this->videojuego->getSuscripciones(), this->videojuego->getNombreCategorias(), this->videojuego->getRating());

    Desarrollador *dev = dynamic_cast<Desarrollador *>(usuarioController->getSesion());
    res.setNombreEmpresa(this->videojuego->getNombreEmpresa());

    if (dev != nullptr)
    {
        UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();
        res.setHorasTotales(usuarioHandler->obtenerHoras(this->videojuego));
    }
    else
    {
        res.setHorasTotales(-1);
    }

    return res;
}

void VideojuegoController::agregarCategoria(string nombre, string descripcion, TipoCategoria tipo) { this->dataCategoria = DataCategoria(nombre, descripcion, tipo); }

void VideojuegoController::confirmarAgregarCategoria()
{

    CategoriaHandler *categoriaHandler = CategoriaHandler::getInstance();

    categoriaHandler->crearNuevaCategoria(this->dataCategoria.getNombre(), this->dataCategoria.getDescripcion(), this->dataCategoria.getTipo());
}

VideojuegoController::~VideojuegoController() { this->videojuego = nullptr; }

set<string> VideojuegoController::obtenerNombreVideojuegos()
{
    VideojuegoHandler *videojuegoHandler = VideojuegoHandler::getInstance();

    return videojuegoHandler->obtenerNombresVideojuegos();
}

void VideojuegoController::eleminarVideojuegoGeneral()
{

    UsuarioController *usuarioController = UsuarioController::getInstance();
    UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();

    map<string, Usuario *> usuarios = usuarioHandler->obtenerUsuarios();
    map<string, Usuario *>::iterator it;
    for (it = usuarios.begin(); it != usuarios.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        if (jugador != nullptr)
        {
            jugador->eliminarContratosDeVideojuego(this->videojuego);
            jugador->eliminarPartidasDeVideojuego(this->videojuego);
        }
    }

    delete this->videojuego;
}