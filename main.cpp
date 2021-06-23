#include "headers/FactoryController.h"
#include "headers/controllers/VideojuegoController.h"
#include "headers/datatypes/DataCategoria.h"
#include "headers/datatypes/DataJugador.h"
#include "headers/datatypes/DataPartida.h"
#include "headers/datatypes/DataPartidaMultijugador.h"
#include "headers/datatypes/DataVideojuego.h"
#include "headers/entities/ContratoSuscripcion.h"
#include "headers/entities/Videojuego.h"
#include "headers/interfaces/IAgregarCategoria.h"
#include "headers/interfaces/IAsignarPuntaje.h"
#include "headers/utils/Fecha.h"
#include "headers/handlers/UsuarioHandler.h"
#include "headers/handlers/CategoriaHandler.h"
#include "headers/handlers/VideojuegoHandler.h"
#include "headers/entities/Desarrollador.h"
#include "headers/utils/enums.h"

#include <iostream>

using namespace std;

void menuInicial()
{
    cout << "+---------------------- Menú Inicial -----------------------+\n";
    cout << "|                                                           |\n";
    cout << "|                    1) Alta de usuario                     |\n";
    cout << "|                    2) Iniciar sesión                      |\n";
    cout << "|                 3) Cargar datos de prueba                 |\n";
    cout << "|                        4) Salir                           |\n";
    cout << "|                                                           |\n";
    cout << "+-----------------------------------------------------------+\n";
}

void menuAltaUsuario(FactoryController *fact)
{

    IAltaUsuario *au = fact->getIAltaUsuario();

    int promptUser = 0;

    string mail = "";
    string pwd = "";

    cout << "Ingrese email: ";
    cin >> mail;
    cout << "\n";

    cout << "Ingrese contraseña: ";
    cin >> pwd;
    cout << "\n";

    cout << "Seleccione tipo de usuario a crear:\n";
    cout << "1) Jugador\n";
    cout << "2) Desarrollador\n";

    cout << ">";
    cin >> promptUser;
    cout << "\n";

    if (promptUser == 1) //Jugador
    {
        bool existeNick = true;
        string nick, desc;

        cin.ignore();
        cout << "Ingrese una descripción: ";
        getline(cin, desc);
        cout << "\n";

        while (existeNick)
        {
            cout << "Ingrese nickname: ";
            cin >> nick;
            cout << "\n";

            DataJugador dtJg = DataJugador(mail, pwd, nick, desc);
            try
            {
                au->ingresarDatosJugador(dtJg);
                existeNick = false;
            }
            catch (const invalid_argument &ex)
            {
                cout << ex.what() << '\n';
                existeNick = true;
            }
        }
    }
    else if (promptUser == 2) //Desarrollador
    {
        string nomEmpresa = "";
        cout << "Ingrese nombre de empresa: ";
        cin >> nomEmpresa;
        cout << "\n";

        DataDesarrollador dtDev = DataDesarrollador(mail, pwd, nomEmpresa);
        au->ingresarDatosDesarrollador(dtDev);
    }
    else
    {
        throw invalid_argument("Error: Tipo de usuario no válido.");
    }

    bool confirmar;
    char promptConfirm = '\0';

    while (promptConfirm != 'y' && promptConfirm != 'n')
    {
        cout << "¿Confirmar alta de usuario? (y/n): ";
        cin >> promptConfirm;
        cout << "\n";
    }

    confirmar = promptConfirm == 'y' ? true : false;

    au->confirmarAltaUsuario();
}

void menuIniciarSesion(FactoryController *fact, bool &jg, bool &dev)
{

    IIniciarSesion *iis = fact->getIIniciarSesion();

    string mail, pwd = "";

    cout << "Email: ";
    cin >> mail;

    cout << "Contraseña: ";
    cin >> pwd;
    cout << "\n";

    bool cancelar = false;
    bool iniciada = iis->iniciarSesion(mail, pwd);
    char failedLogin = '\0';

    while (!iniciada && !cancelar)
    {
        failedLogin = '\0';
        cout << "Credenciales incorrectas. ¿Qué desea hacer?\n";
        cout << "1) Reintentar\n";
        cout << "2) Cancelar\n";

        while (failedLogin != '1' && failedLogin != '2')
        {
            cout << ">";
            cin >> failedLogin;
        }

        if (failedLogin == '1')
        {
            cout << "Email: ";
            cin >> mail;

            cout << "Contraseña: ";
            cin >> pwd;
            cout << "\n";

            iniciada = iis->iniciarSesion(mail, pwd);
        }
        else
        {
            cancelar = true;
        }
    }
    iis->confirmarInicioSesion(mail, jg, dev);
}

void menuModificarFechaSistema(int &dia, int &mes, int &anio, int &hora, int &minuto)
{
    cout << "Todos los valores deben ser enteros.\n";
    cout << "Ingrese dia: ";
    cin >> dia;
    if (dia > 31 || dia < 1)
        throw invalid_argument("Error: El dia ingresado no es valido.");
    cout << "Ingrese mes: ";
    cin >> mes;
    if (mes > 12 || mes < 1)
        throw invalid_argument("Error: El mes ingresado no es valido.");
    cout << "Ingrese año: ";
    cin >> anio;
    if (anio < 0)
        throw invalid_argument("Error: El año ingresado no es valido.");
    cout << "Ingrese hora: ";
    cin >> hora;
    if (hora > 23 || hora < 0)
        throw invalid_argument("Error: La hora ingresada no es valida.");
    cout << "Ingrese minutos: ";
    cin >> minuto;
    if (minuto > 59 || minuto < 0)
        throw invalid_argument("Error: La hora ingresada no es valida.");
}

