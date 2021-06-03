#ifndef DATA_GENERO_H
#define DATA_GENERO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "DataCategoria.h"

using namespace std;

class DataGenero : public DataCategoria{
private:
    TipoGenero tipoGenero;
public: 
    DataGenero();
    DataGenero(TipoGenero tipoGenero);
    //setTipoGenero(TipoGenero tipoGenero) const;
    TipoGenero getTipoGenero() const;
    ~DataGenero();
};

#endif