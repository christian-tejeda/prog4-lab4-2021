#ifndef DATA_VIDEOJUEGO_H
#define DATA_VIDEOJUEGO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../enums.h"

using namespace std;

class DataVideojuego
{
private:
    string nombre;
    string descripcion;
    map<TipoPeriodoValidez, float> suscripciones; // Datatype Suscripcion
    set<string> nombreCategorias;
    string nombreEmpresa;

    //Posible implementacion del datatype Rating
    //rating.first = promedio
    //rating.second = totalVotos
    pair<float, int> rating;

public:
    DataVideojuego();
    DataVideojuego(string nombre, string descripcion, map<TipoPeriodoValidez, float> suscripciones, set<string> nombreCategorias);
    //Getters
    string getNombre() const;
    string getDescripcion() const;
    map<TipoPeriodoValidez, float> getSuscripciones() const;
    set<string> getNombreCategorias();
    //Los métodos addCategoria(cat), addPlataforma(plataforma), addGenero(genero) equivalen a aplicarle el metodo insert al set
    string getNombreEmpresa();
    pair<float, int> getRating();

    ~DataVideojuego();
};

#endif