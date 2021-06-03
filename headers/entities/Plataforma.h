#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataCategoria.h"
#include "../entities/Categoria.h"


using namespace std;

class Plataforma : public Categoria{
private:
    TipoPlataforma tipoPlataforma;
public:
    Plataforma();
    void setTipoPlataforma(TipoPlataforma tipoPlataforma);
    TipoPlataforma getTipoPlataforma();
    ~Plataforma();
};
#endif