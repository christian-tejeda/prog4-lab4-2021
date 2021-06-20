#include "headers/FactoryController.h"
//#include "headers/entities/Usuario.h"
#include "headers/controllers/VideojuegoController.h"
#include "headers/datatypes/DataCategoria.h"
#include "headers/datatypes/DataJugador.h"
#include "headers/datatypes/DataPartida.h"
#include "headers/datatypes/DataPartidaMultijugador.h"
#include "headers/datatypes/DataVideojuego.h"
//#include "headers/interfaces/IEliminarVideojuego.h"
#include "headers/entities/Videojuego.h"
#include "headers/interfaces/IAgregarCategoria.h"
#include "headers/interfaces/IAsignarPuntaje.h"
#include "headers/utils/Fecha.h"
#include "headers/handlers/UsuarioHandler.h"
#include "headers/handlers/CategoriaHandler.h"
#include "headers/handlers/VideojuegoHandler.h"
#include "headers/entities/Desarrollador.h"
#include "headers/utils/enums.h"

#include <bits/types/FILE.h>
#include <iostream>
#include <stdexcept>

void menuInicial()
{
    std::cout << "+---------------------- Menú Inicial -----------------------+\n";
    std::cout << "|                                                           |\n";
    std::cout << "|                    1) Alta de usuario                     |\n";
    std::cout << "|                    2) Iniciar sesión                      |\n";
    std::cout << "|                 3) Cargar datos de prueba                 |\n";
    std::cout << "|                        4) Salir                           |\n";
    std::cout << "|                                                           |\n";
    std::cout << "+-----------------------------------------------------------+\n";
}

void menuAltaUsuario(FactoryController *fact)
{

    IAltaUsuario *au = fact->getIAltaUsuario();

    int promptUser = 0;

    std::string mail = "";
    std::string pwd = "";

    std::cout << "Ingrese email: ";
    std::cin >> mail;
    std::cout << "\n";

    std::cout << "Ingrese contraseña: ";
    std::cin >> pwd;
    std::cout << "\n";

    std::cout << "Seleccione tipo de usuario a crear:\n";
    std::cout << "1) Jugador\n";
    std::cout << "2) Desarrollador\n";

    std::cout << ">";
    std::cin >> promptUser;
    std::cout << "\n";

    if (promptUser == 1) //Jugador
    {
        bool existeNick = true;
        std::string nick, desc;

        std::cin.ignore();
        std::cout << "Ingrese una descripción: ";
        std::getline(std::cin, desc);
        std::cout << "\n";

        while (existeNick)
        {
            std::cout << "Ingrese nickname: ";
            std::cin >> nick;
            std::cout << "\n";

            DataJugador *dtJg = new DataJugador(mail, pwd, nick, desc);
            try
            {
                au->ingresarDatosJugador(dtJg);
                existeNick = false;
            }
            catch (const std::invalid_argument &ex)
            {
                std::cout << ex.what() << '\n';
                existeNick = true;
                delete dtJg;
            }
        }
    }
    else if (promptUser == 2) //Desarrollador
    {
        std::string nomEmpresa = "";
        std::cout << "Ingrese nombre de empresa: ";
        std::cin >> nomEmpresa;
        std::cout << "\n";

        DataDesarrollador *dtDev = new DataDesarrollador(mail, pwd, nomEmpresa);
        au->ingresarDatosDesarrollador(dtDev);
    }
    else
    {
        throw std::invalid_argument("Error: Tipo de usuario no válido.");
    }

    bool confirmar;
    char promptConfirm = '\0';

    while (promptConfirm != 'y' && promptConfirm != 'n')
    {
        std::cout << "¿Confirmar alta de usuario? (y/n): ";
        std::cin >> promptConfirm;
        std::cout << "\n";
    }

    confirmar = promptConfirm == 'y' ? true : false;

    au->confirmarAltaUsuario(confirmar);
}

void menuIniciarSesion(FactoryController *fact, bool &jg, bool &dev)
{

    IIniciarSesion *iis = fact->getIIniciarSesion();

    std::string mail, pwd = "";

    std::cout << "Email: ";
    std::cin >> mail;
    std::cout << "\n";

    std::cout << "Contraseña: ";
    std::cin >> pwd;
    std::cout << "\n";

    bool cancelar = false;
    bool iniciada = iis->iniciarSesion(mail, pwd);
    char failedLogin = '\0';

    while (!iniciada && !cancelar)
    {
        std::cout << "Credenciales incorrectas. ¿Qué desea hacer?\n";
        std::cout << "1) Reintentar\n";
        std::cout << "2) Cancelar\n";

        while (failedLogin != '1' && failedLogin != '2')
        {
            std::cout << ">";
            std::cin >> failedLogin;
        }

        if (failedLogin == '1')
        {
            std::cout << "Email: ";
            std::cin >> mail;
            std::cout << "\n";

            std::cout << "Contraseña: ";
            std::cin >> pwd;
            std::cout << "\n";

            iniciada = iis->iniciarSesion(mail, pwd);
        }
        else
        {
            break;
        }
    }
    iis->confirmarInicioSesion(iniciada, mail, jg, dev);
}

