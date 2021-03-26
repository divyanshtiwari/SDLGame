 //18   // MenuState.h

#ifndef __MenuState__
#define __MenuState__
#include "GameState.h"
#include <vector>
#include "GameObject.h"

class MenuState : public GameState
{
protected:
typedef void(*Callback)();
virtual void setCallbacks(const std::vector<Callback> &callbacks)= 0;
std::vector<Callback> m_callbacks;
};

class MainMenuState:public MenuState{
public:
    MainMenuState() {}
    ~MainMenuState() {}
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateId() const {return _menuId; }

private:

    static const std::string _menuId;
    std::vector<GameObject * > m_gameObjects;
    virtual void setCallbacks(const std::vector<Callback> &callbacks);

    //call back functions for menu items
    static void s_menuToPlay();
    static void s_exitFromMenu();


};

#endif // __MenuState__