void menuCargarDatosPrueba(UsuarioHandler *uh, VideojuegoHandler *vh, CategoriaHandler *ch)
{

    //Carga de usuarios
    DataUsuario d1 = DataDesarrollador("ironhide@mail.com", "123", "Ironhide Game Studio");
    DataUsuario d2 = DataDesarrollador("epic@mail.com", "123", "Epic Games");
    DataUsuario d3 = DataDesarrollador("mojang@mail.com", "123", "Mojang Studios");
    DataUsuario d4 = DataDesarrollador("ea@mail.com", "123", "EA Sports");

    DataUsuario j1 = DataJugador("gamer@mail.com", "123", "gamer", "Descripcion de gamer");
    DataUsuario j2 = DataJugador("ari@mail.com", "123", "ari", "Descripcion de ari");
    DataUsuario j3 = DataJugador("ibai@mail.com", "123", "ibai", "Descripcion de ibai");
    DataUsuario j4 = DataJugador("camila@mail.com", "123", "camila", "Descripcion de camila");

    DataUsuario j5 = DataJugador("1", "1", "1", "Descripcion de 1");
    DataUsuario d5 = DataDesarrollador("2", "2", "ROCKSTARS");

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

    //Carga de categorias
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

    ch->crearNuevaCategoria("Teen", "Su contenido esta dirigido a jovenes de 13 anos en adelante", otrasCategorias);
    ch->crearNuevaCategoria("E", "Su contenido esta dirigido para todo publico", otrasCategorias);

    //Carga de videojuegos
    Categoria *cv1, *cv2, *cv3, *cv4, *cv5, *cv6, *cv7, *cv8;
    cv1 = ch->obtenerCategoriaPorId("PC");
    cv2 = ch->obtenerCategoriaPorId("PS4");
    cv3 = ch->obtenerCategoriaPorId("XBox One");
    cv4 = ch->obtenerCategoriaPorId("Deporte");
    cv5 = ch->obtenerCategoriaPorId("Supervivencia");
    cv6 = ch->obtenerCategoriaPorId("Estrategia");
    cv7 = ch->obtenerCategoriaPorId("Teen");
    cv8 = ch->obtenerCategoriaPorId("E");

    map<TipoPeriodoValidez, float> susc1;
    susc1.insert(pair<TipoPeriodoValidez, float>(mensual, 1));
    susc1.insert(pair<TipoPeriodoValidez, float>(trimestral, 2));
    susc1.insert(pair<TipoPeriodoValidez, float>(anual, 7));
    susc1.insert(pair<TipoPeriodoValidez, float>(vitalicia, 14));
    pair<float, int> ratings1;
    map<string, Categoria *> cats1;
    set<ContratoSuscripcion *> contratos1;
    Videojuego *vj1 = new Videojuego("KingdomRush",
                                     "prueba",
                                     susc1,
                                     ratings1,
                                     contratos1,
                                     cats1,
                                     "Ironhide Game Studio");
    vj1->setCategoria(cv1);
    vj1->setCategoria(cv2);
    vj1->setCategoria(cv6);
    vj1->setCategoria(cv8);
    vh->agregarVideojuego(vj1);
    Desarrollador *des1 = dynamic_cast<Desarrollador *>(uh->obtenerUsuarioPorId("ironhide@mail.com"));
    des1->agregarVideojuegoPublicado(vj1);

    map<TipoPeriodoValidez, float> susc2;
    susc2.insert(pair<TipoPeriodoValidez, float>(mensual, 3));
    susc2.insert(pair<TipoPeriodoValidez, float>(trimestral, 8));
    susc2.insert(pair<TipoPeriodoValidez, float>(anual, 30));
    susc2.insert(pair<TipoPeriodoValidez, float>(vitalicia, 60));
    pair<float, int> ratings2;
    map<string, Categoria *> cats2;
    set<ContratoSuscripcion *> contratos2;
    Videojuego *vj2 = new Videojuego("Fortnite",
                                     "prueba 2",
                                     susc2,
                                     ratings2,
                                     contratos2,
                                     cats2,
                                     "Epic Games");

    vj2->setCategoria(cv1);
    vj2->setCategoria(cv2);
    vj2->setCategoria(cv3);
    vj2->setCategoria(cv5);
    vj2->setCategoria(cv7);
    vh->agregarVideojuego(vj2);
    Desarrollador *des2 = dynamic_cast<Desarrollador *>(uh->obtenerUsuarioPorId("epic@mail.com"));
    des2->agregarVideojuegoPublicado(vj2);

    map<TipoPeriodoValidez, float> susc3;
    susc3.insert(pair<TipoPeriodoValidez, float>(mensual, 2));
    susc3.insert(pair<TipoPeriodoValidez, float>(trimestral, 5));
    susc3.insert(pair<TipoPeriodoValidez, float>(anual, 20));
    susc3.insert(pair<TipoPeriodoValidez, float>(vitalicia, 40));
    pair<float, int> ratings3;
    map<string, Categoria *> cats3;
    set<ContratoSuscripcion *> contratos3;
    Videojuego *vj3 = new Videojuego("Minecraft",
                                     "prueba 3",
                                     susc3,
                                     ratings3,
                                     contratos3,
                                     cats3,
                                     "Mojang Studios");

    vj3->setCategoria(cv1);
    vj3->setCategoria(cv5);
    vj3->setCategoria(cv8);
    vh->agregarVideojuego(vj3);
    Desarrollador *des3 = dynamic_cast<Desarrollador *>(uh->obtenerUsuarioPorId("mojang@mail.com"));
    des3->agregarVideojuegoPublicado(vj3);

    map<TipoPeriodoValidez, float> susc4;
    susc4.insert(pair<TipoPeriodoValidez, float>(mensual, 3));
    susc4.insert(pair<TipoPeriodoValidez, float>(trimestral, 8));
    susc4.insert(pair<TipoPeriodoValidez, float>(anual, 28));
    susc4.insert(pair<TipoPeriodoValidez, float>(vitalicia, 50));
    pair<float, int> ratings4;
    map<string, Categoria *> cats4;
    set<ContratoSuscripcion *> contratos4 = set<ContratoSuscripcion *>();
    Videojuego *vj4 = new Videojuego("FIFA 21", "prueba 4", susc4, ratings4, contratos4, cats4, "EA Sports");

    vj4->setCategoria(cv1);
    vj4->setCategoria(cv2);
    vj4->setCategoria(cv3);
    vj4->setCategoria(cv4);
    vj4->setCategoria(cv8);
    vh->agregarVideojuego(vj4);
    Desarrollador *des4 = dynamic_cast<Desarrollador *>(uh->obtenerUsuarioPorId("ea@mail.com"));
    des4->agregarVideojuegoPublicado(vj4);

    Jugador *gamer = dynamic_cast<Jugador *>(uh->obtenerUsuarioPorId("gamer@mail.com"));
    Jugador *ari = dynamic_cast<Jugador *>(uh->obtenerUsuarioPorId("ari@mail.com"));
    Jugador *ibai = dynamic_cast<Jugador *>(uh->obtenerUsuarioPorId("ibai@mail.com"));

    Videojuego *kindom = vh->obtenerVideojuegoPorId("KingdomRush");
    Videojuego *fort = vh->obtenerVideojuegoPorId("Fortnite");
    Videojuego *mine = vh->obtenerVideojuegoPorId("Minecraft");

    Fecha fe = Fecha(1, 6, 2021, 9, 0);
    Fecha fe2 = Fecha(2, 6, 2021, 11, 0);
    Fecha fe3 = Fecha(4, 6, 2021, 9, 0);
    Fecha fe4 = Fecha(11, 6, 2021, 9, 0);
    Fecha fe5 = Fecha(3, 6, 2021, 7, 0);
    Fecha fe6 = Fecha(21, 12, 2020, 15, 0);
    gamer->contratarSuscripcion(kindom, trimestral, paypal, fe);
    gamer->contratarSuscripcion(fort, trimestral, tarjeta, fe2);
    ari->contratarSuscripcion(fort, mensual, paypal, fe3);
    ari->contratarSuscripcion(mine, anual, tarjeta, fe4);
    ibai->contratarSuscripcion(fort, mensual, tarjeta, fe5);
    ibai->contratarSuscripcion(mine, vitalicia, tarjeta, fe6);
    Fecha fe7 = Fecha(2, 6, 2021, 9, 0);
    Fecha fe8 = Fecha(2, 6, 2021, 15, 0);
    Fecha fe9 = Fecha(12, 6, 2021, 16, 0);
    Fecha f10 = Fecha(2, 6, 2021, 10, 0);
    Fecha f11 = Fecha(2, 6, 2021, 16, 0);
    kindom->agregarPuntaje(4);
    fort->agregarPuntaje(5);
    fort->agregarPuntaje(5);
    mine->agregarPuntaje(3);

    //Inicio de partidas individuales
    gamer->crearPartidaIndividual(0, fe7, kindom, gamer, nullptr);
    PartidaIndividual *part = dynamic_cast<PartidaIndividual *>(uh->obtenerPartidaPorId(0));
    gamer->crearPartidaIndividual(1, fe8, kindom, gamer, part);
    ari->crearPartidaIndividual(2, fe9, mine, ari, nullptr);
    //Finalizo individuales
    gamer->finalizarPartida(0, f10);
    gamer->finalizarPartida(1, f11);

    //Inicio de partidas multijugador
    Fecha f12 = Fecha(5, 6, 2021, 17, 0);
    Fecha f13 = Fecha(6, 6, 2021, 17, 0);
    Fecha f14 = Fecha(12, 6, 2021, 20, 0);
    Fecha f15 = Fecha(5, 6, 2021, 19, 0);
    Fecha f16 = Fecha(6, 6, 2021, 19, 0);
    Fecha f17 = Fecha(5, 6, 2021, 18, 0);
    Fecha f18 = Fecha(6, 6, 2021, 17, 30);
    map<string, Jugador *> partm1;
    partm1.insert(std::pair<string, Jugador *>(ari->getNickname(), dynamic_cast<Jugador *>(ari)));
    partm1.insert(std::pair<string, Jugador *>(ibai->getNickname(), dynamic_cast<Jugador *>(ibai)));
    gamer->crearPartidaMultijugador(3, f12, Fecha(), fort, true, gamer, partm1);
    map<string, Jugador *> partm2;
    partm2.insert(std::pair<string, Jugador *>("ari", ari));
    partm2.insert(std::pair<string, Jugador *>(ibai->getNickname(), ibai));
    gamer->crearPartidaMultijugador(4, f13, Fecha(), fort, true, gamer, partm2);
    std::map<string, Jugador *> partm3;
    partm3.insert(std::pair<string, Jugador *>(ibai->getNickname(), dynamic_cast<Jugador *>(ibai)));
    ari->crearPartidaMultijugador(5, f14, Fecha(), mine, false, ari, partm3);
    //Abandonos de partidas
    Partida *p3 = gamer->obtenerPartidaPorId(3);
    PartidaMultijugador *pm3 = dynamic_cast<PartidaMultijugador *>(p3);
    Partida *p4 = gamer->obtenerPartidaPorId(4);
    PartidaMultijugador *pm4 = dynamic_cast<PartidaMultijugador *>(p4);

    pm3->bajarParticipante(ari, f17);
    pm4->bajarParticipante(ari, f18);

    //Finalizo multijugadores
    gamer->finalizarPartida(3, f15);
    gamer->finalizarPartida(4, f16);

    cout << "¡Datos cargados correctamente!\n";
}