void menuModificarFechaSistema(int &dia, int &mes, int &anio,int &hora,int &minuto) {
        std::cout << "Todos los valores deben ser enteros.";
        /*std::cout << "\n";
        std::cout << "Ingrese el anio: ";
        std::cin >> anio;
        std::cout << "\n";
        std::cout << "Ingrese mes: ";
        std::cin >> mes;
        std::cout << "\n";
        std::cout << "Ingrese el dia: ";
        std::cin >> dia;
        std::cout << "\n";
        std::cout << "Ingrese la hora: ";
        std::cin >> hora;
        std::cout << "\n";
        std::cout << "Ingrese el minuto: ";
        std::cin >> minuto;
        std::cout << "\n";*/
        std::cout << "Ingrese dia: ";
        std::cin >> dia;
        if (dia > 31 || dia < 1)
            throw std::invalid_argument("Error: El dia ingresado no es valido.");
        std::cout << "Ingrese mes: ";
        std::cin >> mes;
        if (mes > 12 || mes < 1)
            throw std::invalid_argument("Error: El mes ingresado no es valido.");
        std::cout << "Ingrese año: ";
        std::cin >> anio;
        if (anio < 0)
            throw std::invalid_argument("Error: El año ingresado no es valido.");
        std::cout << "Ingrese hora: ";
        std::cin >> hora;
        if (hora > 23 || hora < 0)
            throw std::invalid_argument("Error: La hora ingresada no es valida.");
        std::cout << "Ingrese minutos: ";
        std::cin >> minuto;
        if (minuto > 59 || minuto < 0)
            throw std::invalid_argument("Error: La hora ingresada no es valida.");
}

void menuCargarDatosPrueba(UsuarioHandler *uh, VideojuegoHandler *vh, CategoriaHandler *ch)
{

    //Carga de usuarios
    DataUsuario *d1 = new DataDesarrollador("ironhide@mail.com", "123", "Ironhide Game Studio");
    DataUsuario *d2 = new DataDesarrollador("epic@mail.com", "123", "Epic Games");
    DataUsuario *d3 = new DataDesarrollador("mojang@mail.com", "123", "Mojang Studios");
    DataUsuario *d4 = new DataDesarrollador("ea@mail.com", "123", "EA Sports");

    DataUsuario *j1 = new DataJugador("gamer@mail.com", "123", "gamer", "Descripcion de gamer");
    DataUsuario *j2 = new DataJugador("ari@mail.com", "123", "ari", "Descripcion de ari");
    DataUsuario *j3 = new DataJugador("ibai@mail.com", "123", "ibai", "Descripcion de ibai");
    DataUsuario *j4 = new DataJugador("camila@mail.com", "123", "camila", "Descripcion de camila");

    DataUsuario *j5 = new DataJugador("1", "1", "1", "Descripcion de 1");
    DataUsuario *d5 = new DataDesarrollador("2", "2", "ROCKSTARS");
    
    
    uh->agregarUsuario(d1);
    uh->agregarUsuario(d2);
    uh->agregarUsuario(d3);
    uh->agregarUsuario(d4);
    uh->agregarUsuario(j1);
    uh->agregarUsuario(j2);
    uh->agregarUsuario(j3);
    uh->agregarUsuario(j4);
    uh->agregarUsuario(j5);
    uh->agregarUsuario(d5);

    ch->crearNuevaCategoria("Accion", "", genero);
    ch->crearNuevaCategoria("Aventura", "", genero);
    ch->crearNuevaCategoria("Estrategia", "", genero);
    ch->crearNuevaCategoria("Deporte", "", genero);
    ch->crearNuevaCategoria("Supervivencia", "", genero);

    ch->crearNuevaCategoria("PC", "", plataforma);
    ch->crearNuevaCategoria("PS4", "", plataforma);
    ch->crearNuevaCategoria("XBox One", "", plataforma);
    ch->crearNuevaCategoria("Switch", "", plataforma);
    ch->crearNuevaCategoria("Xbox X", "", plataforma);
    ch->crearNuevaCategoria("PS5", "", plataforma);

    ch->crearNuevaCategoria("TTeen", "Su contenido esta dirigido a jovenes de 13 anos en adelante", otrasCategorias);
    ch->crearNuevaCategoria("E", "Su contenido esta dirigido para todo publico", otrasCategorias);

    delete d1;
    delete d2;
    delete d3;
    delete d4;
    delete j1;
    delete j2;
    delete j3;
    delete j4;
    delete j5;
    delete d5;



    //Carga de categorias
    //Carga de videojuegos
    std::cout << "¡Datos cargados correctamente!\n";
}

void menuSalirInicial()
{
    std::cout << "¡Hasta luego! \n";
}

