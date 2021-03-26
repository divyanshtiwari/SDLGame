 //22   // PlayState.h

#ifndef __PlayState__
#define __PlayState__
#include "GameState.h"
#include "GameObject.h"
#include <vector>
#include "SDLGameObject.h"
class PlayState:public GameState{
public:
    PlayState() {}
    ~PlayState() {}
    virtual void update() ;
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateId() const {return _playId;}

    bool checkCollision(SDLGameObject * p1, SDLGameObject * p2);

private:
    static const std::string _playId;

    std::vector<GameObject*> m_gameObjects;
};
#endif // __PlayState__

