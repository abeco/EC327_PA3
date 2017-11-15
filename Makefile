# in EC327, we use the ${GCC} compiler
# therefore, we define the GCC variable
GCC = g++ 


#HighCs: pa3.o GameObject.o Sailor.o Dock.o Port.o CartPoint.o CartVector.o Model.o View.o GameCommand.o
#	${GCC} pa3.o GameObject.o Sailor.o Dock.o Port.o CartPoint.o CartVector.o Model.o View.o GameCommand.o -o HighCs

HighCs: CartPoint.o CartVector.o GameObject.o Port.o Dock.o Sailor.o Model.o View.o GameCommand.o pa3.o
	${GCC} CartPoint.o CartVector.o GameObject.o Port.o Dock.o Sailor.o Model.o View.o GameCommand.o pa3.o -o HighCs

pa3.o: pa3.cpp
	${GCC} -c pa3.cpp

GameObject.o: GameObject.cpp
	${GCC} -c GameObject.cpp

Sailor.o: Sailor.cpp
	${GCC} -c Sailor.cpp

Dock.o: Dock.cpp
	${GCC} -c Dock.cpp

Port.o: Port.cpp
	${GCC} -c Port.cpp

CartPoint.o: CartPoint.cpp
	${GCC} -c CartPoint.cpp

CartVector.o: CartVector.cpp
	${GCC} -c CartVector.cpp

CheckPoint3.o: CheckPoint3.cpp
	${GCC} -c CheckPoint3.cpp

Model.o: Model.cpp
	${GCC} -c -std=c++11 Model.cpp

View.o: View.cpp
	${GCC} -c View.cpp

GameCommand.o: GameCommand.cpp
	${GCC} -c GameCommand.cpp

clean:
#	rm pa3.o GameObject.o Sailor.o Dock.o Port.o CartPoint.o CartVector.o Model.o View.o GameCommand.o HighCs

	rm CartPoint.o CartVector.o GameObject.o Port.o Dock.o Sailor.o Model.o View.o GameCommand.o pa3.o HighCs
