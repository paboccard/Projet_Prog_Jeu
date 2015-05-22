#ifndef TILEGUI_H
#define TILEGUI_H

#include "Element.h"
#include "../Shared/Utils.h"
#include "../Shared/Tile.h"
#include "UtilsGui.h"

class TileGui : public Element, public Tile {
	public:
		TileGui(SDL_Renderer *r, ImagesData *data, idTile id, bool dde = false);

	private:
		
};

#endif
