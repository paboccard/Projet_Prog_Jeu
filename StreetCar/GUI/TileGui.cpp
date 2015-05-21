#include "TileGui.h"

TileGui::TileGui(ImagesData *data, idTile id, bool dde) : Element(data->tiles[id], dde), Tile(id) {

}
