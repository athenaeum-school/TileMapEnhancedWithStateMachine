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
    std::vector<GameObject*> gameObjects = Game::Instance()->getGameObjects();
    for (std::vector<GameObject*>::iterator it = gameObjects.begin() ; it != gameObjects.end(); ++it){
        float x = (*it)->getPositionX();
        float y = (*it)->getPositionY();
    }
}

void NormalState::onInputEvent(CCPoint* diff) {
    
    playerPos = Game::Instance()->getGameObjects()->findPlayer()->getPosition();
    
    if(diff){
        if ( abs(diff->x) > abs(diff->y) ) {
            if (diff->x > 0) {
                
                playerPos.x += _tileMap->getTileSize().width;
            } else {
                playerPos.x -= _tileMap->getTileSize().width;
            }
        } else {
            if (diff.y > 0) {
                playerPos.y += _tileMap->getTileSize().height;
            } else {
                playerPos.y -= _tileMap->getTileSize().height;
            }
        }
        
        // safety check on the bounds of the map
        if (playerPos.x <= (_tileMap->getMapSize().width * _tileMap->getTileSize().width) &&
            playerPos.y <= (_tileMap->getMapSize().height * _tileMap->getTileSize().height) &&
            playerPos.y >= 0 &&
            playerPos.x >= 0 )
        {
            this->setPlayerPosition(playerPos);
        }
    }
}

bool NormalState::onStateEnter() {
    std::cout << "NormalState::onStateEnter()\n";
    return true;
}

bool NormalState::onStateExit() {
    return true;
}

