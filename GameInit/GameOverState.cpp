 //29   // GameOverState.cpp

#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "GameGraphics.h"
#include "PlayState.h"
#include "StateParser.h"

const std::string GameOverState::s_gameoverID = "GAMEOVER";

void GameOverState::s_gameoverToMain(){
    TheGame::Instance()->getStateMachine()->popState();
    TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay(){
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::update(){
    for(int i =0;i<_gameObjects.size();i++){
        _gameObjects[i]->update();
    }
}

void GameOverState::render(){
    for(int i =0;i<_gameObjects.size();i++){
        _gameObjects[i]->draw();
    }
}

//bool GameOverState::onEnter(){
//    if(!TheTextureManager::Instance()->load("assets/gameover.png","gameover",TheGame::Instance()->getRenderer())){
//        return false;
//    }
//    if(!TheTextureManager::Instance()->load("assets/Main_button.png","mainMenu",TheGame::Instance()->getRenderer())){
//        return false;
//    }
//    if(!TheTextureManager::Instance()->load("assets/Restart_button.png","Restart",TheGame::Instance()->getRenderer())){
//        return false;
//    }
//
//    GameObject * gameovertext= new GameGraphics(new LoaderParams(20,10,600,150,"gameover"));
//    GameObject * button1= new MenuButton(new LoaderParams(120,190,400,100,"mainMenu"),s_gameoverToMain);
//    GameObject * button2= new MenuButton(new LoaderParams(120,300,400,100,"Restart"),s_restartPlay);
//
//    _gameObjects.push_back(gameovertext);
//    _gameObjects.push_back(button1);
//    _gameObjects.push_back(button2);
//
//    std::cout<<"Entering MenuState"<<std::endl;
//}

bool GameOverState::onEnter()
{
    // parse the state
    StateParser stateParser;
    stateParser.parseState("test.xml", s_gameoverID, &_gameObjects, &m_textureIDList);
    m_callbacks.push_back(0);
    m_callbacks.push_back(s_gameoverToMain);
    m_callbacks.push_back(s_restartPlay);
    // set the callbacks for menu items
    setCallbacks(m_callbacks);
    std::cout << "entering PauseState\n";
    return true;
}

bool GameOverState::onExit() {
    for(int i =0;i < _gameObjects.size();i++){
        _gameObjects[i]->clean();
    }
    _gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("resume");
    TheTextureManager::Instance()->clearFromTextureMap("mainMenu");
    //reset the mouse button states to false
    TheInputHandler::Instance()->reset();

    std::cout<<"Exiting Menu State"<<std::endl;
    return true;
}
