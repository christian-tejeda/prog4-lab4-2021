#ifndef DATA_DESARROLLADOR_H
#define DATA_DESARROLLADOR_H

#include <string>

#include "../datatypes/DataUsuario.h"

using namespace std;

class DataDesarrollador : public DataUsuario
{
private:
    string nombreEmpresa;

public:
    DataDesarrollador();
    DataDesarrollador(const DataDesarrollador &data);
    DataDesarrollador(string email, string password, string nombreEmpresa);

    string getNombreEmpresa() const;

    friend bool operator<(const DataDesarrollador &d1, const DataDesarrollador &d2);
    friend bool operator!=(const DataDesarrollador &d1, const DataDesarrollador &d2);

    ~DataDesarrollador();
};

#endif