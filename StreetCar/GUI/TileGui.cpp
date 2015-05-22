#include "TileGui.h"

TileGui::TileGui(SDL_Renderer *r, ImagesData *data, idTile id, bool dde) : Element(r, data->tiles[id]->getSurface(), dde), Tile(id) {

}
