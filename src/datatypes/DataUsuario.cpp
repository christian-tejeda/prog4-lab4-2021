
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataUsuario.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

DataUsuario::DataUsuario() {}

DataUsuario::DataUsuario(std::string email, std::string password)
{
    this->email = email;
    this->password = password;
}

std::string DataUsuario::getEmail()
{
    return this->email;
}
std::string DataUsuario::getPassword()
{
    return this->password;
}
DataUsuario::~DataUsuario(){};