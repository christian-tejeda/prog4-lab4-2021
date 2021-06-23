#include "../../headers/datatypes/DataUsuario.h"

DataUsuario::DataUsuario() {}

DataUsuario::DataUsuario(const DataUsuario &data)
{
    email = data.email;
    password = data.password;
}

DataUsuario::DataUsuario(string email, string password)
{
    email = email;
    password = password;
}

string DataUsuario::getEmail() const { return email; }

string DataUsuario::getPassword() const { return password; }

bool operator<(const DataUsuario &d1, const DataUsuario &d2)
{
    return &d1 < &d2;
}

bool operator!=(const DataUsuario &d1, const DataUsuario &d2)
{
    return d1.getPassword() != d2.getPassword() || d1.getEmail() != d2.getEmail();
}

DataUsuario::~DataUsuario(){};