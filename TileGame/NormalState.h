//
//  NormalState.h
//  TileGame
//
//  Created by athenaeum on 2014/11/15.
//
//

#ifndef __TileGame__NormalState__
#define __TileGame__NormalState__

#include "GameState.h"
#include <cocos2d.h>

using namespace cocos2d;

class NormalState : public GameState
{
public:
    virtual void stateUpdate();
    virtual bool onStateEnter();
    virtual bool onStateExit();
    
    virtual std::string getStateID() { return s_normalID; }
    
    NormalState();
    ~NormalState();
    
private:
    
    static const std::string s_normalID;
    
};


#endif /* defined(__TileGame__NormalState__) */
