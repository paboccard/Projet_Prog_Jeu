#include "Stop.h"


Stop::Stop(idTile t): Square(){
	type = t;
	linked = NULL;
}

bool Stop::isLinked(){
	return linked != NULL;
}
