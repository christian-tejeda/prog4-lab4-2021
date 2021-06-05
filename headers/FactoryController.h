#ifndef FACTORY_CONTROLLER_H
#define FACTORY_CONTROLLER_H

#include <string>
#include <utility>
#include "interfaces/IUsuarioController.h"
#include "interfaces/IPartidaController.h"
#include "interfaces/IVideojuegoController.h"

using namespace std;

class FactoryController
{
    //singleton
private:
    static FactoryController *instancia;

public:
    FactoryController();
    //op de singleton
    static FactoryController *getInstance();
    //op de factory
    IUsuarioController *getIUsuarioController();
    IVideojuegoController *getIVideojuegoController();
    IPartidaController *getIPartidaController();

    ~FactoryController();
};

#endif