void menuSalirInicial()
{
    cout << "¡Hasta luego! \n";
}

void menuJugador(Usuario *sesion)
{
    cout << "+----------------------- Menú Jugador  ---------------------+\n";
    cout << "|                                                           |\n";
    cout << "|                 1) Suscribirse a videojuego               |\n";
    cout << "|               2) Asignar puntaje a videojuego             |\n";
    cout << "|                     3) Iniciar partida                    |\n";
    cout << "|              4) Abandonar partida multijugador            |\n";
    cout << "|                    5) Finalizar partida                   |\n";
    cout << "|               6) Ver información de videojuego            |\n";
    cout << "|                7) Modificar fecha del sistema             |\n";
    cout << "|                         8) Salir                          |\n";
    cout << "|                                                           |\n";
    cout << "+-----------------------------------------------------------+\n";
}

void menuSuscribirseVideojuego(FactoryController *fact, Fecha f)
{
    ISuscribirseVideojuego *iSuscAVj = fact->getISuscribirseVideojuego();

    set<DataSuscripcionJugador> dataSuscJugador = iSuscAVj->obtenerSuscripciones();

    set<DataSuscripcionJugador>::iterator it;

    cout << "Suscripciones:  \n";
    cout << " \n";
    cout << "Activas: \n";

    for (it = dataSuscJugador.begin(); it != dataSuscJugador.end(); it++)
    {
        DataSuscripcionJugador data = *it;

        if (data.esSuscripcionActiva())
        {
            cout << data << "\n";
        }
    }

    cout << " \n";
    cout << "Inactivas: \n";

    for (it = dataSuscJugador.begin(); it != dataSuscJugador.end(); it++)
    {
        DataSuscripcionJugador data = *it;

        if (!data.esSuscripcionActiva())
        {
            cout << data << "\n";
        }
    }

    string nombreVideojuego;
    cin.ignore();
    cout << "\n";
    cout << "Ingrese el nombre del Videojuego:";
    cout << " \n";
    getline(cin, nombreVideojuego);

    iSuscAVj->seleccionarVideojuego(nombreVideojuego);

    bool esDataVideojuegoIngresado = false;

    DataSuscripcionJugador dataSusc;

    for (it = dataSuscJugador.begin();
         it != dataSuscJugador.end() && !esDataVideojuegoIngresado; it++)
    {
        DataSuscripcionJugador data = *it;

        if (data.getNombreVideojuego() == nombreVideojuego)
        {
            dataSusc = data;
            esDataVideojuegoIngresado = true;
        }
    }

    if (dataSusc.esSuscripcionActiva())
    {
        if (dataSusc.getValidez() == vitalicia)
            return;

        int opcion;
        cout << "Desea cancelar su Suscripcion Activa?";
        cout << " \n";
        cout << "0) No";
        cout << " \n";
        cout << "1) Si ";
        cout << " \n";
        cin >> opcion;

        if (opcion == 0)
            return;

        iSuscAVj->cancelarSuscripcion();
    }

    cout << "Elija el tipo de suscripcion a contratar:";
    cout << " \n";
    cout << "1) Vitalicia\n";
    cout << "2) Mensual\n";
    cout << "3) Trimestral\n";
    cout << "4) Anual\n";
    cout << " \n";

    int validez;
    cin >> validez;

    cout << "Indique el Metodo de Pago:";
    cout << " \n";
    cout << "1- Tarjeta\n";
    cout << "2- Paypal\n";
    cout << " \n";

    int metodoPago;
    cin >> metodoPago;

    cout << "Desea confirmar la Suscripcion?";
    cout << " \n";
    cout << "1- Si\n";
    cout << "2- No\n";

    int confirmar;
    cin >> confirmar;

    if (confirmar == 1)
    {
        bool conf = confirmar == 1;
        iSuscAVj->confirmarSuscripcion(f);
    }
}