void menuJugador(Usuario *sesion)
{
    std::cout << "+----------------------- Menú Jugador  ---------------------+\n";
    std::cout << "|                                                           |\n";
    std::cout << "|                 1) Suscribirse a videojuego               |\n";
    std::cout << "|               2) Asignar puntaje a videojuego             |\n";
    std::cout << "|                     3) Iniciar partida                    |\n";
    std::cout << "|              4) Abandonar partida multijugador            |\n";
    std::cout << "|                    5) Finalizar partida                   |\n";
    std::cout << "|               6) Ver información de videojuego            |\n";
    std::cout << "|                7) Modificar fecha del sistema             |\n";
    std::cout << "|                         8) Salir                          |\n";
    std::cout << "|                                                           |\n";
    std::cout << "+-----------------------------------------------------------+\n";
}

void menuSuscribirseVideojuego(FactoryController *fact)
{
}

void menuAsignarPuntaje(FactoryController *fact)
{
    IAsignarPuntaje * ap=fact->getIAsignarPuntaje();
    std::string nombre = "";
    int conf;
    std::cout << "Seleccione el Videojuego que desea ver la informacion:  \n";
    
    //VideojuegoController * vc;
    set<DataVideojuego *> data= ap->obtenerVideojuegos();
    set<DataVideojuego *>::iterator it;
    for (it = data.begin(); it != data.end(); it++)
    {
        DataVideojuego * imprimir=*it;
        std::cout << "\tNombre: "<< imprimir->getNombre() << "\t | \t" << "Descripcion:"<< imprimir->getDescripcion() << "    \n";  
    }
    std::cin >> nombre;
    std::cout << "\n";
    int punt;
    std::cout << "Seleccione un numero del 1 al 5 para puntuar al videojuego \n";
    std::cin >> punt;
    while(punt>5||punt<0){
         std::cout << "Seleccione un puntaje corrcto o  dijite cero(0) si desea cancelar\n";
         std::cin >> punt;
    }
    if(punt!=0) {
        ap->seleccionarVideojuego(nombre);
        ap->puntuarVideojuego(punt);
        std::cout << "El puntaje ha sido asignado\n";
    } else{
        std::cout << "Cancelacion satisfactoria\n";
    }
    ap->~IAsignarPuntaje();
}

