 //31   // GameGraphics.cpp

#include "GameGraphics.h"

GameGraphics::GameGraphics() :
SDLGameObject()
{
}
void GameGraphics::draw()
{
SDLGameObject::draw("MENU"); // we now use SDLGameObject
}


void GameGraphics::update()
{
    m_currentFrame = 0;
}

void GameGraphics::load(const LoaderParams * pParams){
    SDLGameObject::load(pParams);
}

