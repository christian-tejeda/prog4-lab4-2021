#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../enums.h"
#include "../headers/DataCategoria.h"

using namespace std;

class Plataforma : public Cateogria{
private:
    TipoPlataforma tipoPlataforma;
public:
    Plataforma()
    setTipoPlataforma(TipoPlataforma tipoPlataforma);
    TipoPlataforma getTipoPlataforma();
    ~Plataforma();
};
#endif