//
//  GameObject.h
//  TileGame
//
//  Created by athenaeum on 2014/11/18.
//
//

#ifndef __TileGame__GameObject__
#define __TileGame__GameObject__

#include <iostream>
#include <cocos2d.h>

class GameObject : public cocos2d::CCSprite
{
public:
    //virtual void setStrategy();
    virtual void stateUpdate() = 0;
private:
    //std::string strategy;
    
};


#endif /* defined(__TileGame__GameObject__) */
