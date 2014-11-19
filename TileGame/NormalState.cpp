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
    _tileWidth = Game::Instance()->getTileMap()->getTileSize().width;
    _tileHeight = Game::Instance()->getTileMap()->getTileSize().height;
    _mapWidth = Game::Instance()->getTileMap()->getMapSize().width;
    _mapHeight = Game::Instance()->getTileMap()->getMapSize().height;
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
    
    Player* player = dynamic_cast<Player*>( Game::Instance()->findGameObject("player"));
    CCPoint playerPos = player->getPosition();
    
    player->setPlayerPosition(diff, playerPos, _tileWidth,_tileHeight, _mapWidth, _mapHeight);
    
    /*
    if(diff){
        if ( abs(diff->x) > abs(diff->y) ) {
            if (diff->x > 0) {
                
                playerPos.x += _tileWidth;
            } else {
                playerPos.x -= _tileWidth;
            }
        } else {
            if (diff->y > 0) {
                playerPos.y += _tileHeight;
            } else {
                playerPos.y -= _tileHeight;
            }
        }
        
        // safety check on the bounds of the map
        if (playerPos.x <= (_mapWidth * _tileWidth) &&
            playerPos.y <= (_mapHeight * _tileHeight) &&
            playerPos.y >= 0 &&
            playerPos.x >= 0 )
        {
            player->setPosition(playerPos);
        }
    }
     */
}

bool NormalState::onStateEnter() {
    std::cout << "NormalState::onStateEnter()\n";
    return true;
}

bool NormalState::onStateExit() {
    return true;
}

