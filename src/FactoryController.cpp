#include <string>
#include <map>
#include <set>
#include <utility>

#include "../headers/FactoryController.h"

using namespace std;

FactoryController *FactoryController::instancia = nullptr;

FactoryController::FactoryController() {}

IUsuarioController *FactoryController::getIUsuarioController() {}
IVideojuegoController *FactoryController::getIVideojuegoController() {}
IPartidaController *FactoryController::getIPartidaController() {}
FactoryController::~FactoryController() {}
