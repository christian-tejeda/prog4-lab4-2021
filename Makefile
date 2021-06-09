
#----------- Headers ----------

H_CONTROLLERS = headers/controllers
H_DATATYPES = headers/datatypes
H_ENTITIES = headers/entities
H_HANDLERS = headers/handlers
INTERFACES = headers/interfaces
H_UTILS = headers/utils
H_FACTORY_CONTROLLER = headers/FactoryController.h

#---------- Source -----------

CPP_CONTROLLERS = src/controllers
CPP_DATATYPES = src/datatypes
CPP_ENTITIES = src/entities
CPP_HANDLERS = src/handlers
CPP_UTILS = src/utils
CPP_FACTORY_CONTROLLER = src/FactoryController.cpp

#---------- GCC --------------

GCC = g++ -c

#---------- Main --------------

main: PartidaController.o 
	  UsuarioController.o 
	  VideojuegoController.o 
	  DataCategoria.o 
	  DataContratoSuscripcion.o 
	  DataDesarrollador.o 
	  DataEstadistica.o 
	  DataGenero.o
	  DataJugador.o
	  DataPartida.o
	  DataPartidaIndividual.o
	  DataPartidaMultijugador.o
	  DataPlataforma.o
	  DataUsuario.o
	  DataVideojuego.o
	  Categoria.o
	  ContextoEstadistica.o
	  ContratoSuscripcion.o
	  Desarrollador.o
	  DuracionParticipante.o
	  Genero.o
	  Jugador.o
	  Partida.o
	  PartidaIndividual.o
	  PartidaMultijugador.o
	  Plataforma.o
	  Usuario.o
	  Videojuego.o
	  CategoriaHandler.o
	  UsuarioHandler.o
	  VideojuegoHandler.o
	  Fecha.o
	  FactoryController.o
	g++ obj/PartidaController.o 
		obj/UsuarioController.o 
		obj/VideojuegoController.o 
		obj/DataCategoria.o 
		obj/DataContratoSuscripcion.o 
		obj/DataDesarrollador.o 
		obj/DataEstadistica.o 
		obj/DataGenero.o 
		obj/DataJugador.o
		obj/DataPartida.o
		obj/DataPartidaIndividual.o
		obj/DataPartidaMultijugador.o
		obj/DataPlataforma.o
		obj/DataUsuario.o
		obj/DataVideojuego.o
		obj/Categoria.o
		obj/ContextoEstadistica.o
		obj/ContratoSuscripcion.o
		obj/Desarrollador.o
		obj/DuracionParticipante.o
		obj/Genero.o
		obj/Jugador.o
		obj/Partida.o
		obj/PartidaIndividual.o
		obj/PartidaMultijugador.o
		obj/Plataforma.o
		obj/Usuario.o
		obj/Videojuego.o
		obj/CategoriaHandler.o
		obj/UsuarioHandler.o
		obj/VideojuegoHandler.o
		obj/Fecha.o
		obj/FactoryController.o -o main

#------------- Objects ------------------

main.o: main.cpp
	$(GCC) main.cpp -o obj/main.o

PartidaController.o: $(CPP_CONTROLLERS)/PartidaController.cpp $(H_CONTROLLERS)/PartidaController.h
	$(GCC) $(CPP_CONTROLLERS)/PartidaController.cpp -o obj/PartidaController.o

UsuarioController.o: $(CPP_CONTROLLERS) $(H_CONTROLLERS)
	$(GCC) $(CPP_CONTROLLERS) -o obj/UsuarioController.o

VideojuegoController.o: $(CPP_CONTROLLERS) $(H_CONTROLLERS)
	$(GCC) $(CPP_CONTROLLERS) -o obj/VideojuegoController.o

DataCategoria.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataCategoria.o

DataContratoSuscripcion.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataContratoSuscripcion.o

DataDesarrollador.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataDesarrollador.o

DataEstadistica.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataEstadistica.o

DataGenero.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataGenero.o

DataJugador.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataJugador.o

DataPartida.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataPartida.o

DataPartidaIndividual.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataPartidaIndividual.o

DataPartidaMultijugador.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataPartidaMultijugador.o

DataPlataforma.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataPlataforma.o

DataUsuario.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataUsuario.o

DataVideojuego.o: $(CPP_DATATYPES) $(H_DATATYPES)
	$(GCC) $(CPP_DATATYPES) -o obj/DataVideojuego.o

Categoria.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/Categoria.o

ContextoEstadistica.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/ContextoEstadistica.o

ContratoSuscripcion.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/ContratoSuscripcion.o

Desarrollador.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/Desarrollador.o

DuracionParticipante.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/DuracionParticipante.o

Genero.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/Genero.o

Jugador.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/Jugador.o

Partida.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/Partida.o

PartidaIndividual.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/PartidaIndividual.o

PartidaMultijugador.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/PartidaMultijugador.o

Plataforma.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/Plataforma.o

Usuario.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/Usuario.o

Videojuego.o: $(CPP_ENTITIES) $(H_ENTITIES)
	$(GCC) $(CPP_ENTITIES) -o obj/Videojuego.o

CategoriaHandler.o: $(CPP_HANDLERS) $(H_HANDLERS)
	$(GCC) $(CPP_HANDLERS) -o obj/CategoriaHandler.o

UsuarioHandler.o: $(CPP_HANDLERS) $(H_HANDLERS)
	$(GCC) $(CPP_HANDLERS) -o obj/UsuarioHandler.o

VideojuegoHandler.o: $(CPP_HANDLERS) $(H_HANDLERS)
	$(GCC) $(CPP_HANDLERS) -o obj/VideojuegoHandler.o

Fecha.o: $(CPP_UTILS) $(H_UTILS)
	$(GCC) $(CPP_UTILS) -o obj/Fecha.o

FactoryController.o: $(CPP_FACTORY_CONTROLLER) $(H_FACTORY_CONTROLLER)
	$(GCC) $(CPP_FACTORY_CONTROLLER) -o obj/FactoryController.o

#--------- Extra --------------

clean:
	rm obj/*.o main

printcpp : cpp/$(wildcard *.cpp)
	ls -la $?

