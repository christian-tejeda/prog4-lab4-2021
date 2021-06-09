#include "headers/FactoryController.h"
#include "headers/entities/Usuario.h"
#include "headers/utils/Fecha.h"

#include <iostream>
#include <stdexcept>

void menuInicial()
{
    std::cout << "+---------------------- Menú Inicial -----------------------+\n";
    std::cout << "|                                                           |\n";
    std::cout << "|                    1) Alta de usuario                     |\n";
    std::cout << "|                    2) Iniciar sesión                      |\n";
    std::cout << "|              3) Modificar fecha del sistema               |\n";
    std::cout << "|                 4) Cargar datos de prueba                 |\n";
    std::cout << "|                        5) Salir                           |\n";
    std::cout << "|                                                           |\n";
    std::cout << "+-----------------------------------------------------------+\n";
}

void menuAltaUsuario() {}

void menuIniciarSesion() {}

void menuModificarFechaSistema() {}

void menuCargarDatosPrueba() {}

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
    std::cout << "|                       7) Salir                            |\n";
    std::cout << "|                                                           |\n";
    std::cout << "+-----------------------------------------------------------+\n";
}

void menuSuscribirseVideojuego()
{
}

void menuAsignarPuntaje()
{
}

void menuIniciarPartida()
{
}

void menuAbandonarPartidaMulti()
{
}

void menuFinalizarPartida()
{
}

void menuVerInfoVideojuego()
{ //Mismo para jugador y dev
}

void menuSalirUsuario(/* usuarioController */)
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
    std::cout << "|                       7) Salir                            |\n";
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

int main(int argc, char const *argv[])
{
    bool salirInicial = false;
    bool salirJugador = true;
    bool salirDev = true;

    int prompt = 0;

    menuInicial();

    while (!salirInicial)
    {

        std::cout << ">";
        std::cin >> prompt;
        std::cout << "\n";

        switch (prompt)
        {
        case 1: //Alta de usuario
            /* code */
            break;
        case 2: //Iniciar sesión
            /* code */
            break;
        case 3: //Modificar fecha del sistema
            /* code */
            break;
        case 4: //Cargar datos de prueba
            /* code */
            break;
        case 5: //Salir Inicial
            /* code */
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
                /* code */
                break;
            case 2: //Asignar puntaje a videojuego
                /* code */
                break;
            case 3: //Iniciar partida
                /* code */
                break;
            case 4: //Abandonar partida multijugador
                /* code */
                break;
            case 5: //Finalizar partida
                /* code */
                break;
            case 6: //Ver información de videojuego
                /* code */
                break;
            case 7: // Salir Jugador
                /* code */
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
                /* code */
                break;
            case 2: //Publicar videojuego
                /* code */
                break;
            case 3: //Eliminar videojuego
                /* code */
                break;
            case 4: //Seleccionar estadísticas
                /* code */
                break;
            case 5: //Consultar estadísticas
                /* code */
                break;
            case 6: //Ver información de videojuego
                /* code */
                break;
            case 7: //Salir Dev
                /* code */
                break;

            default:
                std::cout << "Por favor, elija un numero adecuado.\n";
                break;
            }
        }
    }

    return 0;
}
