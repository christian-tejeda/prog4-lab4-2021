#ifndef FACTORY_CONTROLLER_H
#define FACTORY_CONTROLLER_H

#include <string>
#include <utility>
#include "interfaces/IUsuarioController.h"
#include "interfaces/IPartidaController.h"
#include "interfaces/IVideojuegoController.h"

using namespace std;


class FactoryController{
    //singleton
private:
    static FactoryController* instancia;
    FactoryController();
public:
    IUsuarioController* getUsuarioController();
    IVideojuegoController* getVideojuegoController();
    IPartidaController* getPartidaController();
    ~FactoryController();
};


#endif