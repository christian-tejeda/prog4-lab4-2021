
#include <string>

#include "../../headers/datatypes/DataDesarrollador.h"

using namespace std;

DataDesarrollador::DataDesarrollador()
{
    nombreEmpresa = "";
}

DataDesarrollador::DataDesarrollador(const DataDesarrollador &data) : DataUsuario(data)
{
    nombreEmpresa = data.nombreEmpresa;
}

DataDesarrollador::DataDesarrollador(string email, string password, string nombreEmpresa) : DataUsuario(email, password)
{
    nombreEmpresa = nombreEmpresa;
}

string DataDesarrollador::getNombreEmpresa() const { return nombreEmpresa; }

bool operator<(const DataDesarrollador &d1, const DataDesarrollador &d2)
{
    return &d1 < &d2;
}

bool operator!=(const DataDesarrollador &d1, const DataDesarrollador &d2)
{
    return d1.getEmail() != d2.getEmail() || d2.getNombreEmpresa() != d2.getNombreEmpresa() || d1.getPassword() != d2.getPassword();
}

DataDesarrollador::~DataDesarrollador(){};
