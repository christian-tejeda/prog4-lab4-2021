#ifndef DATA_PLATAFORMA_H
#define DATA_PLATAFORMA_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "DataCategoria.h"

using namespace std;

class DataPlataforma : public DataCategoria
{
private:
    TipoPlataforma tipoPlataforma;

public:
    DataPlataforma();
    DataPlataforma(string nombre, string descripcion, TipoPlataforma tipoPlataforma);
    //setTipoPlataforma(TipoPlataforma tipoPlataforma) const;
    TipoPlataforma getTipoPlataforma();
    ~DataPlataforma();
};

#endif