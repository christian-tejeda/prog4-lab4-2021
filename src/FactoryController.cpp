#include <string>
#include <map>
#include <set>
#include <utility>

#include "../headers/FactoryController.h"

using namespace std;

FactoryController* FactoryController::instancia = NULL;

FactoryController::FactoryController(){}

IUsuarioController* FactoryController::getUsuarioController(){}
IVideojuegoController* FactoryController::getVideojuegoController(){}
IPartidaController* FactoryController::getPartidaController(){}
FactoryController::~FactoryController(){}
