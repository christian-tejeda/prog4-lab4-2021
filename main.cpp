#include "headers/FactoryController.h"
//#include "headers/entities/Usuario.h"
#include "headers/utils/Fecha.h"
#include "headers/handlers/UsuarioHandler.h"
#include "headers/handlers/CategoriaHandler.h"
#include "headers/handlers/VideojuegoHandler.h"

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

        std::cout << "Ingrese una descripción: ";
        std::cin >> desc;
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

void menuIniciarSesion(FactoryController *fact) {}

void menuModificarFechaSistema(int &dia, int &mes, int &anio,int &hora,int &minuto) {
        std::cout << "Todos los valores deben ser enteros.";
        std::cout << "\n";
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
        std::cout << "\n";

}

void menuCargarDatosPrueba(FactoryController *fact) {}

void menuSalirInicial()
{
    std::cout << "¡Hasta luego! \n";
}

void menuJugador(Usuario *sesion)
{
    std::cout << "+--------------------- Bienvenidx, " << sesion->getEmail() << " -+\n";
    std::cout << "|                                                           |\n";
    std::cout << "|               1) Suscribirse a videojuego                 |\n";
    std::cout << "|             2) Asignar puntaje a videojuego               |\n";
    std::cout << "|                   3) Iniciar partida                      |\n";
    std::cout << "|            4) Abandonar partida multijugador              |\n";
    std::cout << "|                  5) Finalizar partida                     |\n";
    std::cout << "|             6) Ver información de videojuego              |\n";
    std::cout << "|              7) Modificar fecha del sistema               |\n";
    std::cout << "|                       8) Salir                            |\n";
    std::cout << "|                                                           |\n";
    std::cout << "+-----------------------------------------------------------+\n";
}

void menuSuscribirseVideojuego(FactoryController *fact)
{
}

void menuAsignarPuntaje(FactoryController *fact)
{
}

void menuIniciarPartida(FactoryController *fact)
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
        ip->confirmarIniciarPartida(confirmamo);
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
        ip->confirmarIniciarPartida(confirmamo);

    }

}
    else {
        std::cout << "No tenes juegos :( \n";
    }

}

void menuAbandonarPartidaMulti(FactoryController *fact)
{
}

void menuFinalizarPartida(FactoryController *fact)
{
}

void menuVerInfoVideojuego(FactoryController *fact)
{ //Mismo para jugador y dev
}

void menuSalirUsuario(FactoryController *fact)
{ //Mismo para jugador y dev
}

void menuDesarrollador(Usuario *sesion)
{
    std::cout << "+--------------------- Bienvenidx, " << sesion->getEmail() << " -+\n";
    std::cout << "|                                                           |\n";
    std::cout << "|                 1) Agregar categoría                      |\n";
    std::cout << "|                2) Publicar videojuego                     |\n";
    std::cout << "|                3) Eliminar videojuego                     |\n";
    std::cout << "|              4) Seleccionar estadísticas                  |\n";
    std::cout << "|               5) Consultar estadísticas                   |\n";
    std::cout << "|            6) Ver información de videojuego               |\n";
    std::cout << "|             7) Modificar fecha del sistema                |\n";
    std::cout << "|                       8) Salir                            |\n";
    std::cout << "|                                                           |\n";
    std::cout << "+-----------------------------------------------------------+\n";
}

void menuAgregarCategoria()
{
}

void menuPublicarVideojuego()
{
}

void menuEliminarVideojuego()
{
}

void menuSeleccionarEstadisticas()
{
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
                /* code */
            }
            catch (const std::invalid_argument &ex)
            {
                std::cout << ex.what() << '\n';
            }

            break;
        case 3: //Cargar Datos de Prueba
            try
            {
                /* code */
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
                    /* code */
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 3: //Iniciar partida
                try
                {
                    /* code */
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
                    /* code */
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
                menuSalirUsuario(fact);
                menuInicial();
                break;

            default:
                std::cout << "Por favor, elija un numero adecuado.\n";
                break;
            }
        }

        while (!salirDev)
        {

            std::cout << ">";
            std::cin >> prompt;
            std::cout << "\n";

            switch (prompt)
            {
            case 1: // Agregar categoría
                try
                {
                    /* code */
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 2: //Publicar videojuego
                try
                {
                    /* code */
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 3: //Eliminar videojuego
                try
                {
                    /* code */
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 4: //Seleccionar estadísticas
                try
                {
                    /* code */
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
                    /* code */
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 7: // Modificar fecha del sistema
                try
                {
                    /* code */
                }
                catch (const std::invalid_argument &ex)
                {
                    std::cout << ex.what() << '\n';
                }
                break;
            case 8: //Salir Dev
                salirDev = true;
                menuSalirUsuario(fact);
                menuInicial();
                break;

            default:
                std::cout << "Por favor, elija un numero adecuado.\n";
                break;
            }
        }
    }

    //Destruccion de singletons
    delete uc;
    delete fact;

    //Destruccion variables globales
    delete fechaSist;

    return 0;
}
