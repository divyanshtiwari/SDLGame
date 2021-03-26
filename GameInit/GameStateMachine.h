 //20   // GameStateMachine.h

#ifndef __GameStateMachine__
#define __GameStateMachine__

#include "GameState.h"
#include <vector>
class GameStateMachine{
public:
    GameStateMachine() {}
    ~GameStateMachine() {}
    void update();
    void render();
    void pushState(GameState * pState);
    void changeState(GameState * pState);
    void popState();

private:
    std::vector<GameState * > _gameStates;

};

#endif // __GameStateMachine__
