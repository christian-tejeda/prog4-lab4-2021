#ifndef DATA_ESTADISTICA_H
#define DATA_ESTADISTICA_H

#include <string>

#include "../utils/enums.h"

class DataEstadistica {
private:
  TipoEstadistica estadistica;
  float resultado;

public:
  DataEstadistica();
  DataEstadistica(TipoEstadistica estadistica, float resultado);

  TipoEstadistica getEstadistica();
  float getResultado();

  ~DataEstadistica();
};

#endif