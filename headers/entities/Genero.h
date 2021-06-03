#ifndef GENERO_H
#define GENERO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../enums.h"
#include "../headers/DataCategoria.h"

using namespace std;

class Genero : public Cateogria{
private:
    TipoGenero tipo;
public:
    Genero();
    setTipoGenero(TipoGenero tipoGenero);
    getTipoGenero();
    ~Genero();
};

#endif
