#ifndef DATA_VIDEOJUEGO_H
#define DATA_VIDEOJUEGO_H

#include <string>
#include <map>
#include <set>

#include "../utils/enums.h"

using namespace std;

class DataVideojuego
{
private:
    string nombre;
    string descripcion;
    map<TipoPeriodoValidez, float> suscripciones;
    set<string> categorias;
    string nombreEmpresa;

    pair<float, int> rating;
    float horastotales;

public:
    DataVideojuego();
    DataVideojuego(const DataVideojuego &data);
    DataVideojuego(string nombre, string descripcion, map<TipoPeriodoValidez, float> suscripciones, set<string> categorias, pair<float, int> rating);

    string getNombre() const;
    string getDescripcion() const;
    map<TipoPeriodoValidez, float> getSuscripciones() const;
    set<string> getNombreCategorias() const;

    string getNombreEmpresa() const;
    float getHorasTotales() const;
    pair<float, int> getRating() const;

    void setNombreEmpresa(string nombreEmpresa);
    void setHorasTotales(float horas);
    void agregarCategoria(string categoria);

    friend bool operator<(const DataVideojuego &d1, const DataVideojuego &d2);
    friend bool operator!=(const DataVideojuego &d1, const DataVideojuego &d2);

    ~DataVideojuego();
};

#endif