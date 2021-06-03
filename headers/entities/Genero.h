#ifndef GENERO_H
#define GENERO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataCategoria.h"
#include "../entities/Categoria.h"

using namespace std;

class Genero : public Categoria
{
private:
    TipoGenero tipo;

public:
    Genero();
    void setTipoGenero(TipoGenero tipoGenero);
    TipoGenero getTipoGenero();
    ~Genero();
};

#endif
