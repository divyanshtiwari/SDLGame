 //2   // Game.h

#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "InputHandler.h"
#include<string>
#include "GameStateMachine.h"

//enum game_states {
//MENU =0,
//PLAY =1,
//GAMEOVER = 2
//};

class Game{
    public:

        ~Game(){}

        bool init(std::string title,int xPos , int yPos , int width , int height , bool fullscreen);

        void render();
        void update();
        void handleEvents();
        void clean();
        void quit();
        // getter
        bool running() {return m_bRunning;}

        static Game* Instance() {
            if(s_pInstance == nullptr){
                s_pInstance = new Game();
            }
            return s_pInstance;
        }

        SDL_Renderer * getRenderer() const {
        return m_pRenderer;
        }

        GameStateMachine * getStateMachine(){ return _gameStateMachine;}
    private:
        Game(){}

        static Game * s_pInstance;

        SDL_Window* m_pWindow = nullptr;
        SDL_Renderer* m_pRenderer = nullptr;


        int m_currentFrame;
        bool m_bRunning;


        std::vector<GameObject *> m_gameObjects;

        GameStateMachine * _gameStateMachine;

};
typedef Game TheGame;

#endif // __Game__
