#ifndef DATA_VIDEOJUEGO_H
#define DATA_VIDEOJUEGO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"

using namespace std;

class DataVideojuego
{
private:
    string nombre;
    string descripcion;
    map<TipoPeriodoValidez, float> suscripciones; // Datatype Suscripcion
    set<string> categorias;
    string nombreEmpresa;

    //Posible implementacion del datatype Rating
    //rating.first = promedio
    //rating.second = totalVotos
    pair<float, int> rating;
    float horastotales;

public:
    DataVideojuego();
    DataVideojuego(string nombre, string descripcion, map<TipoPeriodoValidez, float> suscripciones, set<string> categorias, pair<float, int> rating);
    //Getters
    string getNombre() const;
    string getDescripcion() const;
    map<TipoPeriodoValidez, float> getSuscripciones() const;
    set<string> getNombreCategorias();
    //Los métodos addCategoria(cat), addPlataforma(plataforma), addGenero(genero) equivalen a aplicarle el metodo insert al set
    string getNombreEmpresa();
    float getHorasTotales();
    pair<float, int> getRating();

    void setNombreEmpresa(std::string nombreEmpresa);
    void setHorasTotales(float horas);

    void agregarCategoria(std::string categoria);
    ~DataVideojuego();
};

#endif