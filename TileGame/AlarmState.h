//
//  AlarmState.h
//  TileGame
//
//  Created by athenaeum on 2014/11/15.
//
//

#ifndef __TileGame__AlarmState__
#define __TileGame__AlarmState__

#include "GameState.h"
#include <cocos2d.h>

using namespace cocos2d;

class AlarmState : public GameState
{
public:
    virtual void stateUpdate();
    virtual bool onStateEnter();
    virtual bool onStateExit();
    virtual void onInputEvent(CCPoint* pts);
    
    virtual std::string getStateID() { return s_alarmID; }
    
    AlarmState();
    ~AlarmState();
private:
    
    static const std::string s_alarmID;
    static void s_alarmToNormal();
    static void s_alarmToIdle();
};

#endif /* defined(__TileGame__AlarmState__) */
