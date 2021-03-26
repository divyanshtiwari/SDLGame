 //7   // SDLGameObject.cpp

#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(): GameObject()
{

}

void SDLGameObject:: load(const LoaderParams* pParams){

    m_position = Vector2D(pParams->getX(),pParams->getY());
    m_velocity= Vector2D(0,0);
    m_acceleration= Vector2D(0,0);
    m_w = pParams->getWidth();
    m_h = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_currentRow = 1;
    m_currentFrame = 1;
    m_numFrames = pParams->getNumFrames();

}


void SDLGameObject::draw(std::string id)
{
    static bool last=false;
    if(id=="PLAY"){
    if(m_velocity.getX() >0){
        TextureManager::Instance()->drawframe(m_textureID, (int)m_position.getX(), (int)m_position.getY(),
        m_w, m_h, m_currentRow, m_currentFrame,
        TheGame::Instance()->getRenderer(),SDL_FLIP_HORIZONTAL);
        last = true;
    }
    else if(m_velocity.getX() <0) {
        TextureManager::Instance()->drawframe(m_textureID, (int)m_position.getX(), (int)m_position.getY(),
        m_w, m_h, m_currentRow, m_currentFrame,
        TheGame::Instance()->getRenderer());
        last = false;
    }
    else{
        if(last){
            TextureManager::Instance()->drawframe(m_textureID, (int)m_position.getX(), (int)m_position.getY(),
            m_w, m_h, m_currentRow, m_currentFrame,
            TheGame::Instance()->getRenderer(),SDL_FLIP_HORIZONTAL);
        }
        if(!last){
            TextureManager::Instance()->drawframe(m_textureID, (int)m_position.getX(), (int)m_position.getY(),
            m_w, m_h, m_currentRow, m_currentFrame,
            TheGame::Instance()->getRenderer());
        }
    }
    }
    else if (id=="ENEMY"){
        TextureManager::Instance()->drawframe(m_textureID, (int)m_position.getX(), (int)m_position.getY(),
        m_w, m_h, m_currentRow, m_currentFrame,
        TheGame::Instance()->getRenderer(),SDL_FLIP_HORIZONTAL);
    }
    else{
        TextureManager::Instance()->drawframe(m_textureID, (int)m_position.getX(), (int)m_position.getY(),
        m_w, m_h, m_currentRow, m_currentFrame,
        TheGame::Instance()->getRenderer());
    }


}

