
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataContratoSuscripcion.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

DataContratoSuscripcion::DataContratoSuscripcion() {}

DataContratoSuscripcion::DataContratoSuscripcion(bool activa, string nombreVideojuego, string nombreJugador, float precio, TipoPeriodoValidez periodoValidez, bool cancelada, Fecha fecha, TipoMetodoPago metodoPago)
{
    this->activa = activa;
    this->cancelada = cancelada;
    this->metodoPago = metodoPago;
    this->periodoValidez = periodoValidez;
    this->fechaSuscripcion = fecha;
    this->precio = precio;
}

bool DataContratoSuscripcion::getActiva() const
{
    return this->activa;
}

string DataContratoSuscripcion::getNombreVideojuego() const
{
    return this->nombreVideojuego;
}

float DataContratoSuscripcion::getPrecio() const
{
    return this->precio;
}

TipoPeriodoValidez DataContratoSuscripcion::getPeriodoValidez() const
{
    return this->periodoValidez;
}
bool DataContratoSuscripcion::getCancelada() const
{
    return this->cancelada;
}
Fecha DataContratoSuscripcion::getFechaSuscripcion() const
{
    return this->fechaSuscripcion;
}

TipoMetodoPago DataContratoSuscripcion::getMetodoPago() const
{
    return this->metodoPago;
}

DataContratoSuscripcion::~DataContratoSuscripcion() {}