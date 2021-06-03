
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Usuario.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

Usuario::Usuario() {}

Usuario::Usuario(std::string email, std::string password)
{
    this->email = email;
    this->password = password;
}

std::string Usuario::getEmail()
{
    return this->email;
}
std::string Usuario::getPassword()
{
    return this->password;
}
Usuario::~Usuario(){};


