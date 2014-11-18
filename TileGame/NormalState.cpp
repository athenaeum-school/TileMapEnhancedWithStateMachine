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
        //float x = (*it)->getPositionX();
        //float y = (*it)->getPositionY();
    }
}

void NormalState::onInputEvent(CCPoint* diff) {
    
    GameObject* player = Game::Instance()->findGameObject("player");
    CCPoint playerPos = player->getPosition();
    
    if(diff){
        if ( abs(diff->x) > abs(diff->y) ) {
            if (diff->x > 0) {
                
                playerPos.x += Game::Instance()->getTileMap()->getTileSize().width;
            } else {
                playerPos.x -= Game::Instance()->getTileMap()->getTileSize().width;
            }
        } else {
            if (diff->y > 0) {
                playerPos.y += Game::Instance()->getTileMap()->getTileSize().height;
            } else {
                playerPos.y -= Game::Instance()->getTileMap()->getTileSize().height;
            }
        }
        
        // safety check on the bounds of the map
        if (playerPos.x <= (Game::Instance()->getTileMap()->getMapSize().width * Game::Instance()->getTileMap()->getTileSize().width) &&
            playerPos.y <= (Game::Instance()->getTileMap()->getMapSize().height * Game::Instance()->getTileMap()->getTileSize().height) &&
            playerPos.y >= 0 &&
            playerPos.x >= 0 )
        {
            player->setPosition(playerPos);
            //this->setPlayerPosition(playerPos);
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

