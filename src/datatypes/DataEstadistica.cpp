
#include <map>
#include <set>
#include <string>
#include <utility>

#include "../../headers/datatypes/DataEstadistica.h"
#include "../../headers/utils/enums.h"

DataEstadistica::DataEstadistica() {}

DataEstadistica::DataEstadistica(TipoEstadistica estadistica, float resultado) {
  this->estadistica = estadistica;
  this->resultado = resultado;
}

TipoEstadistica DataEstadistica::getEstadistica() { return this->estadistica; }

float DataEstadistica::getResultado() { return this->resultado; }

DataEstadistica::~DataEstadistica() {}
