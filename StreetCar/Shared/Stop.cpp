#include "Stop.h"


Stop::Stop(idTile t): Square(t){
	linked = NULL;
}

bool Stop::isLinked(){
	return linked != NULL;
}
