 //25   // MenuButton.cpp

#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton():SDLGameObject(){

    m_currentFrame = MOUSE_OUT; // start at zero


}

void MenuButton::draw(){
    SDLGameObject::draw("MENU"); //use the base class drawing function
}

void MenuButton::update(){
    Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();
    if(pMousePos->getX() < (m_position.getX() + m_w)
    && pMousePos->getX() > m_position.getX()
    && pMousePos->getY() < (m_position.getY() + m_h)
    && pMousePos->getY() > m_position.getY()) {
        m_currentFrame = MOUSE_OVER;
        if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased){
            m_currentFrame= CLICKED;
            m_callback(); // call our callback function
            m_bReleased = false;
        }
        else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT)){
            m_bReleased = true;
            m_currentFrame = MOUSE_OVER;
        }
    }
    else {
        m_currentFrame = MOUSE_OUT;
    }
}

void MenuButton::clean(){
    SDLGameObject::clean();
}
void MenuButton::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
	//m_callback = pParams->getCallbackID();
	m_currentFrame = MOUSE_OUT;
}