void menuAsignarPuntaje(FactoryController *fact)
{
    IAsignarPuntaje *ap = fact->getIAsignarPuntaje();
    string nombre = "";
    int conf;
    cout << "Seleccione el Videojuego que desea ver la informacion:  \n";

    set<DataVideojuego> data = ap->obtenerVideojuegos();
    set<DataVideojuego>::iterator it;
    for (it = data.begin(); it != data.end(); it++)
    {
        DataVideojuego imprimir = *it;
        cout << "\tNombre: " << imprimir.getNombre() << "\t | \t"
             << "Descripcion:" << imprimir.getDescripcion() << "    \n";
    }
    cout << "\n";
    cin.ignore();
    cout << ">";
    getline(std::cin, nombre);
    cout << "\n";
    int punt;
    cout << "Seleccione un numero del 1 al 5 para puntuar al videojuego \n";
    cout << ">";
    cin >> punt;
    while (punt > 5 || punt < 0)
    {
        cout << "Seleccione un puntaje corrcto o  digite cero(0) si desea cancelar\n";
        cin >> punt;
    }
    if (punt != 0)
    {
        ap->seleccionarVideojuego(nombre);
        ap->puntuarVideojuego(punt);
        cout << "El puntaje ha sido asignado\n";
    }
    else
    {
        cout << "Cancelacion satisfactoria\n";
    }
    ap->~IAsignarPuntaje();
}

