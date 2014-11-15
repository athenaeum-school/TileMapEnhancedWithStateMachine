//
//  ObjectManager.h
//  TileGame
//
//  Created by athenaeum on 2014/11/15.
//
//

#ifndef __TileGame__ObjectManager__
#define __TileGame__ObjectManager__

#include "StateMachine.h"
#include <vector>
#include <cocos2d.h>

class ObjectManager : public cocos2d::CCLayer
{
public:
    
    static ObjectManager* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new ObjectManager();
            return s_pInstance;
        }
        
        return s_pInstance;
    }
    
    bool init();
    void update();
    void clean();
    
    StateMachine* getStateMachine() { return m_pStateMachine; }
    
    CC_SYNTHESIZE(int, m_playerLives, PlayerLives);
    CC_SYNTHESIZE(int, m_nextLevel, NextLevel);
    CC_SYNTHESIZE(bool, m_bLevelComplete, LevelComplete);
    
    void setCurrentLevel(int currentLevel);
    int getCurrentLevel() { return m_currentLevel;}
    
    std::vector<std::string> getLevelFiles() { return m_levelFiles; }
    
private:
    
    StateMachine* m_pStateMachine;
    static ObjectManager* s_pInstance;
    
    //CCSprite* m_obj;
    //std::vector<CCSprite*> m_refSprite;
    
    int m_currentLevel;

    std::vector<std::string> m_levelFiles;
    
    ObjectManager();
    ~ObjectManager();
    
    ObjectManager(const ObjectManager&);
	ObjectManager& operator=(const ObjectManager&);
    
    ObjectManager(const cocos2d::CCSprite*);
};

typedef ObjectManager Game;

#endif /* defined(__TileGame__ObjectManager__) */