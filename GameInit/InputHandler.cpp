 //9   // InputHandler.cpp

#include "InputHandler.h"
#include <iostream>

InputHandler* InputHandler:: s_pInstance = nullptr;
InputHandler::InputHandler()
{
    for(int i=0; i<3 ; i++){
        m_mouseButtonStates.push_back(false);
    }
    m_mousePosition = new Vector2D(0, 0);
}

InputHandler::~InputHandler()
{
    //dtor
}
void InputHandler::initialiseJoysticks(){

    if(SDL_WasInit(SDL_INIT_JOYSTICK)== 0){
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }
    if(SDL_NumJoysticks()>0){
        for(int i =0; i<SDL_NumJoysticks(); i++){
            SDL_Joystick* joy = SDL_JoystickOpen(i);
            if(SDL_JoystickOpen(i) != nullptr){
                m_joysticks.push_back(joy);
                m_joystickValues.push_back(std::make_pair(new Vector2D(0,0), new Vector2D(0,0)));

                std::vector<bool> tempButtons;

                for(int j=0;j<SDL_JoystickNumButtons(joy);j++){
                    tempButtons.push_back(false);
                }

                m_buttonStates.push_back(tempButtons);
            }
            else{
                std::cout<< SDL_GetError();
            }
        }
        SDL_JoystickEventState(SDL_ENABLE);
        m_bJoysticksInitialised = true;

        std::cout<<"Initialised " << m_joysticks.size() << "joystick(s)";
    }
    else{
        m_bJoysticksInitialised = false;
    }
}

void InputHandler::clean(){
    if(m_bJoysticksInitialised){
        for( int i = 0; i < SDL_NumJoysticks(); i++){
            SDL_JoystickClose(m_joysticks[i]);
        }
    }
}

void InputHandler::reset(){
	m_mouseButtonStates[LEFT] = false;
	m_mouseButtonStates[MIDDLE] = false;
	m_mouseButtonStates[RIGHT] = false;
}
int InputHandler::yvalue(int joy, int stick)
{
    if(m_joystickValues.size() > 0)
    {
        if(stick == 1)
        {
            return m_joystickValues[joy].first->getY();
        }
        else if(stick == 2)
        {
            return m_joystickValues[joy].second->getY();
        }
    }
    return 0;
}

int InputHandler::xvalue(int joy, int stick)
{
    if(m_joystickValues.size() > 0)
    {
        if(stick == 1)
        {
            return m_joystickValues[joy].first->getX();
        }
        else if(stick == 2)
        {
            return m_joystickValues[joy].second->getX();
        }
    }
    return 0;
}
bool InputHandler::isKeyDown(SDL_Scancode key){
    if(m_keystate != 0){
        if(m_keystate[key]==1){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}


void InputHandler::update(){
    SDL_Event event;
    //m_keystate = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&event))
    {
        switch(event.type){
            //1
            case SDL_QUIT:
                TheGame::Instance()->quit();
                break;
            //2
            case SDL_JOYAXISMOTION:
                OnJoystickAxisMove(event);

                break;
            //3
            case SDL_JOYBUTTONUP:
                OnJoystickButtonUp(event);
                break;
            //4
            case SDL_JOYBUTTONDOWN:
                OnJoystickButtonDown(event);
                break;
            //5
            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;
            //6
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;
            //7
            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;
            //8
            case SDL_KEYDOWN:
                onKeyDown();
                break;
            //9
            case SDL_KEYUP:
                OnKeyUp();
                break;
            //10
            default:
                break;
        }
        //cnt++; // ignore
    }
}