void menuIniciarPartida(FactoryController *fact, Fecha fechainicio)
{
    IIniciarPartida *ip = fact->getIIniciarPartida();
    set<DataVideojuego> videojuegosDeJgConSus = ip->obtenerVideojuegosDeJugadorConSuscripcionActiva(fechainicio);
    cout << "Videojuegos con Suscripcion: \n";
    set<DataVideojuego>::iterator it;
    for (it = videojuegosDeJgConSus.begin(); it != videojuegosDeJgConSus.end(); it++)
    {
        cout << "Nombre videojuego: " << (*it).getNombre() << "\n";
    }
    bool juegoValido = false;
    if (videojuegosDeJgConSus.size() != 0)
    {
        while (!juegoValido)
        {
            string nombreJueguito;
            cin.ignore();
            cout << "Ingrese el nombre del videojuego que desea iniciar partida: ";
            getline(cin, nombreJueguito);
            try
            {
                juegoValido = true;
                ip->seleccionarVideojuego(nombreJueguito);
            }
            catch (const invalid_argument &ex)
            {
                cout << ex.what() << '\n';
                juegoValido = false;
            }
        }
        char tipoPartida = '3';
        while (tipoPartida != '1' && tipoPartida != '2')
        {
            cout << "Que tipo de partida desea iniciar?  \n  \n";
            cout << "1 Partida Individual  \n";
            cout << "2 Partida Multijugador \n";
            cin >> tipoPartida;
            if (tipoPartida != '1' && tipoPartida != '2')
            {
                cout << "Ingrese un numero valido  \n";
            }
        }
        if (tipoPartida == '1')
        { //partida individual
            char continuaa = 'r';
            while (continuaa != 'y' && continuaa != 'n')
            {
                cout << "Desea continuar una partida? (y/n) ";
                cin >> continuaa;
                cout << " \n";
            }
            if (continuaa == 'y')
            { //va a continuar una partida
                set<DataPartidaIndividual> partidasfin = ip->obtenerPartidasFinalizadasDeJugador();
                if (partidasfin.size() != 0)
                { //hay partidas para continuar
                    cout << "Partidas finalizadas: \n";
                    set<DataPartidaIndividual>::iterator it;
                    for (it = partidasfin.begin(); it != partidasfin.end(); it++)
                    {
                        DataPartidaIndividual dataPartidaIndividual = *it;
                        cout << "Nombre videojuego: " << dataPartidaIndividual.getDataVideojuego().getNombre();
                        cout << "  Id partida: " << dataPartidaIndividual.getId() << " \n ";
                    }
                    int numeroPartida = -1;
                    bool partidaValida = false;
                    while (!partidaValida)
                    {
                        cout << "Ingrese el id de la partida: ";
                        cin >> numeroPartida;
                        try
                        {
                            partidaValida = true;
                            ip->seleccionarPartidaAContinuar(numeroPartida);
                        }
                        catch (const invalid_argument &ex)
                        {
                            cout << ex.what() << '\n';
                            partidaValida = false;
                        }
                    }
                }
                else
                { //no hay partidas para continuar
                    cout << "No hay partidas finalizadas, se va a iniciar una nueva \n";
                }
            }
            char confirmar = 'r';
            while (confirmar != 'y' && confirmar != 'n')
            {
                cout << "Desea confirmar el inicio de partida? (y/n) ";
                cin >> confirmar;
                cout << " \n";
            }
            bool confirmamo = false;
            if (confirmar == 'y')
                ip->confirmarIniciarPartida(fechainicio);
        }
        else
        {
            char transmitir = 'r';
            while (transmitir != 'y' && transmitir != 'n')
            {
                cout << "Desea que su partida sea transmitida en vivo? (y/n) ";
                cin >> transmitir;
                cout << " \n";
            }
            bool transmitimo = false;
            if (transmitir == 'y')
                transmitimo = true;
            cout << "Jugadores con suscripcion activa \n";
            set<DataJugador> jugadores = ip->obtenerJugadoresConSuscripcionActiva();
            set<DataJugador>::iterator it;
            set<string> nombreJugadoresConSus;
            if (jugadores.size() > 0)
            {
                for (it = jugadores.begin(); it != jugadores.end(); it++)
                {
                    DataJugador dataJugador = *it;
                    cout << "Nickname: " << dataJugador.getNickname() << "\n";
                    nombreJugadoresConSus.insert(dataJugador.getNickname());
                }
                char masJugadores = 'r';
                cout << "Desea agregar un jugador a la partida? (y/n) ";
                cin >> masJugadores;
                cout << "\n";
                while (masJugadores == 'y')
                {
                    set<string>::iterator it2;
                    string jugadorAgregar;
                    cout << "Ingrese el nickname del jugador: ";
                    cin >> jugadorAgregar;
                    it2 = nombreJugadoresConSus.find(jugadorAgregar);
                    if (it2 == nombreJugadoresConSus.end())
                    {
                        cout << "Jugador con ese nombre y suscripcion no encontrado, intente con otro \n";
                    }
                    else
                    {
                        cout << "Jugador ingresado \n";
                        ip->seleccionarJugador(jugadorAgregar);
                    }
                    char seguirAgregando = 'r';
                    while (seguirAgregando != 'y' && seguirAgregando != 'n')
                    {
                        cout << "Desea agregar otro jugador a la partida? (y/n) \n";
                        cin >> seguirAgregando;
                    }
                    if (seguirAgregando == 'y')
                    {
                        masJugadores = 'y';
                    }
                    else
                        masJugadores = 'n';
                }
            }
            else
                cout << "No hay otros jugadores suscritos a éste juego.\n";
            char confirmar = 'r';
            while (confirmar != 'y' && confirmar != 'n')
            {
                cout << "Desea confirmar el inicio de partida? (y/n) ";
                cin >> confirmar;
                cout << " \n";
            }
            bool confirmamo = false;
            if (confirmar == 'y')
                ip->confirmarIniciarPartida(fechainicio);
        }
    }
    else
    {
        cout << "No tenés juegos...\n";
    }
}

void menuAbandonarPartidaMulti(FactoryController *fact, Fecha fs)
{
    IAbandonarPartida *iap = fact->getIAbandonarPartida();

    set<DataPartidaMultijugador> colDtMulti = iap->obtenerPartidasMultijugadorActivasDeJugador();
    if (colDtMulti.size() > 0)
    {
        set<DataPartidaMultijugador>::iterator it;
        cout << "ID \t Comienzo \t Videojuego \t Transmitida?  \n";
        cout << "----------------------------------------------------------\n";
        for (it = colDtMulti.begin(); it != colDtMulti.end(); it++)
        {
            cout << (*it).getId() << " \t " << (*it).getFechaInicio() << " \t " << (*it).getDataVideojuego().getNombre() << " \t " << (*it).getTransmitida() << "\n";
        }

        int promptPartida;
        cout << "Indique partida a abandonar\n";
        cout << ">";
        cin >> promptPartida;

        iap->abandonarPartida(promptPartida, fs);
        cout << "¡Salida de partida registrada! \n";
    }
    else
        cout << "No tenés partidas activas.\n";

    delete iap;
}

void menuFinalizarPartida(FactoryController *fact, Fecha fecha)
{
    IFinalizarPartida *fp = fact->getIFinalizarPartida();
    set<DataPartida> part = fp->obtenerPartidasSinFinalizarDeJugador();
    if (part.size() != 0)
    {
        cout << "Ingrese ID de la Partida a Finalizar:  \n";
        set<DataPartida>::iterator it;
        for (it = part.begin(); it != part.end(); it++)
        {
            DataPartida dataPartida = *it;
            cout << "Id: " << dataPartida.getId() << " \nFecha Comienzo (DIA/MES/AÑO) : " << dataPartida.getFechaInicio().getDia() << "/" << dataPartida.getFechaInicio().getMes() << "/" << dataPartida.getFechaInicio().getAnio() << "   "
                 << " \n Nombre Videojuego :" << dataPartida.getDataVideojuego().getNombre();
            DataPartidaIndividual data = dynamic_cast<DataPartidaIndividual &>(dataPartida);
            DataPartidaMultijugador dataPartidaMultijugador = dynamic_cast<DataPartidaMultijugador &>(dataPartida);
            if (data != DataPartidaIndividual())
            {
                string resp = data.getContinuacion() ? "si" : "no";
                cout << "Es continuacion?: " << resp << "\n";
            }
            else if (dataPartidaMultijugador != DataPartidaMultijugador())
            {
                string resp = dataPartidaMultijugador.getTransmitida() ? "si" : "no";
                cout << "Es trasmitida en Vivo?: " << resp << "\n";
                set<DataJugador> participanetes = dataPartidaMultijugador.getParticipantes();
                set<DataJugador>::iterator it;
                cout << "Jugadores Participantes" << resp << "\n";
                for (it = participanetes.begin(); it != participanetes.end(); it++)
                {
                    DataJugador dataJugador = *it;
                    cout << "\t" << dataJugador.getNickname() << "\n";
                }
            }
            cout << " \n \n";
        }
        int seleccion;
        cout << ">";
        cin >> seleccion;
        fp->finalizarPartida(seleccion, fecha);
        cout << "La partida ha sido finalizada \n";
    }
    else
    {
        cout << "No se encontraron partidas sin finalizar\n";
    }
}

