 //27   // PauseState.cpp

#include "PauseState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "StateParser.h"
const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain(){
    TheGame::Instance()->getStateMachine()->popState();
    TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::s_resumePlay(){
    TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update(){
    for(int i =0;i<_gameObjects.size();i++){
        _gameObjects[i]->update();
    }
}

void PauseState::render(){
    for(int i =0;i<_gameObjects.size();i++){
        _gameObjects[i]->draw();
    }
}

//bool PauseState::onEnter(){
//    if(!TheTextureManager::Instance()->load("assets/Main_button.png","mainMenu",TheGame::Instance()->getRenderer())){
//        return false;
//    }
//    if(!TheTextureManager::Instance()->load("assets/Resume_button.png","Resume",TheGame::Instance()->getRenderer())){
//        return false;
//    }
//
//    GameObject * button1= new MenuButton(new LoaderParams(120,100,400,100,"mainMenu"),s_pauseToMain);
//    GameObject * button2= new MenuButton(new LoaderParams(120,300,400,100,"Resume"),s_resumePlay);
//
//    _gameObjects.push_back(button1);
//    _gameObjects.push_back(button2);
//
//    std::cout<<"Entering MenuState"<<std::endl;
//    return true;
//}

bool PauseState::onEnter()
{
    StateParser stateParser;
    stateParser.parseState("test.xml", s_pauseID, &_gameObjects,&m_textureIDList);
    m_callbacks.push_back(0);
    m_callbacks.push_back(s_pauseToMain);
    m_callbacks.push_back(s_resumePlay);
    setCallbacks(m_callbacks);
    std::cout << "entering PauseState\n";
    return true;
}

bool PauseState::onExit() {
    for(int i =0;i < _gameObjects.size();i++){
        _gameObjects[i]->clean();
    }
    _gameObjects.clear();
//    TheTextureManager::Instance()->clearFromTextureMap("resume");
//    TheTextureManager::Instance()->clearFromTextureMap("mainMenu");
        // clear the texture manager
    for(int i = 0; i < m_textureIDList.size(); i++){
        TheTextureManager::Instance()->
        clearFromTextureMap(m_textureIDList[i]);
    }
    //reset the mouse button states to false
    TheInputHandler::Instance()->reset();

    std::cout<<"Exiting Menu State"<<std::endl;
    return true;
}

void PauseState::setCallbacks(const std::vector<Callback> &callbacks){
    // go through the game objects
    for(int i = 0; i < _gameObjects.size(); i++){
        // if they are of type MenuButton then assign a callback based on the id passed in from the file
        if(dynamic_cast<MenuButton*>(_gameObjects[i])){
            MenuButton* pButton = dynamic_cast<MenuButton*>(_gameObjects[i]);
            pButton->setCallback(callbacks[pButton->getCallbackID()]);
        }
    }
}
