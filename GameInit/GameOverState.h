 //28   // GameOverState.h

#ifndef __GameOverState__
#define __GameOverState__
#include "GameObject.h"
#include <vector>
#include "GameState.h"
#include "MenuState.h"
class GameOverState:public MenuState{
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();
    virtual void setCallbacks(const std::vector<Callback>& callbacks);
    virtual std::string getStateId() const {return s_gameoverID;}

private:
    static void s_gameoverToMain();
    static void s_restartPlay();

    static const std::string s_gameoverID;

    std::vector<GameObject * > _gameObjects;

};

#endif // __GameOverState__

