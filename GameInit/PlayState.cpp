 //23   // PlayState.cpp

#include "PlayState.h"
#include "Game.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "StateParser.h"

const std::string PlayState::_playId = "PLAY";

void PlayState::update(){
    //std::cout<<"Nothing to update in Play"<<std::endl;
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)){
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    }

    for(std::vector<GameObject *>::size_type i =0; i!= m_gameObjects.size(); i++){
        m_gameObjects[i]->update();
    }

    if(checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]),dynamic_cast<SDLGameObject*>(m_gameObjects[1]))){
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
    }
}

void PlayState::render() {
    //std::cout<<"Renderer works in Play"<<std::endl;
    for(std::vector<GameObject *> ::size_type i=0; i != m_gameObjects.size(); i++){
        m_gameObjects[i]->draw();

    }


}

//bool PlayState::onEnter() {
//    if(!TheTextureManager::Instance()->load("assets/helicopter.png","helicopter",TheGame::Instance()->getRenderer())){
//        return false;
//    }
//    GameObject * player = new Player(new LoaderParams(500,100,128,82,"helicopter"));
//
//    if(!TheTextureManager::Instance()->load("assets/helicopter2.png","helicopter2",TheGame::Instance()->getRenderer())){
//        return false;
//    }
//    GameObject * enemy = new Enemy(new LoaderParams(100,100,128,82,"helicopter2"));
//
//    m_gameObjects.push_back(player);
//    m_gameObjects.push_back(enemy);
//
//    std::cout<<"Entering PlayState"<<std::endl;
//
//    return true;
//}

bool PlayState::onEnter()
{
    // parse the state
    StateParser stateParser;
    stateParser.parseState("test.xml", _playId, &m_gameObjects,&m_textureIDList);
    std::cout << "entering PlayState\n";
    return true;
}

bool PlayState::onExit(){
    std::cout<<"Exiting Play State"<<std::endl;
    return true;
}

bool PlayState::checkCollision(SDLGameObject * p1, SDLGameObject * p2){
    int leftA, leftB;
    int rightA, rightB;
    int topA,topB;
    int bottomA,bottomB;

    //p1
    leftA = p1->getPositon().getX();
    rightA = p1->getPositon().getX()+p1->getWidth();
    topA = p1->getPositon().getY();
    bottomA= p1->getPositon().getY() +p1->getHeight();

    //p2
    leftB = p2->getPositon().getX();
    rightB = p2->getPositon().getX()+p2->getWidth();
    topB = p2->getPositon().getY();
    bottomB= p2->getPositon().getY() +p2->getHeight();

    if(bottomA <=topB){return false;}
    if(topA >= bottomB) {return false;}
    if(rightA <=leftB) {return false;}
    if(leftA >= rightB) {return false;}

    return true;
}
