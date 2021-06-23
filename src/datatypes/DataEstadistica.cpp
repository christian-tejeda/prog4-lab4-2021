
#include <map>
#include <set>
#include <string>
#include <utility>

#include "../../headers/datatypes/DataEstadistica.h"
#include "../../headers/utils/enums.h"

DataEstadistica::DataEstadistica() {}

DataEstadistica::DataEstadistica(TipoEstadistica estadistica, float resultado)
{
  this->estadistica = estadistica;
  this->resultado = resultado;
}

TipoEstadistica DataEstadistica::getEstadistica() { return this->estadistica; }

ostream &operator<<(ostream &os, const DataEstadistica &dataSuscJugador)
{

  string estadistica;

  switch (dataSuscJugador.estadistica)
  {
  case horasJugadas:
    estadistica = "Horas jugadas: ";
    break;
  case promedioRating:
    estadistica = "Promedio rating: ";
    break;
  case cantidadSuscritos:
    estadistica = "Cantidad suscritos: ";
    break;
  default:
    estadistica = "";
  }

  string resultado = std::to_string(dataSuscJugador.resultado);

  os << estadistica << resultado;

  return os;
}

float DataEstadistica::getResultado() { return this->resultado; }

DataEstadistica::~DataEstadistica() {}
