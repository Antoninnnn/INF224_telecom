##########################################
#
#  Exemple de Makefile
#  Eric Lecolinet - Reda Dehak - Telecom ParisTech 2015
#  INF224 - TP C++ - http://www.telecom-paristech.fr/~elc/inf224
#
#  Implemented and appropriated by Yining YANG
#
#
##########################################

##########################################
#
#	Utilisation consigne:
#	make 
#	./server
#
##########################################

##########################################
#
#	Clean consigne:
#	cd INF224/c++
#	make clean
#	cd INF224/c++/tcpserver/
#	make clean -f Makefile-cliserv
#
##########################################

#
# Nom du programme
#
PROG = myprog

EXEC = test

CLIENT=client
SERVER=server
CLISERV=cliserv

#
# Fichiers sources (NE PAS METTRE les .h ni les .o seulement les .cpp)
#
SOURCES = multimedia.cpp main.cpp
CLIENT_SOURCES=multimedia.cpp tcpserver/client.cpp tcpserver/ccsocket.cpp 
SERVER_SOURCES=multimedia.cpp tcpserver/server.cpp tcpserver/tcpserver.cpp tcpserver/ccsocket.cpp 
CLISERV_SOURCES=multimedia.cpp tcpserver/client.cpp tcpserver/server.cpp tcpserver/tcpserver.cpp tcpserver/ccsocket.cpp tcpserver/Makefile-cliserv



#
# Fichiers objets (ne pas modifier sauf si l'extension n'est pas .cpp)
#
OBJETS = ${SOURCES:%.cpp=%.o}
CLIENT_OBJETS=${CLIENT_SOURCES:%.cpp=%.o}
SERVER_OBJETS=${SERVER_SOURCES:%.cpp=%.o}

#
# Compilateur C++
#
CXX = c++

#
# Options du compilateur C++
#   -g pour debugger, -O optimise, -Wall affiche les erreurs, -I pour les headers
#   -std=c++11 pour C++11
# Exemple: CXXFLAGS= -std=c++11 -Wall -O -I/usr/local/qt/include
#
CXXFLAGS = -std=c++11 -Wall -g

#
# Options de l'editeur de liens
#
LDFLAGS = 

#
# Librairies a utiliser
# Exemple: LDLIBS = -L/usr/local/qt/lib -lqt
#
LDLIBS = -lpthread 


##########################################
#
# Regles de construction/destruction des .o et de l'executable
# depend-${PROG} sera un fichier contenant les dependances
#
 
all: ${PROG} ${CLIENT} ${SERVER}

#run: ${PROG}
#	./${PROG}

run-${SERVER}: ${SERVER}
	./${SERVER}

run-${CLIENT}: ${CLIENT}
	./${CLIENT}

${PROG}: depend-${PROG} ${OBJETS}
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${OBJETS} ${LDLIBS}
${CLIENT}: depend-${CLIENT} ${CLIENT_OBJETS}
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${CLIENT_OBJETS} ${LDLIBS}

${SERVER}: depend-${SERVER} ${SERVER_OBJETS}
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${SERVER_OBJETS} ${LDLIBS}


clean:
	-@$(RM) *.o depend-${PROG} depend-${CLIENT} depend-${SERVER} core 1>/dev/null 2>&1

clean-all: clean
	-@$(RM) -${PROG} -${CLIENT} -${SERVER} 1>/dev/null 2>&1
  
tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}
	tar cvf ${CLISERV}.tar.gz ${CLISERV_SOURCES}

# Gestion des dependances : creation automatique des dependances en utilisant 
# l'option -MM de g++ (attention tous les compilateurs n'ont pas cette option)
#
depend-${PROG}:
	${CXX} ${CXXFLAGS} -MM ${SOURCES} > depend-${PROG}
depend-${CLIENT}:
	${CXX} ${CXXFLAGS} -MM ${CLIENT_SOURCES} > depend-${CLIENT}

depend-${SERVER}:
	${CXX} ${CXXFLAGS} -MM ${SERVER_SOURCES} > depend-${SERVER}


###########################################
#
# Regles implicites
#

.SUFFIXES: .cpp .cxx .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c (CFLAGS) $(INCPATH) -o $@ $<


#############################################
#
# Inclusion du fichier des dependances
#
-include depend-${PROG}
-include depend-${CLIENT}
-include depend-${SERVER}