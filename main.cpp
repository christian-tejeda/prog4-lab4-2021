#include "headers/FactoryController.h"
//#include "headers/entities/Usuario.h"
#include "headers/controllers/VideojuegoController.h"
#include "headers/datatypes/DataVideojuego.h"
//#include "headers/interfaces/IEliminarVideojuego.h"
#include "headers/utils/Fecha.h"
#include "headers/handlers/UsuarioHandler.h"
#include "headers/handlers/CategoriaHandler.h"
#include "headers/handlers/VideojuegoHandler.h"
#include "headers/entities/Desarrollador.h"

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

void menuModificarFechaSistema() {}

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
}

void menuAbandonarPartidaMulti(FactoryController *fact)
{
}

void menuFinalizarPartida(FactoryController *fact)
{
}

void menuVerInfoVideojuego(FactoryController *fact)
{
    IVerInfoVideojuego *iviv = fact->getIVerInfoVideojuego();

    std::string nombre = "";
    int conf;
    std::cout << "Seleccione el Videojuego que desea ver la informacion:  \n";
    
    VideojuegoController * vc;
    set<DataVideojuego *> data= vc->obtenerVideojuegos();
    set<DataVideojuego *>::iterator it;
    for (it = data.begin(); it != data.end(); it++)
    {
        DataVideojuego * imprimir=*it;
        std::cout << imprimir->getNombre() << "    -+\n";  
    }
    std::cin >> nombre;
    std::cout << "\n";
    DataVideojuego * datav = vc->obtenerDataVideojuego(nombre);
    
    float mens=datav->getSuscripciones().find(mensual)->second;
    float tri=datav->getSuscripciones().find(trimestral)->second;
    float anu=datav->getSuscripciones().find(anual)->second;
    float vit=datav->getSuscripciones().find(vitalicia)->second;
    std::string empresa=datav->getNombreEmpresa();
    float puntaje=datav->getRating().first;
    set<std::string> nombrescat=datav->getNombreCategorias();

    
    //float horas=datav->getCantidadHoras();//hay que pedirle a partida controller.. es un poco largo para desarrollador.
    set<std::string>::iterator nuevo;
    std::cout << "+---------------- Datos Videojuego-----------------------+\n";
    std::cout << "\n";
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
        std::string print= *nuevo;
        std::cout << "      -"<<print<< "\n";
    }
    std::cout << "     Desarrollador  :\n"<<empresa<< "\n";
    std::cout << "     PuntajePromedio:\n"<<puntaje<< "\n";


    //solo si es desarrollador:
    UsuarioController * uc;
    uc=uc->getInstance();
    Desarrollador* des= dynamic_cast<Desarrollador*>(uc->getSesion());
    if (des!=nullptr){
        vc->seleccionarVideojuego(nombre);//busco el videojuego y lo dejo en el controller
        int horas=vc->obtenerHoras();
        std::cout << "     HorasTotales   :\n"<<puntaje<< "\n";
    }std::cout << "\n";
    std::cout << "\n";


    
    std::cout << "+---------------- Datos Videojuego-----------------------+\n";
    
    //float horas=datav->getCantidadHoras();
    
    
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

void menuEliminarVideojuego(FactoryController *fact)
{
    IEliminarVideojuego *ev = fact->getIEliminarVideojuego();

 
    std::string nombre = "";
    int conf;

    std::cout << "Seleccione el Videojuego a Eliminar:  \n";
    
    VideojuegoController * vc;
    set<DataVideojuego *> data= vc->obtenerVideojuegosPublicadosPorDesarrolladorConPartidasFinalizadas();
    set<DataVideojuego *>::iterator it;
    for (it = data.begin(); it != data.end(); it++)
    {
        DataVideojuego * imprimir=*it;
        std::cout << imprimir->getNombre() << "    -+\n";  
    }
    
    std::cin >> nombre;
    std::cout << "\n";
    vc->seleccionarVideojuego(nombre);
    bool confirmar = false;

    std::cout << "Esta seguo de eliminar: " << nombre << "?\n";
    std::cout << "seleccione el numero correspondiente\n";
    std::cout << "1-Si\n";
    std::cout << "2-No\n";

    std::cin >> conf;
    while(conf!=1||conf!=2){
        std::cout << "Ups! Hubo un error, seleccione un numero correcto por favor! \n";
        std::cin >> conf;
    }
    confirmar = conf == 1 ? true : false;

    vc->confirmarAgregarCategoria(confirmar);
   if (conf==1){
        std::cout << "El videojuego "<< nombre << " ha sido eliminado... \n";
    }
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
                    /* code */
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
