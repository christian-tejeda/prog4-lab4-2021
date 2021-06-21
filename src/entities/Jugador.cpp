#include "../../headers/entities/Jugador.h"

Jugador::Jugador() : Usuario(){};

Jugador::Jugador(std::string email, std::string password, std::string nickname,
                 std::string descripcion)
    : Usuario(email, password) {
  this->nickname = nickname;
  this->descripcion = descripcion;
}

std::string Jugador::getNickname() { return this->nickname; }
std::string Jugador::getDescripcion() { return this->descripcion; }

void Jugador::setNickname(std::string nick) { this->nickname = nick; }

void Jugador::setDescripcion(std::string descripcion) {
  this->descripcion = descripcion;
}

void Jugador::cancelarSuscripcionActiva(Videojuego *vj) {
  std::set<ContratoSuscripcion *> contratos = this->contratos;
  std::set<ContratoSuscripcion *>::iterator it;

  bool cancelado = false;
  for (it = contratos.begin(); it != contratos.end() && !cancelado; it++) {
    ContratoSuscripcion *contrato = (*it);
    if (contrato->perteneceAVideojuego(vj)) {
      if (contrato->esActivo()) {
        contrato->cancelar();
        cancelado = true;
      }
    }
  }
}

void Jugador::contratarSuscripcion(Videojuego *vj, TipoPeriodoValidez validez,
                                   TipoMetodoPago metodoPago) {
  this->contratos.insert(
      new ContratoSuscripcion(this, vj, metodoPago, validez));
}

map<int, Partida *> Jugador::obtenerPartidasSinFinalizar() {
  map<int, Partida *> res;
  map<int, Partida *>::iterator it;
  for (it = this->partidasIniciadas.begin(); it != this->partidasIniciadas.end(); it++) {
    if (it->second->getFechaFin()==nullptr){
        res.insert(*it);
    }
  }
  return res;
}

void Jugador::finalizarPartida(int idPartida,Fecha * fecha) {
    //map<int,Partida*> part= this->partidasIniciadas;
    //PartidaIndividual* indi = dynamic_cast<PartidaIndividual*>(this->partidasIniciadas.find(idPartida)->second);
    //PartidaMultijugador* multi = dynamic_cast<PartidaMultijugador*>(this->partidasIniciadas.find(idPartida)->second);
    //if(indi!=nullptr){
    //  indi->terminar;
    Partida * terminar=partidasIniciadas.find(idPartida)->second;
    terminar->finalizar(fecha);
}

map<string, Videojuego *> Jugador::obtenerVideojuegos() {
  return map<string, Videojuego *>();
}

void Jugador::eliminarContratosDeVideojuego(Videojuego *vj) {
  set<ContratoSuscripcion *> cont = this->contratos;
  set<ContratoSuscripcion *>::iterator it;
  while ( it != cont.end(); it++) {
    ContratoSuscripcion *contr = *it;
    bool pertenece = contr->perteneceAVideojuego(vj);
    if (pertenece) {
      this->contratos.erase(*it);
      it++;
      delete contr;
    }
  }
}

void Jugador::eliminarPartidasDeVideojuego(Videojuego *vj) {
  map<int, Partida *> partidas = this->partidasIniciadas;
  map<int, Partida *>::iterator it;
  for (it = partidas.begin(); it != partidas.end(); it++) {
    Partida *par = (it->second);
    Videojuego *video = par->getVideojuego();
    if (vj == video) {
      par->eliminarPartidasVideojuego(vj);
      this->partidasIniciadas.erase(it->first);
      delete par;
    }
  }
}

DataUsuario *Jugador::getData() { return nullptr; }

//PartidaIndividual *Jugador::obtenerPartida(string id) { return nullptr; }

bool tieneSuscripcionActiva(Videojuego *vj) { return false; }

bool Jugador::tienePartidaSinFinalizar(Videojuego *vj) {
  map<int, Partida *> partidas = this->partidasIniciadas;
  map<int, Partida *>::iterator it;
  it = partidas.begin();
  Partida *partida;
  bool tiene;
  while (it != partidas.end() && !tiene) {
    //PartidaIndividual *partida = dynamic_cast<PartidaIndividual *>(it->second);
    tiene = !(partida->esFinalizada());
    it++;
  }
  return tiene;
}

int Jugador::obtenerDuracionPartida(Videojuego *vj) {
  map<int, Partida *> partidas = this->partidasIniciadas;
  map<int, Partida *>::iterator it;
  int res = 0;
  for (it = partidas.begin(); it != partidas.end(); it++) {
    Partida *partida = it->second;
    // PartidaIndividual*partida=dynamic_cast<PartidaIndividual *>(it->second);
    Videojuego *video = partida->getVideojuego();
    if (vj == video) {
      int sumar = partida->getDuracionTotal();
      res += sumar;
    }
  }
  return res;
}

