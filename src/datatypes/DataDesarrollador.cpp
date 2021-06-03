
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataUsuario.h"
#include "../../headers/datatypes/DataDesarrollador.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

DataDesarrollador::DataDesarrollador() {}

DataDesarrollador::DataDesarrollador(std::string email, std::string password, std::string nombreEmpresa) : DataUsuario(email, password)
{
    this->nombreEmpresa = nombreEmpresa;
}

std::string DataDesarrollador::getNombreEmpresa()
{
    return this->nombreEmpresa;
}

DataDesarrollador::~DataDesarrollador(){};
