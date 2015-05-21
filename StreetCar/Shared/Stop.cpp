#include "Stop.h"


Stop::Stop(idTile t): Square(){
	type = t;
	linked = NULL;
}

Bool Stop::isLinked(){
	return linked != NULL;
}
