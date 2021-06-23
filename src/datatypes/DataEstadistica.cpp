#include "../../headers/datatypes/DataEstadistica.h"

DataEstadistica::DataEstadistica()
{
  resultado = -1;
}

DataEstadistica::DataEstadistica(const DataEstadistica &data)
{
  estadistica = data.estadistica;
  resultado = data.resultado;
}

DataEstadistica::DataEstadistica(TipoEstadistica estadistica, float resultado)
{
  estadistica = estadistica;
  resultado = resultado;
}

TipoEstadistica DataEstadistica::getEstadistica() const { return estadistica; }

float DataEstadistica::getResultado() const { return resultado; }

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

  string resultado = to_string(dataSuscJugador.resultado);

  os << estadistica << resultado;

  return os;
}

bool operator<(const DataEstadistica &d1, const DataEstadistica &d2)
{
  return &d1 < &d2;
}

bool operator!=(const DataEstadistica &d1, const DataEstadistica &d2)
{
  return d1.getEstadistica() != d2.getEstadistica() || d1.getResultado() != d2.getResultado();
}

DataEstadistica::~DataEstadistica() {}
