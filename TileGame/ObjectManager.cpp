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

ObjectManager* ObjectManager::s_pInstance = 0;

ObjectManager::ObjectManager():
m_pStateMachine(0),
m_playerLives(3),
m_bLevelComplete(false)
{
    m_pStateMachine = new StateMachine();
    m_currentLevel = 1;
}

ObjectManager::~ObjectManager()
{
}

bool ObjectManager::init()
{
    // ここで画像や音声のロード、その他初期化を行えますが、
    // TODO: 慣れたらGOのファクトリーでの初期化を実装すること
    m_pStateMachine->changeState(new NormalState());
    return true;
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

void ObjectManager::clean()
{
    cout << "cleaning ObjectManager\n";
    //m_pStateMachine->clean();
    m_pStateMachine = 0;
    delete m_pStateMachine;

}
