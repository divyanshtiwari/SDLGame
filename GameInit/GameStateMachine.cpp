 //21   // GameStateMachine.cpp

#include "GameStateMachine.h"

void GameStateMachine::update() {
    if(!_gameStates.empty()){
        _gameStates.back()->update();
    }
}

void GameStateMachine::render() {
    if(!_gameStates.empty()){
        _gameStates.back()->render();
    }
}



//Adding one state without removing the previous state
void GameStateMachine::pushState(GameState * pState){
    _gameStates.push_back(pState);
    _gameStates.back()->onEnter();
}

//Removing one state without adding another
void GameStateMachine::popState(){
    if(!_gameStates.empty()){
        if(_gameStates.back()->onExit()){
            delete _gameStates.back();
            _gameStates.pop_back();
        }
    }
}

//Removing one state and adding another
void GameStateMachine::changeState(GameState * pState){
    if(!_gameStates.empty()){
        if(_gameStates.back()->getStateId() == pState->getStateId()){
            return ; // do nothing
        }

        if(_gameStates.back()->onExit()){
            delete _gameStates.back();
            _gameStates.pop_back();
        }
    }
    // push new state;
    _gameStates.push_back(pState);

    //initialize it
    _gameStates.back()->onEnter();
}
