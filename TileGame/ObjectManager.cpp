//
//  ObjectManager.cpp
//  TileGame
//
//  Created by athenaeum on 2014/11/15.
//
//

#include "ObjectManager.h"
#include "NormalState.h"
#include "AlarmState.h"

using namespace std;

ObjectManager* ObjectManager::s_pInstance = 0; //インスタンスを格納する変数です。

ObjectManager::ObjectManager():
m_pStateMachine(0), // m_pStateMachine変数を０に初期化します。
m_playerLives(3), // m_plyaerLives変数を3に初期化します。
m_bLevelComplete(false) // m_bLevelComplete変数をfalseに初期化します。
{
    m_pStateMachine = new StateMachine();
    m_currentLevel = 1;
}

ObjectManager::~ObjectManager()
{
    //delete m_pStateMachine;
    clean();
}

bool ObjectManager::init()
{
    // ここで画像や音声のロード、その他初期化を行えますが、
    // TODO: 慣れたらGOのファクトリーでの初期化を実装すること
    m_pStateMachine->changeState(new NormalState());
    return true;
}

void ObjectManager::setGameObjectPosition(const cocos2d::CCPoint &pts)
{
    for (std::vector<GameObject*>::iterator it = m_gameObjects.begin() ; it != m_gameObjects.end(); ++it)
        (*it)->setPosition(pts);
}

void ObjectManager::setTileMap(cocos2d::CCTMXTiledMap* tileMap)
{
    this->_tileMap = tileMap;
}

cocos2d::CCTMXTiledMap* ObjectManager::getTileMap()
{
    return this->_tileMap;
}

void ObjectManager::setGameObjectStrategy()
{
    //for (std::vector<GameObject*>::iterator it = m_gameObjects.begin() ; it != m_gameObjects.end(); ++it)
    //    (*it)->setStrategy();
}

void ObjectManager::addGameObject(GameObject* sprite)
{
    m_gameObjects.push_back(sprite);
}

void ObjectManager::addGameObjectMap(const std::string id, GameObject* sprite)
{
    // Map（C#でのDictionaryみたいなものです）を使う必要がある場合は、参考にしてください。
    m_gameObjectMap.insert(pair<std::string, GameObject*>(id, sprite));
}

std::vector<GameObject*> ObjectManager::getGameObjects()
{
    return m_gameObjects;
}

GameObject* ObjectManager::findGameObject(std::string id)
{
    // タグでの検索は負荷があるので、基本使わないようにしましょう。実験目的での使用ならいいです。
    std::map<std::string, GameObject*>::iterator it = m_gameObjectMap.find(id);
    if(it != m_gameObjectMap.end()){
        return it->second;
    } else {
        return 0;
    }
}

void ObjectManager::setCurrentLevel(int currentLevel)
{
    m_currentLevel = currentLevel;
    m_pStateMachine->changeState(new NormalState());
    m_bLevelComplete = false;
}

void ObjectManager::update()
{
    m_pStateMachine->update();
}

void ObjectManager::handleEvents(CCPoint* pts)
{
    m_pStateMachine->onEvent(pts);
}

void ObjectManager::clean()
{
    cout << "cleaning ObjectManager\n";
    m_pStateMachine->clean();
    m_pStateMachine = 0;
    delete m_pStateMachine;

}
