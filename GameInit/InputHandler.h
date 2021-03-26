 //8   // InputHandler.h

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "Game.h"
enum mouse_buttons {LEFT = 0, MIDDLE = 1, RIGHT = 2};

class InputHandler
{
public:

    void update();
    void clean();
    void reset();
    void initialiseJoysticks();
    int xvalue(int joy, int stick);
    int yvalue(int joy, int stick);
    bool joysticksInitialised() {
        return m_bJoysticksInitialised;
    }


    static InputHandler* Instance()
    {
        if(s_pInstance == nullptr)
        {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }

    bool getButtonState(int joy, int buttonNumber){
        return m_buttonStates[joy][buttonNumber];
    }
    bool getMouseButtonState(int buttonNumber){
        return m_mouseButtonStates[buttonNumber];
    }
    Vector2D * getMousePosition(){
        return m_mousePosition;
    }
    bool isKeyDown(SDL_Scancode key);

private:

    InputHandler();
    ~InputHandler();

    Vector2D* m_mousePosition ;

    const Uint8 * m_keystate;


    std::vector<bool> m_mouseButtonStates;

    std::vector<std::vector<bool>> m_buttonStates;
    std::vector<SDL_Joystick * > m_joysticks;
    bool m_bJoysticksInitialised;
    std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
    static InputHandler* s_pInstance;
    const int m_joystickDeadZone = 10000;

    //private function to handle different event types

    //handle keyboard events
    void onKeyDown(){
        m_keystate = SDL_GetKeyboardState(0);
    }
    void OnKeyUp(){
        m_keystate = SDL_GetKeyboardState(0);
    }

    //handle mouse events
    void onMouseMove(SDL_Event & event){
        if(event.type == SDL_MOUSEMOTION){
            m_mousePosition->setX(event.motion.x);
            m_mousePosition->setY(event.motion.y);
        }
    }
    void onMouseButtonUp(SDL_Event & event){
        if(event.type == SDL_MOUSEBUTTONUP){
            if(event.button.button == SDL_BUTTON_LEFT){
                m_mouseButtonStates[LEFT]=false;
            }
            if(event.button.button == SDL_BUTTON_MIDDLE){
                m_mouseButtonStates[MIDDLE]=false;
            }
            if(event.button.button == SDL_BUTTON_RIGHT){
                m_mouseButtonStates[RIGHT]=false;
            }
        }
    }
    void onMouseButtonDown(SDL_Event & event){
        if(event.type == SDL_MOUSEBUTTONDOWN){
            if(event.button.button == SDL_BUTTON_LEFT){
                m_mouseButtonStates[LEFT]=true;
            }
            if(event.button.button == SDL_BUTTON_MIDDLE){
                m_mouseButtonStates[MIDDLE]=true;
            }
            if(event.button.button == SDL_BUTTON_RIGHT){
                m_mouseButtonStates[RIGHT]=true;
            }
        }
    }

    //handle joystick events
    void OnJoystickAxisMove(SDL_Event & event ){
        if(event.type == SDL_JOYAXISMOTION)
        {
            int whichOne = event.jaxis.which;
            // left stick move left or right
            if(event.jaxis.axis == 0)
            {
                if (event.jaxis.value > m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setX(1);


                }
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setX(-1);

                }
                else
                {
                    m_joystickValues[whichOne].first->setX(0);
                }
            }
            // left stick move up or down
            if(event.jaxis.axis == 1)
            {
                if (event.jaxis.value > m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setY(1);
                }
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setY(-1);
                }
                else
                {
                    m_joystickValues[whichOne].first->setY(0);
                }
            }
            // right stick move left or right
            if(event.jaxis.axis == 3)
            {
                if (event.jaxis.value > m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].second->setX(1);
                }
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].second->setX(-1);
                }
                else
                {
                    m_joystickValues[whichOne].second->setX(0);
                }
            }
                // right stick move up or down
            if(event.jaxis.axis == 4)
            {
                if (event.jaxis.value > m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].second->setY(1);
                }
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].second->setY(-1);
                }
                else
                {
                    m_joystickValues[whichOne].second->setY(0);
                }
            }
        }
    }
    void OnJoystickButtonDown(SDL_Event & event ){
        if(event.type == SDL_JOYBUTTONDOWN){
            int whichone = event.jaxis.which;
            //std::cout<<cnt<<whichone<<"true"<<std::endl;
            m_buttonStates[whichone][event.jbutton.button]= true;
        }
    }
    void OnJoystickButtonUp(SDL_Event & event ){
        if(event.type == SDL_JOYBUTTONUP){
            int whichone = event.jaxis.which;
            //std::cout<<cnt<<whichone<<"false"<<std::endl;

            m_buttonStates[whichone][event.jbutton.button] = false;
        }
    }
};
typedef InputHandler TheInputHandler;

#endif // INPUTHANDLER_H
