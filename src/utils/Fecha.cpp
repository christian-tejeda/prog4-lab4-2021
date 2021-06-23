#include "../../headers/utils/Fecha.h"
#include <iomanip>
#include <string>

#include <iostream>

Fecha::Fecha()
{
  anio = mes = dia = hora = minuto = -1;
};

Fecha::Fecha(const Fecha &fecha)
{
  anio = fecha.anio;
  mes = fecha.mes;
  dia = fecha.dia;
  hora = fecha.hora;
  minuto = fecha.minuto;
};

Fecha::Fecha(int dia, int mes, int anio, int hora, int minuto)
{
  anio = anio;
  mes = mes;
  dia = dia;
  hora = hora;
  minuto = minuto;
};

int Fecha::getDia() const { return dia; };

int Fecha::getMes() const { return mes; };

int Fecha::getAnio() const { return anio; };

int Fecha::getHora() const { return hora; };

int Fecha::getMinuto() const { return minuto; };

bool Fecha::operator==(Fecha opFecha)
{
  return dia == opFecha.dia && mes == opFecha.mes && anio == opFecha.anio &&
         hora == opFecha.hora && minuto == opFecha.minuto;
};

bool operator!=(const Fecha &f1, const Fecha &f2)
{
  return f1.getAnio() != f2.getAnio() || f1.getMes() || f2.getMes() || f1.getDia() != f2.getDia() || f1.getHora() != f2.getHora() || f1.getMinuto() != f2.getMinuto();
}

int Fecha::contarAniosBisiestos(const Fecha &f)
{
  int anios = f.anio;
  if (f.mes <= 2)
    anios--;
  return anios / 4 - anios / 100 + anios / 400;
}

float Fecha::operator-(const Fecha &f)
{
  //meses
  const int mesesDias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  //se calcula en horas el 1er argumento
  double horas1 = anio * 365 * 24 + dia * 24 + hora + minuto * (1 / 60);
  for (int i = 0; i < mes - 1; i++)
    horas1 += (double)(mesesDias[i] * 24);
  horas1 += (double)contarAniosBisiestos(*this);

  //se calcula en horas el 2do argumento
  double horas2 = f.anio * 365 * 24 + f.dia * 24 + f.hora + f.minuto * (1 / 60);
  for (int i = 0; i < f.mes - 1; i++)
    horas2 += (double)(mesesDias[i] * 24);
  horas2 += (double)contarAniosBisiestos(f);

  double printDiff = (double)(horas1 - horas2);
  if (horas1 - horas2 > (double)0)
    return (double)(horas1 - horas2);
  else
    return (double)(horas2 - horas1);
}

ostream &operator<<(ostream &os, Fecha f)
{
  os << setfill('0') << setw(2) << f.getDia() << '/'
     << setfill('0') << setw(2) << f.getMes() << '/'
     << f.getAnio() << " , "
     << setfill('0') << setw(2) << f.getHora() << ':'
     << setfill('0') << setw(2) << f.getMinuto();
  return os;
};

Fecha::~Fecha(){};