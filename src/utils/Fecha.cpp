#include <string>
#include <iomanip>
#include "../../headers/utils/Fecha.h"


#include <iostream>

Fecha::Fecha(){};

Fecha::Fecha(const DtFechaHora &fecha)
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
    return dia == opFecha.dia && mes == opFecha.mes && anio == opFecha.anio && hora == opFecha.hora && minuto == opFecha.minuto;
};

std::ostream &operator<<(std::ostream &os, const Fecha &f)
{
    os << std::setfill('0') << std::setw(2) << f.getDia() << '/'
       << std::setfill('0') << std::setw(2) << f.getMes() << '/'
       << f.getAnio() << " , "
       << std::setfill('0') << std::setw(2) << f.getHora() << ':'
       << std::setfill('0') << std::setw(2) << f.getMinuto();
    return os;
};

Fecha::~Fecha(){};