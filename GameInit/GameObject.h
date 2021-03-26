 //10   // GameObject.h

#ifndef __GameObject__
#define __GameObject__
#include <string>
#include <SDL2/SDl.h>
#include "TextureManager.h"
#include "LoaderParams.h"

class GameObject {

public:


    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean() =0;

    //new load function
    virtual void load(const LoaderParams* pParams)=0;

private:

protected:

    GameObject(){}
    virtual ~GameObject() {}

};

#endif // __GameObject__
