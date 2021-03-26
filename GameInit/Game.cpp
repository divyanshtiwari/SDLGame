 //3   // Game.cpp
#include "Game.h"
#include <SDL_image.h>
#include "MenuState.h"
#include "PlayState.h"
#include "GameObjectFactory.h"
#include "MenuButton.h"
#include "GameGraphics.h"
Game * Game::s_pInstance = nullptr;

bool Game::init(std::string title,int xPos , int yPos , int width , int height , bool fullscreen){
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout<<"SDL init success"<<std::endl;
        m_pWindow = SDL_CreateWindow(title.c_str(),xPos,yPos,width,height, flags);
        if(m_pWindow != nullptr){
            std::cout<<"Window creation success"<<std::endl;
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer!=nullptr){
                std::cout<<"Renderer creation success"<<std::endl;
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0 , 255); //156, 100, 12 ,
            }
            else{
                std::cout<<"Renderer init failed"<<std::endl;
                return false;
            }
        }
        else{
            std::cout<<"Window inti failed"<<std::endl;
            return false;
        }
    }
    else{
        std::cout<<"SDL intit fail"<<std::endl;
        return false;
    }

    std::cout<<"Init success"<<std::endl;
    m_bRunning = true; // start game loop

    TheInputHandler::Instance()->initialiseJoysticks();

    //_gameStateMachine = new GameStateMachine();
    //_gameStateMachine->changeState(new MenuState());

    TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
    TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
    TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
    TheGameObjectFactory::Instance()->registerType("GameGraphics", new GameGraphicsCreator());

    return true;


}

void Game::render(){

    SDL_RenderClear(m_pRenderer);

    _gameStateMachine->render();

//    for(std::vector<GameObject *> ::size_type i=0; i != m_gameObjects.size(); i++){
//        m_gameObjects[i]->draw();
//    }

    SDL_RenderPresent(m_pRenderer);
}

void Game::clean(){

    std::cout << "cleaning game"<<std::endl;
    TheInputHandler::Instance()->clean();
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::handleEvents() {
    TheInputHandler::Instance()->update();

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)){
        _gameStateMachine->changeState(new PlayState());
    }
}

void Game::update(){

    _gameStateMachine->update();
//        for(std::vector<GameObject *>::size_type i =0; i!= m_gameObjects.size(); i++){
//            m_gameObjects[i]->update();
//        }
}

void Game::quit(){
    m_bRunning = false;
}