void menuIniciarPartida(FactoryController *fact,Fecha fechainicio)
{
    IIniciarPartida *ip = fact->getIIniciarPartida();
    set<DataVideojuego*> videojuegosDeJgConSus = ip->obtenerVideojuegosDeJugadorConSuscripcionActiva();
    std::cout << "Videojuegos con Suscripcion: \n";
    set<DataVideojuego*>::iterator it;
    for(it = videojuegosDeJgConSus.begin();it != videojuegosDeJgConSus.end(); it++){
        std::cout << "Nombre videojuego: " << (*it)->getNombre() << "\n";
    }
    bool juegoValido = false;
    if(videojuegosDeJgConSus.size() != 0){
    while (!juegoValido){
        std::string nombreJueguito;
        std::cout << "Ingrese el nombre del videojuego que desea iniciar partida: ";
        std::cin >> nombreJueguito;
        try{
            juegoValido = true;
            ip->seleccionarVideojuego(nombreJueguito);
        }
        catch (const std::invalid_argument &ex){
            std::cout << ex.what() << '\n';
            juegoValido = false;
        }
    }
    char tipoPartida = '3';
    while(tipoPartida != '1' || tipoPartida != '2'){
        std::cout <<"Que tipo de partida desea iniciar?  \n  \n";
        std::cout <<"1 Partida Individual  \n";
        std::cout <<"2 Partida Multijugador \n";
        std::cin >> tipoPartida;
        if(tipoPartida != '1' && tipoPartida != '2' ){
            std::cout <<"Ingrese un numero valido  \n";
        }
    }
    if(tipoPartida == 1){//partida individual
        char continuaa = 'r';
        while(continuaa != 'y' || continuaa != 'n'){
            std::cout << "Desea continuar una partida? ";
            std::cin >> continuaa;
            std::cout << " \n";
        }
        if(continuaa == 'y'){//va a continuar una partida
            set<DataPartidaIndividual*> partidasfin = ip->obtenerPartidasFinalizadasDeJugador();
            if(partidasfin.size() != 0){//hay partidas para continuar
                std::cout << "Partidas finalizadas: \n";
                set<DataPartidaIndividual*>::iterator it;
                for(it = partidasfin.begin();it != partidasfin.end(); it++){
                    std::cout << "Nombre videojuego: " << (*it)->getVideojuego().getNombre();
                    std::cout << "  Id partida: " << (*it)->getId()<< " \n ";
                }
                int numeroPartida = -1;
                bool partidaValida = false;
                while(!partidaValida){//vamo a ver que meta un buen id
                    std::cout << "Ingrese el id de la partida: ";
                    std::cin >> numeroPartida;
                    try{
                        partidaValida = true;
                        ip->seleccionarPartidaAContinuar(numeroPartida);
                    }
                    catch (const std::invalid_argument &ex){
                    std::cout << ex.what() << '\n';
                    partidaValida = false;
                    }
                }
            }
            else{//no hay partidas para continuar
                std::cout << "No hay partidas finalizadas, se va a iniciar una nueva \n";
            }   
        }
        char confirmar = 'r';
        while(confirmar != 'y' || confirmar != 'n'){
            std::cout << "Desea confirmar el inicio de partida? (y/n) ";
            std::cin >> confirmar;
            std::cout << " \n";
        }
        bool confirmamo = false;
        if(confirmar == 'y')confirmamo = true;
        ip->confirmarIniciarPartida(confirmamo,&fechainicio);
    }
    else{//partida multijugador
        char transmitir = 'r';
        while(transmitir != 'y' || transmitir != 'n'){
            std::cout << "Desea que su partida sea transmitida en vivo? (y/n) ";
            std::cin >> transmitir;
            std::cout << " \n";
        }
        bool transmitimo = false;
        if(transmitir == 'y')transmitimo = true;
        std::cout << "Jugadores con suscripcion activa \n";
        set<DataJugador*> jugadores = ip->obtenerJugadoresConSuscripcionActiva();
        set<DataJugador*>::iterator it;
        set<std::string> nombreJugadoresConSus;
        for(it = jugadores.begin();it != jugadores.end(); it++){
            std::cout << "Nickname: " << (*it)->getNickname() << "\n";
            nombreJugadoresConSus.insert((*it)->getNickname());
            }
        char masJugadores = 'r';
        std::cout << "Desea agregar un jugador a la partida? (y/n) ";
        std::cin >> masJugadores;
        std:cout << "\n";
        while(masJugadores == 'y'){//agregando jugadores
            set<std::string>::iterator it2;
            std::string jugadorAgregar;
            std::cout << "Ingrese el nickname del jugador: ";
            std::cin >> jugadorAgregar;
            it2->find(jugadorAgregar);
            if(it2 == nombreJugadoresConSus.end()){
                std::cout <<"Jugador con ese nombre y suscripcion no encontrado, intente con otro \n";
            }
            else{
                std::cout <<"Jugador ingresado \n";
                ip->seleccionarJugador(jugadorAgregar);
            }
            char seguirAgregando = 'r';
            while(seguirAgregando != 'y' && seguirAgregando != 'n'){
                std::cout << "Desea agregar otro jugador a la partida? (y/n) \n";
                std::cin >> seguirAgregando;
            }
            if(seguirAgregando == 'y'){
                masJugadores = 'y';
            }
            else masJugadores = 'n';
        }
        char confirmar = 'r';
        while(confirmar != 'y' || confirmar != 'n'){
            std::cout << "Desea confirmar el inicio de partida? (y/n) ";
            std::cin >> confirmar;
            std::cout << " \n";
        }
        bool confirmamo = false;
        if(confirmar == 'y')confirmamo = true;
        ip->confirmarIniciarPartida(confirmamo,&fechainicio);

    }

}
    else {
        std::cout << "No tenes juegos :( \n";
    }

}

void menuAbandonarPartidaMulti(FactoryController *fact)
{
}

void menuFinalizarPartida(FactoryController *fact,Fecha * fecha)
{
    IFinalizarPartida *fp= fact->getIFinalizarPartida();
    set<DataPartida*> part=fp->obtenerPartidasSinFinalizarDeJugador();
    if (part.size()!=0){
        std::cout << "Seleccione la Partida a Finalizar:  \n";
        set<DataPartida*>::iterator it;
        for (it = part.begin();it != part.end(); it++){
            DataPartida * p=*it;
            std::cout << "Id: " << p->getId() << " \nFecha Comienzo (DIA/MES/ANO) : " << p->getFechaInicio().getDia() <<"/"<< p->getFechaInicio().getMes() <<"/"<< p->getFechaInicio().getAnio() <<"   " <<" \n Nombre Videojuego :" << p->getVideojuego().getNombre();
            DataPartidaIndividual* data = dynamic_cast<DataPartidaIndividual*>(p);
            DataPartidaMultijugador* nacional = dynamic_cast<DataPartidaMultijugador*>(p);
            if (data!=nullptr){
                std::string resp = data->getContinuacion() ? "si" : "no";
                std::cout << "Es continuacion?: " << resp << "\n";
            }
            else if (nacional!=nullptr){
                std::string resp = nacional->getTramistida() ? "si" : "no";
                std::cout << "Es trasmitida en Vivo?: " << resp << "\n";
                set<DataJugador*> participanetes=nacional->getParticipantes();
                set<DataJugador*>::iterator it;
                std::cout << "Jugadores Participantes" << resp << "\n";
                for (it = participanetes.begin();it != participanetes.end(); it++){
                    DataJugador * jugador=*it;
                    std::cout << "\t" << jugador->getNickname() << "\n";
                }
            }
            std::cout << " \n \n";
        }
        int seleccion;
        std::cin >>seleccion;
        fp->finalizarPartida(seleccion,fecha);
        std::cout << "La partida ha sido finalizada \n";
    }else { std::cout << "No se encontraron partidas sin finalizar\n";}
}

