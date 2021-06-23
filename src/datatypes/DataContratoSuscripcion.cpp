
#include <string>

#include "../../headers/datatypes/DataContratoSuscripcion.h"

using namespace std;

DataContratoSuscripcion::DataContratoSuscripcion()
{
    nombreVideojuego = "";
    nombreJugador = "";
}

DataContratoSuscripcion::DataContratoSuscripcion(const DataContratoSuscripcion &data)
{
    activa = data.activa;
    nombreJugador = data.nombreJugador;
    nombreVideojuego = data.nombreVideojuego;
    cancelada = data.cancelada;
    metodoPago = data.metodoPago;
    periodoValidez = data.periodoValidez;
    fechaSuscripcion = data.fechaSuscripcion;
    precio = data.precio;
}

DataContratoSuscripcion::DataContratoSuscripcion(bool activa, string nombreVideojuego, string nombreJugador, float precio, TipoPeriodoValidez periodoValidez, bool cancelada, Fecha fecha, TipoMetodoPago metodoPago)
{
    activa = activa;
    nombreVideojuego = nombreVideojuego;
    nombreJugador = nombreJugador;
    cancelada = cancelada;
    metodoPago = metodoPago;
    periodoValidez = periodoValidez;
    fechaSuscripcion = fecha;
    precio = precio;
}

bool DataContratoSuscripcion::getActiva() const { return activa; }

string DataContratoSuscripcion::getNombreVideojuego() const { return nombreVideojuego; }

string DataContratoSuscripcion::getNombreJugador() const { return nombreJugador; }

float DataContratoSuscripcion::getPrecio() const { return precio; }

TipoPeriodoValidez DataContratoSuscripcion::getPeriodoValidez() const { return periodoValidez; }

bool DataContratoSuscripcion::getCancelada() const { return cancelada; }

Fecha DataContratoSuscripcion::getFechaSuscripcion() const { return fechaSuscripcion; }

TipoMetodoPago DataContratoSuscripcion::getMetodoPago() const { return metodoPago; }

bool operator<(const DataContratoSuscripcion &d1, const DataContratoSuscripcion &d2)
{
    return &d1 < &d2;
}

bool operator!=(const DataContratoSuscripcion &d1, const DataContratoSuscripcion &d2)
{
    return d1.getActiva() != d2.getActiva() || d1.getCancelada() != d2.getCancelada() || d1.getFechaSuscripcion() != d2.getFechaSuscripcion() || d1.getMetodoPago() != d2.getMetodoPago() || d1.getNombreJugador() != d2.getNombreJugador() || d1.getNombreVideojuego() != d2.getNombreVideojuego() || d1.getPeriodoValidez() != d2.getPeriodoValidez() || d1.getPrecio() != d2.getPrecio();
}

DataContratoSuscripcion::~DataContratoSuscripcion() {}