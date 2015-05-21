#ifndef TILEGUI_H
#define TILEGUI_H

#include "Element.h"
#include "../Shared/Utils.h"

class TileGui : public Element, public Tile {
	public:
		TileGui(ImagesData *data, idTile id, bool dde = false);

	private:
		
};

#endif
