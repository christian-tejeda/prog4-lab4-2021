#ifndef DATA_VIDEOJUEGO_H
#define DATA_VIDEOJUEGO_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../entities/Categoria.h"

using namespace std;

class DataVideojuego
{
private:
    string nombre;
    string descripcion;
    map<TipoPeriodoValidez, float> suscripciones; // Datatype Suscripcion
    set<Categoria *> categorias;
    string nombreEmpresa;

    //Posible implementacion del datatype Rating
    //rating.first = promedio
    //rating.second = totalVotos
    pair<float, int> rating;

public:
    DataVideojuego();
    DataVideojuego(string nombre, string descripcion, map<TipoPeriodoValidez, float> suscripciones, set<Categoria *> categorias, pair<float, int> rating);
    //Getters
    string getNombre() const;
    string getDescripcion() const;
    map<TipoPeriodoValidez, float> getSuscripciones() const;
    set<Categoria *> getNombreCategorias();
    //Los métodos addCategoria(cat), addPlataforma(plataforma), addGenero(genero) equivalen a aplicarle el metodo insert al set
    string getNombreEmgetNombreCategoriaspresa();
    pair<float, int> getRating();

    ~DataVideojuego();
};

#endif