void menuVerInfoVideojuego(FactoryController *fact)
{
    IVerInfoVideojuego *iviv = fact->getIVerInfoVideojuego();

    std::string nombre = "";
    int conf;
    std::cout << "Seleccione el Videojuego que desea ver la informacion:  \n";
    
    //VideojuegoController * vc;
    set<DataVideojuego *> data= iviv->obtenerVideojuegos();
    set<DataVideojuego *>::iterator it;
    for (it = data.begin(); it != data.end(); it++)
    {
        DataVideojuego * imprimir=*it;
        std::cout << imprimir->getNombre() << "    -+\n";  
    }
    std::cin >> nombre;
    std::cout << "\n";
    DataVideojuego * datav = iviv->obtenerDataVideojuego(nombre);//controlar aca la cuestion si es Desaroollador o no 
    std::string empresa=datav->getNombreEmpresa();    
    map<TipoPeriodoValidez,float> suss=datav->getSuscripciones();
    std::cout<< suss.size();
    float mens=suss.find(mensual)->second;
    float tri=suss[trimestral];
    float anu=suss[anual];
    float vit=suss[vitalicia];
    
    float puntaje=0;
    if(datav->getRating().second!=0)
        float puntaje=datav->getRating().first/datav->getRating().second;
    set<std::string> nombrescat=datav->getNombreCategorias();
   
    float horas=datav->getHorasTotales();//hay que pedirle a partida controller.. es un poco largo para desarrollador.
    set<std::string>::iterator nuevo;
    std::cout << "+---------------- Datos Videojuego-----------------------+\n";
    std::cout << "\n";
    std::cout << "     Nombre        :"<<datav->getNombre() <<"\n";
    std::cout << "     Descripcion   :"<<datav->getDescripcion() << "\n";
    std::cout << "     Costos Suscrip:\n";
    std::cout << "      -mensual      :"<<mens<< "\n";
    std::cout << "      -trimensual   :"<<tri<< "\n";
    std::cout << "      -anual        :"<<anu<< "\n";
    std::cout << "      -vitalicia    :"<<vit<< "\n";
    std::cout << "     Categorias:\n";
    for (nuevo = nombrescat.begin(); nuevo != nombrescat.end(); nuevo++){
        std::cout << "      -"<<(*nuevo)<< "\n";
    }
    std::cout << "     NombreEmpresa  :"<<empresa<< "\n";
    std::cout << "     PuntajePromedio:"<<puntaje<< "\n";

    //solo si es desarrollador:
    if (datav->getHorasTotales()>=0){
           std::cout << "     HorasTotales   :"<< horas << "\n";
    } 
    std::cout << "+---------------- Datos Videojuego-----------------------+\n";
    
    //float horas=datav->getCantidadHoras();
    iviv->~IVerInfoVideojuego();
    
    
}

    

void menuSalirUsuario(FactoryController *fact)
{ //Mismo para jugador y dev
}

void menuDesarrollador(Usuario *sesion)
{
    std::cout << "+-------------------- Menú Desarrollador -------------------+\n";
    std::cout << "|                                                           |\n";
    std::cout << "|                   1) Agregar categoría                    |\n";
    std::cout << "|                  2) Publicar videojuego                   |\n";
    std::cout << "|                  3) Eliminar videojuego                   |\n";
    std::cout << "|                4) Seleccionar estadísticas                |\n";
    std::cout << "|                 5) Consultar estadísticas                 |\n";
    std::cout << "|              6) Ver información de videojuego             |\n";
    std::cout << "|               7) Modificar fecha del sistema              |\n";
    std::cout << "|                         8) Salir                          |\n";
    std::cout << "|                                                           |\n";
    std::cout << "+-----------------------------------------------------------+\n";
}

