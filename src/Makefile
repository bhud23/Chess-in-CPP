CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = chess
# --> include all of the object files here, make sure to add them as you go
OBJECTS = main.o textdisplay.o game.o subject.o bishop.o  blank.o gamemanager.o king.o knight.o pawn.o piece.o queen.o rook.o human.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
