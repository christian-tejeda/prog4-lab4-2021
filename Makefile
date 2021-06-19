
#----------- Headers ----------

H_CONTROLLERS = headers/controllers
H_DATATYPES = headers/datatypes
H_ENTITIES = headers/entities
H_HANDLERS = headers/handlers
INTERFACES = headers/interfaces
H_UTILS = headers/utils
H_FACTORY_CONTROLLER = headers/FactoryController.h
H_FACTORY_STRATEGY_ESTADISTICA = headers/FactoryStrategyEstadistica.h

#---------- Source -----------

CPP_CONTROLLERS = src/controllers
CPP_DATATYPES = src/datatypes
CPP_ENTITIES = src/entities
CPP_HANDLERS = src/handlers
CPP_UTILS = src/utils
CPP_FACTORY_CONTROLLER = src/FactoryController.cpp
CPP_FACTORY_STRATEGY_ESTADISTICA = src/FactoryStrategyEstadistica.cpp

#---------- GCC --------------

GCC = g++ -c

#---------- Main --------------

main: PartidaController.o UsuarioController.o VideojuegoController.o DataCategoria.o DataContratoSuscripcion.o DataSuscripcionJugador.o  DataDesarrollador.o DataEstadistica.o DataJugador.o DataPartida.o DataPartidaIndividual.o DataPartidaMultijugador.o DataUsuario.o DataVideojuego.o Categoria.o ContratoSuscripcion.o Usuario.o Desarrollador.o DuracionParticipante.o Jugador.o Partida.o PartidaIndividual.o PartidaMultijugador.o Videojuego.o CategoriaHandler.o UsuarioHandler.o VideojuegoHandler.o Fecha.o FactoryController.o FactoryStrategyEstadistica.o CantidadSuscritosStrategy.o PromedioRatingStrategy.o TotalHorasJugadasStrategy.o main.o
	g++ -o main obj/PartidaController.o obj/UsuarioController.o obj/VideojuegoController.o obj/DataCategoria.o obj/DataContratoSuscripcion.o obj/DataSuscripcionJugador.o obj/DataDesarrollador.o obj/DataEstadistica.o obj/DataJugador.o obj/DataPartida.o obj/DataPartidaIndividual.o obj/DataPartidaMultijugador.o obj/DataUsuario.o obj/DataVideojuego.o obj/Categoria.o obj/ContratoSuscripcion.o obj/Desarrollador.o obj/DuracionParticipante.o obj/Jugador.o obj/Partida.o obj/PartidaIndividual.o obj/PartidaMultijugador.o obj/Usuario.o obj/Videojuego.o obj/CategoriaHandler.o obj/UsuarioHandler.o obj/VideojuegoHandler.o obj/Fecha.o obj/FactoryController.o obj/FactoryStrategyEstadistica.o obj/CantidadSuscritosStrategy.o obj/PromedioRatingStrategy.o obj/TotalHorasJugadasStrategy.o obj/main.o 
		

#------------- Objects ------------------

main.o: main.cpp
	$(GCC) main.cpp -o obj/main.o

PartidaController.o: $(CPP_CONTROLLERS)/PartidaController.cpp $(H_CONTROLLERS)/PartidaController.h
	$(GCC) $(CPP_CONTROLLERS)/PartidaController.cpp -o obj/PartidaController.o

UsuarioController.o: $(CPP_CONTROLLERS)/UsuarioController.cpp $(H_CONTROLLERS)/UsuarioController.h
	$(GCC) $(CPP_CONTROLLERS)/UsuarioController.cpp -o obj/UsuarioController.o

VideojuegoController.o: $(CPP_CONTROLLERS)/VideojuegoController.cpp $(H_CONTROLLERS)/VideojuegoController.h
	$(GCC) $(CPP_CONTROLLERS)/VideojuegoController.cpp -o obj/VideojuegoController.o

DataCategoria.o: $(CPP_DATATYPES)/DataCategoria.cpp $(H_DATATYPES)/DataCategoria.h
	$(GCC) $(CPP_DATATYPES)/DataCategoria.cpp -o obj/DataCategoria.o