void menuVerInfoVideojuego(FactoryController *fact)
{
    IVerInfoVideojuego *iviv = fact->getIVerInfoVideojuego();

    string nombre = "";
    int conf;
    //VideojuegoController * vc;
    set<DataVideojuego> data = iviv->obtenerVideojuegos();
    set<DataVideojuego>::iterator it;
    if (data.size() != 0)
    {
        cout << "LISTA DE VIDEOJUEGOS SISTEMA\n";
        cout << "-----------------------------\n";
        for (it = data.begin(); it != data.end(); it++)
        {
            DataVideojuego imprimir = *it;
            cout << imprimir.getNombre() << "\n";
        }

        cin.ignore();
        cout << "Seleccione el Videojuego que desea ver la informacion:  \n";
        cout << ">";
        getline(cin, nombre);
        cout << "\n";
        DataVideojuego datav = iviv->obtenerDataVideojuego(nombre); //controlar aca la cuestion si es Desaroollador o no
        string empresa = datav.getNombreEmpresa();
        map<TipoPeriodoValidez, float> suss = datav.getSuscripciones();
        float mens = suss.find(mensual)->second;
        float tri = suss[trimestral];
        float anu = suss[anual];
        float vit = suss[vitalicia];
        float puntaje = 0;
        int cantidadvotos = datav.getRating().second;

        //cout << "      -votos      :"<<cantidadvotos<< "\n";
        if (cantidadvotos != 0)
        {
            float total = datav.getRating().first;
            puntaje = total / cantidadvotos;

            //cout << "      -total      :"<<datav->getRating().first<< "\n";
        }
        set<string> categorias = datav.getNombreCategorias();

        float horas = datav.getHorasTotales(); //hay que pedirle a partida controller.. es un poco largo para desarrollador.
        set<string>::iterator it2;
        cout << "+---------------- Datos Videojuego-----------------------+\n";
        cout << "\n";
        cout << "     Nombre        :" << datav.getNombre() << "\n";
        cout << "     Descripcion   :" << datav.getDescripcion() << "\n";
        cout << "     Costos Suscrip:\n";
        cout << "      -mensual      :" << mens << "\n";
        cout << "      -trimensual   :" << tri << "\n";
        cout << "      -anual        :" << anu << "\n";
        cout << "      -vitalicia    :" << vit << "\n";
        cout << "     Categorias:\n";
        for (it2 = categorias.begin(); it2 != categorias.end(); it2++)
        {
            string catActual = *it2;
            cout << " \t " << catActual << "\n";
        }
        cout << "     NombreEmpresa  :" << empresa << "\n";
        cout << "     PuntajePromedio:" << puntaje << "\n";

        //solo si es desarrollador:
        if (datav.getHorasTotales() >= 0)
        {
            cout << "     HorasTotales   :" << horas << "\n\n";
        }
        cout << "+--------------------------------------------------------+\n";
    }
    else
    {
        cout << "¡No hay videojuegos en el sistema!\n";
    }
    //float horas=datav->getCantidadHoras();
    iviv->~IVerInfoVideojuego();
}

void menuSalirUsuariomake(FactoryController *fact)
{ //Mismo para jugador y dev
}

void menuDesarrollador(Usuario *sesion)
{
    cout << "+-------------------- Menú Desarrollador -------------------+\n";
    cout << "|                                                           |\n";
    cout << "|                   1) Agregar categoría                    |\n";
    cout << "|                  2) Publicar videojuego                   |\n";
    cout << "|                  3) Eliminar videojuego                   |\n";
    cout << "|                4) Seleccionar estadísticas                |\n";
    cout << "|                 5) Consultar estadísticas                 |\n";
    cout << "|              6) Ver información de videojuego             |\n";
    cout << "|               7) Modificar fecha del sistema              |\n";
    cout << "|                         8) Salir                          |\n";
    cout << "|                                                           |\n";
    cout << "+-----------------------------------------------------------+\n";
}

void menuAgregarCategoria(FactoryController *fact)
{
    IAgregarCategoria *ac = fact->getIAgregarCategoria();

    set<DataCategoria> cats = ac->obtenerCategorias();
    set<DataCategoria>::iterator it;
    cout << "Nombre\n";
    cout << "----------------------------------------------------\n";
    for (it = cats.begin(); it != cats.end(); ++it)
    {
        DataCategoria dataCategoria = *it;
        string nombreCategoria = dataCategoria.getNombre();
        cout << nombreCategoria << " \n";
        cout << "----------------------------------------------------\n";
    }
    cout << "+------------Que tipo de Categoria desea agregar?-----------+\n";
    cout << "|                                                           |\n";
    cout << "|                    1) Plataforma                          |\n";
    cout << "|                      2) Genero                            |\n";
    cout << "|                  3) Otras Categorias                      |\n";
    cout << "|                                                           |\n";
    cout << "+-----------------------------------------------------------+\n";
    int opcion;
    cin >> opcion;
    while (opcion > 3 || opcion < 1)
    {
        cout << "Seleccione una opcion correcta, por favor\n";
        cin >> opcion;
    }
    TipoCategoria tipo;
    if (opcion == 1)
    {
        tipo = plataforma;
    }
    else if (opcion == 2)
    {
        tipo = genero;
    }
    else
    {
        tipo = otrasCategorias;
    }

    string agregar;
    string desc;
    cout << "Introduzca el nombre de la cateogria agregar: ";
    cin.ignore();
    getline(cin, agregar);
    cout << "Introduzca la descripcion de la cateogria agregar: ";
    //cin.ignore();
    getline(cin, desc);
    cout << "Confirma que desea agregar esta nueva categoria?\n";
    cout << "    -Nombre: " << agregar << "\n";
    cout << "    -Descripcion: " << desc << "\n";
    cout << "1-Confirmar\n";
    cout << "2-Cancelar\n";
    int op2;
    cin >> op2;

    while (op2 > 2 || op2 < 1)
    {
        cout << "Seleccione una opcion correcta, por favor\n";
        cin >> op2;
    }

    ac->agregarCategoria(agregar, desc, tipo);
    if (op2 == 1)
    {
        ac->confirmarAgregarCategoria();
        cout << "\n";
    }

    ac->~IAgregarCategoria();
}

