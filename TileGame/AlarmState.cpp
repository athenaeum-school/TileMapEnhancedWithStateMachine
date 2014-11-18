//
//  AlarmState.cpp
//  TileGame
//
//  Created by athenaeum on 2014/11/15.
//
//

#include "AlarmState.h"
#include "ObjectManager.h"
#include "NormalState.h"

const std::string AlarmState::s_alarmID = "ALARM";

void AlarmState::s_alarmToNormal() {
    Game::Instance()->getStateMachine()->changeState(new NormalState());
}

void AlarmState::s_alarmToIdle() {
    //Game::Instance()->getStateMachine()->changeState(new IdleState());
}

AlarmState::AlarmState() {
    //CCSprite* player = (CCSprite*) HelloWorld::s_pInstance->getChildByTag(0);
    //ccColor3B playerColor = {arc4random() % 255,arc4random() % 255,arc4random() % 255};
    //shirt->setColor(playerColor);
    //HelloWorld::s_pInstance->addChild(this);
}

AlarmState::~AlarmState() {
    
}

void AlarmState::stateUpdate() {
    
}

void AlarmState::onInputEvent() {
    
}

bool AlarmState::onStateEnter() {
    return true;
}

bool AlarmState::onStateExit() {
    return true;
}