void menuAgregarCategoria(FactoryController *fact)
{
    IAgregarCategoria *ac=fact->getIAgregarCategoria();

    set<DataCategoria*> cats=ac->obtenerCategorias();
    set<DataCategoria*>::iterator it;
    std::cout << "----------------------------------------------------\n";
    for (it = cats.begin(); it != cats.end(); ++it){
        DataCategoria*hola=*it;
        std::string print= hola->getNombre();
        std::cout << "\t Nombre   | \t"<<print<< "   -\n";
        std::cout << "----------------------------------------------------\n";
    }
    std::cout << "+------------Que tipo de Categoria desea agregar?-----------+n";
    std::cout << "|                                                           |\n";
    std::cout << "|                    1) Plataforma                          |\n";
    std::cout << "|                      2) Genero                            |\n";
    std::cout << "|                  3) Otras Categorias                      |\n";
    std::cout << "|                                                           |\n";
    std::cout << "+-----------------------------------------------------------+\n";
    int opcion;
    std::cin >> opcion;
    while(opcion>3||opcion<1){
         std::cout << "Seleccione una opcion correcta, por favor\n";
         std::cin >> opcion;
    }
    TipoCategoria tipo;
    if (opcion==1){
        tipo=plataforma;
    }else if (opcion==2){
        tipo=genero;
    }
    else {
        tipo=otrasCategorias;
    }

    std::string agregar;
    std::string desc;
    std::cout << "Introduzca el nombre de la cateogria agregar\n";
    std::cin >> agregar;
    std::cout << "Introduzca la descripcion de la cateogria agregar\n";
    std::cin >> desc;
    std::cout << "Confirma que desea agregar esta nueva categoria?\n";
    std::cout << "    -Nombre: "<< agregar <<"\n";
    std::cout << "    -Descripcion: "<< desc <<"\n";
    std::cout << "1-Confirmar\n";
    std::cout << "2-Cancelar\n";
    int op2;
    std::cin >> op2;
    while(op2>2||op2<1){
         std::cout << "Seleccione una opcion correcta, por favor\n";
         std::cin >> op2;
    }
    //std::cin >> op2;
    ac->agregarCategoria(agregar,desc,tipo);
    ac->confirmarAgregarCategoria(op2==2);
    std::cout << "\n";
    ac->~IAgregarCategoria();
}

void menuPublicarVideojuego(FactoryController *fact) {
    IPublicarVideojuego *ipv = fact->getIPublicarVideojuego();

    std::string nombreVdj, descVdj;

    std::cin.ignore();
    std::cout << "Ingrese un nombre para el videojuego: ";
    std::getline(std::cin, nombreVdj);
    std::cin.ignore();
    std::cout << "Ingrese una descripción para el videojuego: ";
    std::getline(std::cin, descVdj);
    std::cout << "Ingrese el coste de cada periodo:\n";

    float precioMensual, precioTrimestral, precioAnual, precioVitalicia;
    std::cout << "Mensual: ";
    std::cin >> precioMensual;
    std::cout << "Trimestral: ";
    std::cin >> precioTrimestral;
    std::cout << "Anual: ";
    std::cin >> precioAnual;
    std::cout << "Vitalicia: ";
    std::cin >> precioVitalicia;

    std:map<TipoPeriodoValidez, float> suscripciones;
    suscripciones.insert(std::pair<TipoPeriodoValidez, float>(mensual, precioMensual));
    suscripciones.insert(std::pair<TipoPeriodoValidez, float>(trimestral, precioTrimestral));
    suscripciones.insert(std::pair<TipoPeriodoValidez, float>(anual, precioAnual));
    suscripciones.insert(std::pair<TipoPeriodoValidez, float>(vitalicia, precioVitalicia));
    
    
    DataVideojuego *nuevoDataVdj = new DataVideojuego(nombreVdj, descVdj, suscripciones, std::set<string>(), std::pair<float, int>(0, 0));
    ipv->ingresarDatosVideojuego(nuevoDataVdj);

    std::set<DataCategoria *> categorias = ipv->obtenerCategorias();
    set<DataCategoria*>::iterator it;
    std::cout << "----------------- Géneros --------------------------\n";
    std::cout << "Nombre \t Descripcion \n";
    std::cout << "----------------------------------------------------\n";
    for (it = categorias.begin(); it != categorias.end(); it++) {
        if ((*it)->getTipo() == genero) {
            DataCategoria *catActual = *it;
            std::cout << catActual->getNombre() << " \t " << catActual->getDescripcion() << "\n";
        }
    };

    std::string nombreCat;
    char promptConfirm = '\0';
    bool continuaAgregar = true;
    do {
        std::cin.ignore();
        std::cout << "Ingrese el nombre del genero: ";
        std::getline(std::cin, nombreCat);
        ipv->agregarCategoriaAVideojuego(nombreCat);
        std::cout << "¿Desea agregar más géneros? (y/n) ";
        std::cin >> promptConfirm;
        continuaAgregar = promptConfirm == 'y' ? true : false;
    } while (continuaAgregar);

    std::cout << "----------------- Plataformas ------------------------\n";
    std::cout << "Nombre \t Descripcion \n";
    std::cout << "----------------------------------------------------\n";
    for (it = categorias.begin(); it != categorias.end(); it++) {
        if ((*it)->getTipo() == plataforma) {
            DataCategoria *catActual = *it;
            std::cout << catActual->getNombre() << " \t " << catActual->getDescripcion() << "\n";
        }
    }

    promptConfirm = '\0';
    continuaAgregar = true;
    do {
        std::cin.ignore();
        std::cout << "Ingrese el nombre de la plataforma: ";
        std::getline(std::cin, nombreCat);
        ipv->agregarCategoriaAVideojuego(nombreCat);
        std::cout << "¿Desea agregar más plataformas? (y/n) ";
        std::cin >> promptConfirm;
        continuaAgregar = promptConfirm == 'y' ? true : false;
    } while (continuaAgregar);

    std::cout << "----------------- Otras categorías --------------------\n";
    std::cout << "Nombre \t Descripcion \n";
    std::cout << "----------------------------------------------------\n";
    for (it = categorias.begin(); it != categorias.end(); it++) {
        if ((*it)->getTipo() == otrasCategorias) {
            DataCategoria *catActual = *it;
            std::cout << catActual->getNombre() << " \t " << catActual->getDescripcion() << "\n";
        }
    }
    promptConfirm = '\0';
    continuaAgregar = true;
    std::cout << "¿Desea agregar otro tipo de categorías? (y/n) ";
    std::cin >> promptConfirm;
    continuaAgregar = promptConfirm == 'y' ? true : false;
    while (continuaAgregar) {
        std::cin.ignore();
        std::cout << "Ingrese el nombre de la categoría: ";
        std::getline(std::cin, nombreCat);
        ipv->agregarCategoriaAVideojuego(nombreCat);
        std::cout << "¿Desea agregar más categorías? (y/n) ";
        std::cin >> promptConfirm;
        continuaAgregar = promptConfirm == 'y' ? true : false;
    }

    ipv->obtenerDataVideojuegoIngresada();

    bool confirmar;
    promptConfirm = '\0';
    while (promptConfirm != 'y' && promptConfirm != 'n')
    {
        std::cout << "¿Confirmar publicación de videojuego? (y/n): ";
        std::cin >> promptConfirm;
    }
    confirmar = promptConfirm == 'y' ? true : false;
    ipv->confirmarPublicacionVideojuego(confirmar);
    ipv->~IPublicarVideojuego();
}

