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
        // ここで各ゲームオブジェクト＝NPCのアップデートを行います。
        // 人工知能的な動作については
        // Game::Instance()->getStateMachine()->changeState(new AlarmState());
        // をお使いください。
        (*it)->stateUpdate();
        //iterator のitは、ベクターの要素である、gameObjectsポインタ変数へのポインターなので、
        //ポインタのデータを「*」で取り出しましょう。
    }
}

// 入力時にだけ処理させたい場合（＝毎フレーム更新は避けたい場合）。
// 基本的にはstateUpdate()関数を使うようにしましょう。
void NormalState::onInputEvent(CCPoint* diff) {

    _tileWidth = Game::Instance()->getTileMap()->getTileSize().width;
    _tileHeight = Game::Instance()->getTileMap()->getTileSize().height;
    _mapWidth = Game::Instance()->getTileMap()->getMapSize().width;
    _mapHeight = Game::Instance()->getTileMap()->getMapSize().height;
    
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

