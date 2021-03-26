 //5   // TextureManager.cpp

#include "TextureManager.h"
#include <SDL_image.h>

TextureManager* TextureManager::s_pInstance = nullptr;


bool TextureManager::load(std::string fileName,std::string id, SDL_Renderer * pRenderer){

    SDL_Surface * pTempSurface = IMG_Load(fileName.c_str());

    if(pTempSurface == nullptr){
        return false;
    }

    SDL_Texture * pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

    SDL_FreeSurface(pTempSurface);

    //everything went okay, add the texture to our list
     if(pTexture!=nullptr){
        m_textureMap[id] = pTexture;
        return true;
     }

    // reached here mean something went wrong
    return false;

}

void TextureManager::draw(std::string id , int x, int y, int w , int h, SDL_Renderer * pRenderer, SDL_RendererFlip flip){

    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w= w;
    srcRect.h = destRect.h = h;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id],&srcRect, &destRect,0,0,flip);

}

void TextureManager::drawframe(std::string id, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip){


    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = w * currentFrame;
    srcRect.y = h * (currentRow -1);
    srcRect.w = destRect.w = w;
    srcRect.h = destRect.h = h;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
&destRect, 0, 0, flip);

}

void TextureManager::clearFromTextureMap(std::string id){
    m_textureMap.erase(id);
}