void menuEliminarVideojuego(FactoryController *fact)
{
    IEliminarVideojuego *ev = fact->getIEliminarVideojuego();

 
    std::string nombre = "";
    int conf;

    std::cout << "Seleccione el Videojuego a Eliminar:  \n";
    
    set<DataVideojuego *> data= ev->obtenerVideojuegosPublicadosPorDesarrolladorConPartidasFinalizadas();
    set<DataVideojuego *>::iterator it;
    for (it = data.begin(); it != data.end(); it++)
    {
        DataVideojuego * imprimir=*it;
        std::cout << imprimir->getNombre() << "    -+\n";  
    }
    
    std::cin >> nombre;
    std::cout << "\n";
    ev->seleccionarVideojuego(nombre);
    bool confirmar = false;

    std::cout << "Esta seguo de eliminar?: " << nombre << "?\n";
    std::cout << "seleccione el numero correspondiente\n";
    std::cout << "1-Si\n";
    std::cout << "2-No\n";

    std::cin >> conf;
    while(conf!=1||conf!=2){
        std::cout << "Ups! Hubo un error, seleccione un numero correcto por favor! \n";
        std::cin >> conf;
    }
    confirmar = conf == 1 ? true : false;

    ev->confirmarEliminarVideojuego(confirmar);
   if (conf==1){
        std::cout << "El videojuego "<< nombre << " ha sido eliminado... \n";
    }
}

void menuSeleccionarEstadisticas(FactoryController * fact)
{
    std::cout << "Bienvenido al menu de seleccionar estadisticas :D \n";
    ISeleccionarEstadisticas * se = fact->getISeleccionarEstadisticas();
    /*set<DataEstadistica*> estadisticas = se->listarEstadisticas();
    set<DataEstadistica*>::iterator it;
    for(it = estadisticas.begin();it != estadisticas.end();it++){
        std::cout << (*it)->get
    }*/
    bool quiereMas = true;
    int flag = 30;
    set<int> quiere;
    while(quiereMas){
        flag = 30;
        std::cout << "Digite la categoria que desea agregar: \n";
        std::cout << "1) Agregar total horas jugadas \n";
        std::cout << "2) Agregar Promedio rating \n";
        std::cout << "3) Agregar Cantidad Suscritos \n";
        std::cin >> flag;
        std::string aver = "q";

        switch(flag){
            case 1:
                std::cout << "Total horas jugadas agregado exitsosamente \n";
                quiere.insert(1);
                break;
            case 2:
                std::cout << "Promedio rating agregado exitosamente \n";
                quiere.insert(2);
                break;
            case 3:
                std::cout << "Cantidad suscritos agregado exitosamente \n";
                quiere.insert(3);
                break;
        }
        bool quiereMasMas = true;
        while(quiereMasMas){
        std::cout << "Desea agregar mas estadisticas? (y/n) \n";
        std::cin >> aver;
        if(aver == "n"){
            quiereMasMas = false;
            quiereMas = false;
        }
        else if(aver == "y"){
            quiereMasMas = false;
        }
        }

    }
    se->seleccionarEstadisticas(quiere);


}

