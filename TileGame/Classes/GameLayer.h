#ifndef __GameLayer_SCENE_H__
#define __GameLayer_SCENE_H__

#include "cocos2d.h"
#include "HudLayer.h"
#include "ObjectManager.h"
#include "NormalState.h"
#include "AlarmState.h"
#include "Player.h"
#include "Enemy.h"

using namespace cocos2d;

class GameLayer : public cocos2d::CCLayer
{
private:
    
    CCTMXTiledMap *_tileMap;
    
    CCTMXLayer *_background;

    Player * _player;
    Enemy * _enemy;
    
    NormalState *_normalState;
    AlarmState *_alarmState;

    CCTMXLayer *_meta;
    
    CCTMXLayer *_foreground;
    
    HudLayer *_hud;
    
    ObjectManager* _gm;
    
    int _numCollected;
    
public:
    
    static GameLayer* s_pInstance;
    static GameLayer* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new GameLayer();
            return s_pInstance;
        }
        
        return s_pInstance;
    }
    
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    void setViewPointCenter(CCPoint position);
    
    void registerWithTouchDispatcher();
    
    void setPlayerPosition(CCPoint position);
    
    bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    
    void ccTouchEnded(CCTouch *touch, CCEvent *event);
    
    CCPoint tileCoordForPosition(CCPoint position);

    void update (float dt);
    
    enum Status {
        kNormal = 0,
        kAlarm,
        kEnegyDrink
    };
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameLayer);
};

#endif // __GameLayer_SCENE_H__