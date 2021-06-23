#ifndef DATA_ESTADISTICA_H
#define DATA_ESTADISTICA_H

#include <string>
#include <iostream>

#include "../utils/enums.h"

using namespace std;
class DataEstadistica
{
private:
  TipoEstadistica estadistica;
  float resultado;

public:
  DataEstadistica();
  DataEstadistica(const DataEstadistica &data);
  DataEstadistica(TipoEstadistica estadistica, float resultado);

  TipoEstadistica getEstadistica() const;
  float getResultado() const;

  friend ostream &operator<<(ostream &os, const DataEstadistica &dt);
  friend bool operator<(const DataEstadistica &d1, const DataEstadistica &d2);
  friend bool operator!=(const DataEstadistica &d1, const DataEstadistica &d2);

  ~DataEstadistica();
};

#endif