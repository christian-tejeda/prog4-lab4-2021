#ifndef DATA_ESTADISTICA_H
#define DATA_ESTADISTICA_H

#include <string>
#include <iostream>

#include "../utils/enums.h"
using namespace std;
class DataEstadistica {
private:
  TipoEstadistica estadistica;
  float resultado;

public:
  DataEstadistica();
  DataEstadistica(TipoEstadistica estadistica, float resultado);

  TipoEstadistica getEstadistica();
  float getResultado();
  friend ostream &operator<<(ostream &os, const DataEstadistica &dt); 

  ~DataEstadistica();
};

#endif