void menuPublicarVideojuego(FactoryController *fact)
{
    IPublicarVideojuego *ipv = fact->getIPublicarVideojuego();

    string nombreVdj, descVdj;

    cin.ignore();
    cout << "Ingrese un nombre para el videojuego: ";
    getline(cin, nombreVdj);
    cout << "Ingrese una descripción para el videojuego: ";
    //cin.ignore();
    getline(cin, descVdj);
    cout << "Ingrese el coste de cada periodo:\n";

    float precioMensual, precioTrimestral, precioAnual, precioVitalicia;
    cout << "Mensual: ";
    cin >> precioMensual;
    cout << "Trimestral: ";
    cin >> precioTrimestral;
    cout << "Anual: ";
    cin >> precioAnual;
    cout << "Vitalicia: ";
    cin >> precioVitalicia;

    map<TipoPeriodoValidez, float> suscripciones;
    suscripciones.insert(pair<TipoPeriodoValidez, float>(mensual, precioMensual));
    suscripciones.insert(pair<TipoPeriodoValidez, float>(trimestral, precioTrimestral));
    suscripciones.insert(pair<TipoPeriodoValidez, float>(anual, precioAnual));
    suscripciones.insert(pair<TipoPeriodoValidez, float>(vitalicia, precioVitalicia));

    DataVideojuego nuevoDataVdj = DataVideojuego(nombreVdj, descVdj, suscripciones, set<string>(), pair<float, int>(0, 0));
    ipv->ingresarDatosVideojuego(nuevoDataVdj);

    set<DataCategoria> categorias = ipv->obtenerCategorias();
    set<DataCategoria>::iterator it;
    cout << "----------------- Géneros --------------------------\n";
    cout << "Nombre \t Descripcion \n";
    cout << "----------------------------------------------------\n";
    for (it = categorias.begin(); it != categorias.end(); it++)
    {
        DataCategoria dataCategoria = *it;
        if (dataCategoria.getTipo() == genero)
        {
            cout << dataCategoria.getNombre() << " \t " << dataCategoria.getDescripcion() << "\n";
        }
    };

    string nombreCat;
    char promptConfirm = '\0';
    bool continuaAgregar = true;
    do
    {
        cin.ignore();
        cout << "Ingrese el nombre del genero: ";
        getline(cin, nombreCat);
        ipv->agregarCategoriaAVideojuego(nombreCat);
        cout << "¿Desea agregar más géneros? (y/n) ";
        cin >> promptConfirm;
        continuaAgregar = promptConfirm == 'y' ? true : false;
    } while (continuaAgregar);

    cout << "----------------- Plataformas ------------------------\n";
    cout << "Nombre \t Descripcion \n";
    cout << "----------------------------------------------------\n";
    for (it = categorias.begin(); it != categorias.end(); it++)
    {
        if ((*it).getTipo() == plataforma)
        {
            DataCategoria catActual = *it;
            cout << catActual.getNombre() << " \t " << catActual.getDescripcion() << "\n";
        }
    }

    promptConfirm = '\0';
    continuaAgregar = true;
    do
    {
        cin.ignore();
        cout << "Ingrese el nombre de la plataforma: ";
        getline(cin, nombreCat);
        ipv->agregarCategoriaAVideojuego(nombreCat);
        cout << "¿Desea agregar más plataformas? (y/n) ";
        cin >> promptConfirm;
        continuaAgregar = promptConfirm == 'y' ? true : false;
    } while (continuaAgregar);

    cout << "----------------- Otras categorías --------------------\n";
    cout << "Nombre \t Descripcion \n";
    cout << "----------------------------------------------------\n";
    for (it = categorias.begin(); it != categorias.end(); it++)
    {
        if ((*it).getTipo() == otrasCategorias)
        {
            DataCategoria catActual = *it;
            cout << catActual.getNombre() << " \t " << catActual.getDescripcion() << "\n";
        }
    }
    promptConfirm = '\0';
    continuaAgregar = true;
    cout << "¿Desea agregar otro tipo de categorías? (y/n) ";
    cin >> promptConfirm;
    continuaAgregar = promptConfirm == 'y' ? true : false;
    while (continuaAgregar)
    {
        cin.ignore();
        cout << "Ingrese el nombre de la categoría: ";
        getline(cin, nombreCat);
        ipv->agregarCategoriaAVideojuego(nombreCat);
        cout << "¿Desea agregar más categorías? (y/n) ";
        cin >> promptConfirm;
        continuaAgregar = promptConfirm == 'y' ? true : false;
    }

    ipv->obtenerDataVideojuegoIngresada();

    bool confirmar;
    promptConfirm = '\0';
    while (promptConfirm != 'y' && promptConfirm != 'n')
    {
        cout << "¿Confirmar publicación de videojuego? (y/n): ";
        cin >> promptConfirm;
    }
    confirmar = promptConfirm == 'y' ? true : false;

    if (confirmar)
    {
        ipv->confirmarPublicacionVideojuego();
    }

    ipv->~IPublicarVideojuego();
}

void menuEliminarVideojuego(FactoryController *fact)
{
    IEliminarVideojuego *ev = fact->getIEliminarVideojuego();

    string nombre = "";
    int conf;

    cout << "Seleccione el Videojuego a Eliminar:  \n";

    set<DataVideojuego> data = ev->obtenerVideojuegosPublicadosPorDesarrolladorConPartidasFinalizadas();
    set<DataVideojuego>::iterator it;
    for (it = data.begin(); it != data.end(); it++)
    {
        DataVideojuego imprimir = *it;
        cout << imprimir.getNombre() << "\n";
    }
    cout << "\n>";
    cin >> nombre;
    //cout << "\n";
    ev->seleccionarVideojuego(nombre);
    bool confirmar = false;

    cout << "Está seguro de eliminar: " << nombre << " ?\n";
    cout << "1-Si\n";
    cout << "2-No\n";
    cout << ">";
    cin >> conf;

    confirmar = conf == 1 ? true : false;

    if (confirmar)
    {
        ev->confirmarEliminarVideojuego();
        cout << "El videojuego " << nombre << " ha sido eliminado... \n";
    }
}

