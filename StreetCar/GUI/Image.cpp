#include "Image.h"
#include "graphics.h"

using namespace std;

Image::Image(SDL_Renderer *ren, const std::string &imageFile, int w, int h) : Element(ren) {
    rect.w = w;
    rect.h = h;
    texture = loadTexture(imageFile.c_str(), ren);
    if (texture == NULL){
	SDL_DestroyRenderer(ren);
        SDL_Quit();
    }
    //print(50, 50);
}


/*int Image::getWidth(){
    return rect.w;
}

int Image::getHeight(){
   return rect.h;
}*/

