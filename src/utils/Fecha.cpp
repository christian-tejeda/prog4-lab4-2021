#include "../../headers/utils/Fecha.h"
#include <iomanip>
#include <string>

#include <iostream>

Fecha::Fecha(){};

Fecha::Fecha(const Fecha &fecha)
{
  this->anio = fecha.anio;
  this->mes = fecha.mes;
  this->dia = fecha.dia;
  this->hora = fecha.hora;
  this->minuto = fecha.minuto;
};

Fecha::Fecha(int dia, int mes, int anio, int hora, int minuto)
{
  this->anio = anio;
  this->mes = mes;
  this->dia = dia;
  this->hora = hora;
  this->minuto = minuto;
};

int Fecha::getDia() { return this->dia; };

int Fecha::getMes() { return this->mes; };

int Fecha::getAnio() { return this->anio; };

int Fecha::getHora() { return this->hora; };

int Fecha::getMinuto() { return this->minuto; };

bool Fecha::operator==(Fecha opFecha)
{
  return dia == opFecha.dia && mes == opFecha.mes && anio == opFecha.anio &&
         hora == opFecha.hora && minuto == opFecha.minuto;
};

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
  float horas1 = anio * 365 * 24 + dia * 24 + hora + minuto * (1 / 60);
  for (int i = 0; i < mes - 1; i++)
    horas1 += mesesDias[i] * 24;
  horas1 += contarAniosBisiestos(*this);

  //se calcula en horas el 2do argumento
  float horas2 = f.anio * 365 * 24 + f.dia * 24 + f.hora + f.minuto * (1 / 60);
  for (int i = 0; i < f.mes - 1; i++)
    horas2 += mesesDias[i] * 24;
  horas2 += contarAniosBisiestos(f);

  return horas1 - horas2;
}

std::ostream &operator<<(std::ostream &os, Fecha f)
{
  os << std::setfill('0') << std::setw(2) << f.getDia() << '/'
     << std::setfill('0') << std::setw(2) << f.getMes() << '/'
     << f.getAnio() << " , "
     << std::setfill('0') << std::setw(2) << f.getHora() << ':'
     << std::setfill('0') << std::setw(2) << f.getMinuto();
  return os;
};

Fecha::~Fecha(){};