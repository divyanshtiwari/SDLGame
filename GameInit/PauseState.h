 //26   // PauseState.h
#ifndef __PauseState__
#define __PauseState__
#include "GameObject.h"
#include <vector>
#include "GameState.h"
#include "MenuState.h"
class PauseState:public MenuState{
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();
    virtual void setCallbacks(const std::vector<Callback>& callbacks);
    virtual std::string getStateId() const {return s_pauseID;}

private:
    static void s_pauseToMain();
    static void s_resumePlay();

    static const std::string s_pauseID;

    std::vector<GameObject * > _gameObjects;

};

#endif // __PauseState__