DataContratoSuscripcion.o: $(CPP_DATATYPES)/DataContratoSuscripcion.cpp $(H_DATATYPES)/DataContratoSuscripcion.h
	$(GCC) $(CPP_DATATYPES)/DataContratoSuscripcion.cpp -o obj/DataContratoSuscripcion.o

DataDesarrollador.o: $(CPP_DATATYPES)/DataDesarrollador.cpp $(H_DATATYPES)/DataDesarrollador.h
	$(GCC) $(CPP_DATATYPES)/DataDesarrollador.cpp -o obj/DataDesarrollador.o

DataEstadistica.o: $(CPP_DATATYPES)/DataEstadistica.cpp $(H_DATATYPES)/DataEstadistica.h
	$(GCC) $(CPP_DATATYPES)/DataEstadistica.cpp -o obj/DataEstadistica.o

DataJugador.o: $(CPP_DATATYPES)/DataJugador.cpp $(H_DATATYPES)/DataJugador.h
	$(GCC) $(CPP_DATATYPES)/DataJugador.cpp -o obj/DataJugador.o

DataPartida.o: $(CPP_DATATYPES)/DataPartida.cpp $(H_DATATYPES)/DataPartida.h
	$(GCC) $(CPP_DATATYPES)/DataPartida.cpp -o obj/DataPartida.o

DataPartidaIndividual.o: $(CPP_DATATYPES)/DataPartidaIndividual.cpp $(H_DATATYPES)/DataPartidaIndividual.h
	$(GCC) $(CPP_DATATYPES)/DataPartidaIndividual.cpp -o obj/DataPartidaIndividual.o

DataPartidaMultijugador.o: $(CPP_DATATYPES)/DataPartidaMultijugador.cpp $(H_DATATYPES)/DataPartidaMultijugador.h
	$(GCC) $(CPP_DATATYPES)/DataPartidaMultijugador.cpp -o obj/DataPartidaMultijugador.o

DataUsuario.o: $(CPP_DATATYPES)/DataUsuario.cpp $(H_DATATYPES)/DataUsuario.h
	$(GCC) $(CPP_DATATYPES)/DataUsuario.cpp -o obj/DataUsuario.o

DataVideojuego.o: $(CPP_DATATYPES)/DataVideojuego.cpp $(H_DATATYPES)/DataVideojuego.h
	$(GCC) $(CPP_DATATYPES)/DataVideojuego.cpp -o obj/DataVideojuego.o

DataSuscripcionJugador.o: $(CPP_DATATYPES)/DataSuscripcionJugador.cpp $(H_DATATYPES)/DataSuscripcionJugador.h
	$(GCC) $(CPP_DATATYPES)/DataSuscripcionJugador.cpp -o obj/DataSuscripcionJugador.o	

Categoria.o: $(CPP_ENTITIES)/Categoria.cpp $(H_ENTITIES)/Categoria.h
	$(GCC) $(CPP_ENTITIES)/Categoria.cpp -o obj/Categoria.o

ContratoSuscripcion.o: $(CPP_ENTITIES)/ContratoSuscripcion.cpp $(H_ENTITIES)/ContratoSuscripcion.h
	$(GCC) $(CPP_ENTITIES)/ContratoSuscripcion.cpp -o obj/ContratoSuscripcion.o

Usuario.o: $(CPP_ENTITIES)/Usuario.cpp $(H_ENTITIES)/Usuario.h
	$(GCC) $(CPP_ENTITIES)/Usuario.cpp -o obj/Usuario.o

Desarrollador.o: $(CPP_ENTITIES)/Desarrollador.cpp $(H_ENTITIES)/Desarrollador.h
	$(GCC) $(CPP_ENTITIES)/Desarrollador.cpp -o obj/Desarrollador.o

DuracionParticipante.o: $(CPP_ENTITIES)/DuracionParticipante.cpp $(H_ENTITIES)/DuracionParticipante.h
	$(GCC) $(CPP_ENTITIES)/DuracionParticipante.cpp -o obj/DuracionParticipante.o

