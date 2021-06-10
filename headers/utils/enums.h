#ifndef ENUMS_H
#define ENUMS_H

enum EstadoSuscripcion
{
    activa,
    inactiva,
    cualquiera
};

enum TipoMetodoPago
{
    tarjeta,
    paypal
};

enum TipoPeriodoValidez
{
    mensual,
    trimestral,
    anual,
    vitalicia
};

enum TipoGenero
{
    accion,
    aventura,
    estrategia,
    deporte
};

enum TipoPlataforma
{
    pc,
    nintendo_switch,
    ps4,
    xboxone,
    ps5,
    xboxx
};

enum TipoEstadistica
{
    horasJugadas,
    promedioRating,
    cantidadSuscritos
};

#endif