#ifndef DATA_CATEGORIA_H
#define DATA_CATEGORIA_H

#include "../utils/enums.h"

using namespace std;

class DataCategoria
{
private:
    string nombre;
    string descripcion;
    TipoCategoria tipo;

public:
    DataCategoria();
    DataCategoria(const DataCategoria &data);
    DataCategoria(string nombre, string descripcion);
    DataCategoria(string nombre, string descripcion, TipoCategoria tipo);

    string getNombre() const;
    string getDescripcion() const;
    TipoCategoria getTipo() const;

    friend bool operator<(const DataCategoria &d1, const DataCategoria &d2);
    friend bool operator!=(const DataCategoria &d1, const DataCategoria &d2);

    ~DataCategoria();
};

#endif