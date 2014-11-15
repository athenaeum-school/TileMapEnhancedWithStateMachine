//
//  NormalState.cpp
//  TileGame
//
//  Created by athenaeum on 2014/11/15.
//
//

#include "NormalState.h"
#include "cocos2d.h"

using namespace cocos2d;

const std::string NormalState::s_normalID = "NORMAL";

NormalState::NormalState() {
    std::cout << "NormalState::NormalState() normal state constructor\n";
}

NormalState::~NormalState() {
    
}

void NormalState::stateUpdate() {
    
}

bool NormalState::onStateEnter() {
    std::cout << "NormalState::onStateEnter()\n";
    return true;
}

bool NormalState::onStateExit() {
    return true;
}