std::set<ContratoSuscripcion *> Jugador::obtenerContratosActivos() {
  std::set<ContratoSuscripcion *> activos = std::set<ContratoSuscripcion *>();

  std::set<ContratoSuscripcion *>::iterator it;
  for (it = this->contratos.begin(); it != this->contratos.end(); it++) {
    ContratoSuscripcion *contrato = (*it);
    if (contrato->esActivo()) {
      activos.insert(contrato);
    }
  }

  return activos;
}

float Jugador::calcularTotalHorasPartidasIniciadas(Videojuego *videojuego) {
  float res = 0;
  map<int, Partida *> partidasIniciadas = this->partidasIniciadas;

  map<int, Partida *>::iterator it;
  for (it = partidasIniciadas.begin(); it != partidasIniciadas.end(); it++) {
    Partida *partida = (it->second);
    Videojuego *currentVideojuego = partida->getVideojuego();

    if (currentVideojuego == videojuego) {
      res += partida->getDuracionTotal();
    }
  }

  return res;
}

map<int, PartidaIndividual *> Jugador::obtenerPartidasFinalizadas()//pronta ?)
{
    map<int,Partida *>::iterator it;
    map<int,PartidaIndividual*> res;
    for(it = this->partidasIniciadas.begin();it != this->partidasIniciadas.end(); it++){
        if(it->second->esFinalizada()){
            PartidaIndividual* testpartida = dynamic_cast<PartidaIndividual*>(it->second);
            if(testpartida != nullptr){
                res.insert({it->first,dynamic_cast<PartidaIndividual*>(it->second)});
            }
        }   
    }
    return res;
}

PartidaIndividual *Jugador::obtenerPartida(int id)
{
    return dynamic_cast<PartidaIndividual*>(partidasIniciadas.find(id)->second);
}

bool Jugador::tieneSuscripcionActiva(Videojuego *vj)
{
    set<ContratoSuscripcion*>::iterator it;
    for(it = this->contratos.begin();it != this->contratos.end();it++){
        if((*it)->esActivo() && (*it)->perteneceAVideojuego(vj)){
            return true;
        }
    }
    return false;
}
/*
bool Jugador::tienePartidaSinFinalizar(Videojuego *vj){//operacion faltante en obtenerpartidasfinalizadas en elim videojuego
    map<int, Partida *> partidas=this->partidasIniciadas;
    map<int, Partida *>::iterator it;
    it = partidas.begin();
    PartidaIndividual*partida=dynamic_cast<PartidaIndividual *>(it->second);
    bool tiene=(partida->getFechaFin()==nullptr);
    while(it != partidas.end()&&!tiene){
        it++;
        PartidaIndividual*partida=dynamic_cast<PartidaIndividual *>(it->second);
        tiene=(partida->getFechaFin()==nullptr);
    }
  }*///QUEDO REDEFINDA ABAJO, BORRAR SI SE NECEISTA.. VER

map<std::string,Videojuego*> Jugador::obtenerVideojuegosConSuscripcionActiva(){
    map<std::string,Videojuego*> res;
    set<ContratoSuscripcion*>::iterator it;
    for(it = this->contratos.begin();it!= this->contratos.end(); it++){
        if((*it)->esActivo()){
            res.insert({(*it)->getVideojuego()->getNombre(),(*it)->getVideojuego()});
        }
    }
    return res;
}

void Jugador::crearPartidaIndividual(int idPartida,Fecha fechaActual,Videojuego * vj,Jugador *host,PartidaIndividual * cont){
    if(cont == nullptr){
        PartidaIndividual * parti =new PartidaIndividual(idPartida,fechaActual,nullptr,0,vj,this,nullptr);
        this->partidasIniciadas.insert({idPartida,parti});
    }
    else{
        map<int,Partida*>::iterator it;
        it = this->partidasIniciadas.find(idPartida);
        float duracioon = dynamic_cast<PartidaIndividual *>(it->second)->getDuracionTotal();
        this->partidasIniciadas.erase(idPartida);
        PartidaIndividual * parti =new PartidaIndividual(idPartida,fechaActual,nullptr,duracioon,vj,this,cont);
        this->partidasIniciadas.insert({idPartida,parti});
    }
}

void Jugador::crearPartidaMultijugador(int idPartida, Fecha fechaActual, Fecha *fechaFin, Videojuego * vj, bool transmitida, Jugador * host, map<string, Jugador *> participantes){
    set<DuracionParticipante * > durpart;
    map<string,Jugador*>::iterator it;
    DuracionParticipante * durparticipantehost = new DuracionParticipante(&fechaActual,nullptr,host);
    durpart.insert(durparticipantehost);
    for(it = participantes.begin();it != participantes.end();it++){
        DuracionParticipante * durparticipante = new DuracionParticipante(&fechaActual,nullptr,it->second);
        durpart.insert(durparticipante);
    }
    PartidaMultijugador * partim = new PartidaMultijugador(idPartida, fechaActual, nullptr,0,vj,host,transmitida,durpart);
    this->partidasIniciadas.insert({idPartida,partim});
}

Jugador::~Jugador(){};
