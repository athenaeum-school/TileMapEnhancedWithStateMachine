//
//  Player.cpp
//  TileGame
//
//  Created by athenaeum on 2014/11/18.
//
//

#include "Player.h"
#include <iostream>

void Player::setPlayerPosition(cocos2d::CCPoint* diff, cocos2d::CCPoint playerPos,
                       float tileWidth, float tileHeight, float mapWidth, float mapHeight)
{
    if(diff){
        if ( abs(diff->x) > abs(diff->y) ) {
            if (diff->x > 0) {
                
                playerPos.x += tileWidth;
            } else {
                playerPos.x -= tileWidth;
            }
        } else {
            if (diff->y > 0) {
                playerPos.y += tileHeight;
            } else {
                playerPos.y -= tileHeight;
            }
        }
        
        // safety check on the bounds of the map
        if (playerPos.x <= (mapWidth * tileWidth) &&
            playerPos.y <= (mapHeight * tileHeight) &&
            playerPos.y >= 0 &&
            playerPos.x >= 0 )
        {
            this->setPosition(playerPos);
        }
    }
}

//
void Player::stateUpdate(){
    //基本的にPlayerの動作・処理はこの中で定義・宣言してください。
    //setPlayerPosition(cocos2d::CCPoint* diff, cocos2d::CCPoint playerPos,float tileWidth, float tileHeight, float mapWidth, float mapHeight)
    std::cout << "Update for the player.";
}