#ifndef DATA_ESTADISTICA_H
#define DATA_ESTADISTICA_H

#include <string>

#include "../utils/enums.h"

class DataEstadistica
{
private:
    std::string nombre;
    std::string descripcion;
    float valor;

public:
    DataEstadistica();
    DataEstadistica(std::string nombre, std::string descripcion, float valor);
    // TipoEstadistica getEstadistica(); <- tipo de retorno?
    float getResultado();
    ~DataEstadistica();
};

#endif