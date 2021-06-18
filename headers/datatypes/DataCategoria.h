#ifndef DATA_CATEGORIA_H
#define DATA_CATEGORIA_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"

//using namespace std;

class DataCategoria
{
private:
    std::string nombre;
    std::string descripcion;
    TipoCategoria tipo;

public:
    DataCategoria();
    DataCategoria(std::string nombre, std::string descripcion);
    DataCategoria(std::string nombre, std::string descripcion, TipoCategoria tipo);
    std::string getNombre() const;
    std::string getDescripcion() const;
    TipoCategoria getTipo() const;
    //setNombre(std::string nombre) const;
    //setDescripcion(std::string descripcion) const;
    ~DataCategoria();
};

#endif