void menuConsultarEstadisticas()
{
}

//-------------------- Programa Principal -----------------------------

int main(int argc, char const *argv[])
{
    //Creación de singletons
    UsuarioHandler *uh = UsuarioHandler::getInstance();
    CategoriaHandler *ch = CategoriaHandler::getInstance();
    VideojuegoHandler *vh = VideojuegoHandler::getInstance();

    UsuarioController *uc = UsuarioController::getInstance();

    FactoryController *fact = FactoryController::getInstance();

    //Creacion variables globales
    Fecha *fechaSist = new Fecha(1, 1, 2021, 15, 30); //Fecha de ejemplo

    bool salirInicial = false;
    bool salirJugador = true;
    bool salirDev = true;

    int prompt = 0;

    while (!salirInicial)
    {
        salirJugador = true;
        salirDev = true;

        menuInicial();

        std::cout << ">";
        std::cin >> prompt;
        std::cout << "\n";

        switch (prompt)
        {
        case 1: //Alta de usuario
            try
            {
                menuAltaUsuario(fact);
            }
            catch (const std::invalid_argument &ex)
            {
                std::cout << ex.what() << '\n';
            }

            break;
        case 2: //Iniciar sesión
            try
            {
                menuIniciarSesion(fact, salirJugador, salirDev);
            }
            catch (const std::invalid_argument &ex)
            {
                std::cout << ex.what() << '\n';
            }

            break;
        case 3: //Cargar Datos de Prueba
            try
            {
                menuCargarDatosPrueba(uh, vh, ch);
            }
            catch (const std::invalid_argument &ex)
            {
                std::cout << ex.what() << '\n';
            }
            break;
        case 4: //Salir inicial
            salirInicial = true;
            menuSalirInicial();
            break;
        default:
            std::cout << "Por favor, elija un numero adecuado.\n";
            break;
        }

        while (!salirJugador)
        {

            menuJugador(uc->getSesion());

            std::cout << ">";
            std::cin >> prompt;
            std::cout << "\n";

            switch (prompt)
            {
            case 1: //Suscribirse a videojuego
                try
                {
                    /* code */
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 2: //Asignar puntaje a videojuego
                try
                {
                    menuAsignarPuntaje(fact);
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 3: //Iniciar partida
                try
                {
                    menuIniciarPartida(fact,*fechaSist);
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 4: //Abandonar partida multijugador
                try
                {
                    /* code */
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 5: //Finalizar partida
                try
                {
                    menuFinalizarPartida(fact,fechaSist);
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 6: //Ver información de videojuego
                try
                {
                    menuVerInfoVideojuego(fact);
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 7: // Modificar fecha del sistema
                try
                {
                    int dia = 0;
                    int mes = 0;
                    int anio = 0;
                    int hora = 0;
                    int minuto = 0;
                    void menuModificarFechaSistema(int dia, int mes, int anio,int hora,int minuto);
                    delete fechaSist;
                    fechaSist = new Fecha(dia,mes,anio,hora,minuto);

                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 8: // Salir Jugador
                salirJugador = true;
                //menuSalirUsuario(fact);
                break;

            default:
                std::cout << "Por favor, elija un numero adecuado.\n";
                break;
            }
        }

        while (!salirDev)
        {
            menuDesarrollador(uc->getSesion());

            std::cout << ">";
            std::cin >> prompt;
            std::cout << "\n";

            switch (prompt)
            {
            case 1: // Agregar categoría
                try
                {
                   menuAgregarCategoria(fact);
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 2: //Publicar videojuego
                try
                {
                    menuPublicarVideojuego(fact);
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 3: //Eliminar videojuego
                try
                {
                    menuEliminarVideojuego(fact);
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 4: //Seleccionar estadísticas
                try
                {
                    menuSeleccionarEstadisticas(fact);
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 5: //Consultar estadísticas
                try
                {
                    /* code */
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 6: //Ver información de videojuego
                try
                {
                    menuVerInfoVideojuego(fact);
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 7: // Modificar fecha del sistema
                try
                {
                    int dia = 0;
                    int mes = 0;
                    int anio = 0;
                    int hora = 0;
                    int minuto = 0;
                    menuModificarFechaSistema(dia,mes, anio,hora,minuto);
                    delete fechaSist;
                    fechaSist = new Fecha(dia,mes,anio,hora,minuto);

                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 8: //Salir Dev
                salirDev = true;
                //menuSalirUsuario(fact);
                break;

            default:
                std::cout << "Por favor, elija un numero adecuado.\n";
                break;
            }
        }
    }

    //Destruccion de singletons
    vh->releaseInstance();
    uc->releaseInstance();
    uh->releaseInstance();
    ch->releaseInstance();

    fact->releaseInstance();

    //Destruccion variables globales
    delete fechaSist;

    return 0;
}