void menuSeleccionarEstadisticas(FactoryController *fact)
{
    cout << "Bienvenido al menu de seleccionar estadisticas :smile: \n";
    ISeleccionarEstadisticas *se = fact->getISeleccionarEstadisticas();

    bool agregar = true;
    set<TipoEstadistica> estadisticasDeInteres;
    int opcion;

    while (agregar)
    {
        cout << "Digite la categoria que desea agregar: \n";
        cout << "1) Agregar total horas jugadas \n";
        cout << "2) Agregar Promedio rating \n";
        cout << "3) Agregar Cantidad Suscritos \n";

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Total horas jugadas agregado exitsosamente \n";
            estadisticasDeInteres.insert(horasJugadas);
            break;
        case 2:
            cout << "Promedio rating agregado exitosamente \n";
            estadisticasDeInteres.insert(promedioRating);
            break;
        case 3:
            cout << "Cantidad suscritos agregado exitosamente \n";
            estadisticasDeInteres.insert(cantidadSuscritos);
            break;
        }

        cout << "Desea agregar mas estadisticas? (y/n) \n";
        string seguirAgregando;
        cin >> seguirAgregando;

        agregar = seguirAgregando == "y" ? 1 : 0;
    }
    se->seleccionarEstadisticas(estadisticasDeInteres);
}

void menuConsultarEstadisticas(FactoryController *fact)
{
    IConsultarEstadisticas *ce = fact->getIConsultarEstadisticas();
    set<DataVideojuego> dtvjs = ce->obtenerVideojuegosPublicadosPorDesarrollador();
    set<DataVideojuego>::iterator it;
    cout << "Seleccione un videojuego para consultar sus estadisticas  \n";
    for (it = dtvjs.begin(); it != dtvjs.end(); it++)
    {
        DataVideojuego dataVideojuego = *it;
        cout << dataVideojuego.getNombre() << " \n";
    }
    string juegoName = "";
    cout << "Escriba el nombre del videojuego: ";
    cin >> juegoName;
    set<DataEstadistica> estadis = ce->calcularEstadisticas(juegoName);
    set<DataEstadistica>::iterator it2;
    cout << "Estadisticas \n";
    for (it2 = estadis.begin(); it2 != estadis.end(); it2++)
    {
        const DataEstadistica data = (*it2);
        cout << data << "\n";
    }
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
    Fecha fechaSist = Fecha(1, 1, 2021, 15, 30); //Fecha de ejemplo

    bool salirInicial = false;
    bool salirJugador = true;
    bool salirDev = true;

    int prompt = 0;

    while (!salirInicial)
    {
        salirJugador = true;
        salirDev = true;

        menuInicial();

        cout << ">";
        cin >> prompt;
        cout << "\n";

        switch (prompt)
        {
        case 1: //Alta de usuario
            try
            {
                menuAltaUsuario(fact);
            }
            catch (const invalid_argument &ex)
            {
                cout << ex.what() << '\n';
            }

            break;
        case 2: //Iniciar sesión
            try
            {
                menuIniciarSesion(fact, salirJugador, salirDev);
            }
            catch (const invalid_argument &ex)
            {
                cout << ex.what() << '\n';
            }

            break;
        case 3: //Cargar Datos de Prueba
            try
            {
                menuCargarDatosPrueba(uh, vh, ch);
            }
            catch (const invalid_argument &ex)
            {
                cout << ex.what() << '\n';
            }
            break;
        case 4: //Salir inicial
            salirInicial = true;
            menuSalirInicial();
            break;
        default:
            cout << "Por favor, elija un numero adecuado.\n";
            break;
        }

        while (!salirJugador)
        {

            menuJugador(uc->getSesion());

            cout << ">";
            cin >> prompt;
            cout << "\n";

            switch (prompt)
            {
            case 1: //Suscribirse a videojuego
                try
                {
                    menuSuscribirseVideojuego(fact, fechaSist);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 2: //Asignar puntaje a videojuego
                try
                {
                    menuAsignarPuntaje(fact);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 3: //Iniciar partida
                try
                {
                    menuIniciarPartida(fact, fechaSist);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 4: //Abandonar partida multijugador
                try
                {
                    menuAbandonarPartidaMulti(fact, fechaSist);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 5: //Finalizar partida
                try
                {
                    menuFinalizarPartida(fact, fechaSist);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 6: //Ver información de videojuego
                try
                {
                    menuVerInfoVideojuego(fact);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
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
                    menuModificarFechaSistema(dia, mes, anio, hora, minuto);
                    fechaSist = Fecha(dia, mes, anio, hora, minuto);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 8: // Salir Jugador
                salirJugador = true;
                //menuSalirUsuario(fact);
                break;

            default:
                cout << "Por favor, elija un numero adecuado.\n";
                break;
            }
        }

        while (!salirDev)
        {
            menuDesarrollador(uc->getSesion());

            cout << ">";
            cin >> prompt;
            cout << "\n";

            switch (prompt)
            {
            case 1: // Agregar categoría
                try
                {
                    menuAgregarCategoria(fact);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 2: //Publicar videojuego
                try
                {
                    menuPublicarVideojuego(fact);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 3: //Eliminar videojuego
                try
                {
                    menuEliminarVideojuego(fact);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 4: //Seleccionar estadísticas
                try
                {
                    menuSeleccionarEstadisticas(fact);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 5: //Consultar estadísticas
                try
                {
                    menuConsultarEstadisticas(fact);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 6: //Ver información de videojuego
                try
                {
                    menuVerInfoVideojuego(fact);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
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
                    menuModificarFechaSistema(dia, mes, anio, hora, minuto);
                    fechaSist = Fecha(dia, mes, anio, hora, minuto);
                }
                catch (const invalid_argument &ex)
                {
                    cout << ex.what() << '\n';
                }
                break;
            case 8: //Salir Dev
                salirDev = true;
                //menuSalirUsuario(fact);
                break;

            default:
                cout << "Por favor, elija un numero adecuado.\n";
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

    return 0;
}
