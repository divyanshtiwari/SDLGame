 //4   // TextureManager.h

#ifndef __TextureManager__
#define __TextureManager__
#include <string>
#include <SDL2/SDL.h>
#include <map>



class TextureManager {
public:
    //TextureManager(){};
    ~TextureManager(){};

    bool load(std::string fileName, std::string id, SDL_Renderer * pRenderer);

    // Draw
    void draw(std::string id,int x, int y, int w , int h, SDL_Renderer * pRenderer,SDL_RendererFlip flip = SDL_FLIP_NONE);

    //DrawFrame
    void drawframe(std::string id, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    std::map<std::string, SDL_Texture*> m_textureMap;

    void clearFromTextureMap(std::string id);

    static TextureManager * Instance(){
    if(s_pInstance == nullptr){
        s_pInstance = new TextureManager();
        return s_pInstance;
    }
    return s_pInstance;
}


private:
    TextureManager(){}; // for making this class a singleton
    static TextureManager* s_pInstance;

};

typedef TextureManager TheTextureManager;

#endif // __TextureManager__