Jugador.o: $(CPP_ENTITIES)/Jugador.cpp $(H_ENTITIES)/Jugador.h
	$(GCC) $(CPP_ENTITIES)/Jugador.cpp -o obj/Jugador.o

Partida.o: $(CPP_ENTITIES)/Partida.cpp $(H_ENTITIES)/Partida.h
	$(GCC) $(CPP_ENTITIES)/Partida.cpp -o obj/Partida.o

PartidaIndividual.o: $(CPP_ENTITIES)/PartidaIndividual.cpp $(H_ENTITIES)/PartidaIndividual.h
	$(GCC) $(CPP_ENTITIES)/PartidaIndividual.cpp -o obj/PartidaIndividual.o

PartidaMultijugador.o: $(CPP_ENTITIES)/PartidaMultijugador.cpp $(H_ENTITIES)/PartidaMultijugador.h
	$(GCC) $(CPP_ENTITIES)/PartidaMultijugador.cpp -o obj/PartidaMultijugador.o

Videojuego.o: $(CPP_ENTITIES)/Videojuego.cpp $(H_ENTITIES)/Videojuego.h
	$(GCC) $(CPP_ENTITIES)/Videojuego.cpp -o obj/Videojuego.o

CantidadSuscritosStrategy.o: $(CPP_ENTITIES)/CantidadSuscritosStrategy.cpp $(H_ENTITIES)/CantidadSuscritosStrategy.h
	$(GCC) $(CPP_ENTITIES)/CantidadSuscritosStrategy.cpp -o obj/CantidadSuscritosStrategy.o

PromedioRatingStrategy.o: $(CPP_ENTITIES)/PromedioRatingStrategy.cpp $(H_ENTITIES)/PromedioRatingStrategy.h
	$(GCC) $(CPP_ENTITIES)/PromedioRatingStrategy.cpp -o obj/PromedioRatingStrategy.o

TotalHorasJugadasStrategy.o: $(CPP_ENTITIES)/TotalHorasJugadasStrategy.cpp $(H_ENTITIES)/TotalHorasJugadasStrategy.h
	$(GCC) $(CPP_ENTITIES)/TotalHorasJugadasStrategy.cpp -o obj/TotalHorasJugadasStrategy.o	

CategoriaHandler.o: $(CPP_HANDLERS)/CategoriaHandler.cpp $(H_HANDLERS)/CategoriaHandler.h
	$(GCC) $(CPP_HANDLERS)/CategoriaHandler.cpp -o obj/CategoriaHandler.o

UsuarioHandler.o: $(CPP_HANDLERS)/UsuarioHandler.cpp $(H_HANDLERS)/UsuarioHandler.h
	$(GCC) $(CPP_HANDLERS)/UsuarioHandler.cpp -o obj/UsuarioHandler.o

VideojuegoHandler.o: $(CPP_HANDLERS)/VideojuegoHandler.cpp $(H_HANDLERS)/VideojuegoHandler.h
	$(GCC) $(CPP_HANDLERS)/VideojuegoHandler.cpp -o obj/VideojuegoHandler.o

Fecha.o: $(CPP_UTILS)/Fecha.cpp $(H_UTILS)/Fecha.h
	$(GCC) $(CPP_UTILS)/Fecha.cpp -o obj/Fecha.o

FactoryController.o: $(CPP_FACTORY_CONTROLLER) $(H_FACTORY_CONTROLLER)
	$(GCC) $(CPP_FACTORY_CONTROLLER) -o obj/FactoryController.o

FactoryStrategyEstadistica.o: $(CPP_FACTORY_STRATEGY_ESTADISTICA) $(H_FACTORY_STRATEGY_ESTADISTICA)
	$(GCC) $(CPP_FACTORY_STRATEGY_ESTADISTICA) -o obj/FactoryStrategyEstadistica.o

#--------- Extra --------------

clean:
	rm obj/*.o main

printcpp : cpp/$(wildcard *.cpp)
	ls -la $?

