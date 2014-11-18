#include "GameLayer.h"
#include "SimpleAudioEngine.h"
#include "ObjectManager.h"

using namespace cocos2d;

GameLayer* GameLayer::s_pInstance = 0;

CCScene* GameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();
    //GameManager * game = Game::Instance()->create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    HudLayer *hud = new HudLayer();
    hud->init();
    scene->addChild(hud);
    layer->_hud = hud;
    
    ObjectManager *gm = ObjectManager::Instance();
    scene->addChild(gm);
    layer->_gm = gm;
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    GameLayer::s_pInstance = this;
    
    Game::Instance()->getStateMachine()->pushState(new NormalState());
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("pickup.caf");
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("hit.caf");
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("move.caf");
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("TileMap.caf");
    
    _tileMap = new CCTMXTiledMap();
    _tileMap->initWithTMXFile("TileMap.tmx");
    _background = _tileMap->layerNamed("Background");
    _foreground = _tileMap->layerNamed("Foreground");
    
    _meta = _tileMap->layerNamed("Meta");
    _meta->setVisible(false);
    
    this->addChild(_tileMap);
    
    CCTMXObjectGroup *objectGroup = _tileMap->objectGroupNamed("Objects");
    
    if(objectGroup == NULL){
        CCLog("tile map has no objects object layer");
        return false;
    }
    
    CCDictionary *spawnPoint = objectGroup->objectNamed("SpawnPoint");
    
    int x = ((CCString)*spawnPoint->valueForKey("x")).intValue();
    int y = ((CCString)*spawnPoint->valueForKey("y")).intValue();
    
    enum Status normalStatus = kNormal;
    enum Status alarmStatus = kAlarm;
    
    Player* _player = new Player();
    _player->initWithFile("Player.png");
    _player->setPosition(ccp(x,y));
    _player->setTag(normalStatus);
    
    this->addChild(_player);
    
    Enemy* _enemy = new Enemy();
    this->addChild(_enemy);
    
    Game::Instance()->addGameObject(_player);
    Game::Instance()->addGameObject(_enemy);
    
    /*
    _normalState = new NormalState();
    _normalState->initWithFile("Player.png");
    _normalState->setPosition(ccp(x,y));
    _normalState->setTag(normalStatus);
    
    this->addChild(_normalState);
    this->setViewPointCenter(_normalState->getPosition());
    
    _alarmState = new AlarmState();
    _alarmState->initWithFile("Player.png");
    _alarmState->setPosition(ccp(x,y));
    //_alarmState->cocos2d::CCRGBAProtocol::setColor(<#const ccColor3B &color#>);
    _alarmState->setTag(alarmStatus);
    
    
    this->addChild(_normalState);
    */
    
    this->setViewPointCenter(_player->getPosition());
    
    this->setTouchEnabled(true);
    
    //create main loop
    this->schedule(schedule_selector(GameLayer::update));
    
    return true;
}

void GameLayer::setViewPointCenter(CCPoint position)
{
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    int x = MAX(position.x, winSize.width/2);
    int y = MAX(position.y, winSize.height/2);
    x = MIN(x, (_tileMap->getMapSize().width * this->_tileMap->getTileSize().width) - winSize.width / 2);
    y = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height) - winSize.height/2);
    CCPoint actualPosition = ccp(x, y);
    
    CCPoint centerOfView = ccp(winSize.width/2, winSize.height/2);
    CCPoint viewPoint = ccpSub(centerOfView, actualPosition);
    this->setPosition(viewPoint);
}

#pragma mark - handle touches

void GameLayer::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool GameLayer::ccTouchBegan(CCTouch *touch, CCEvent *event)
{
    return true;
}

void GameLayer::setPlayerPosition(CCPoint position)
{
    CCPoint tileCoord = this->tileCoordForPosition(position);
    int tileGid = _meta->tileGIDAt(tileCoord);
    if (tileGid) {
        CCDictionary *properties = _tileMap->propertiesForGID(tileGid);
        if (properties) {
            CCString *collision = new CCString();
            *collision = *properties->valueForKey("Collidable");
            if (collision && (collision->compare("True") == 0)) {
                CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("hit.caf");
                return;
            }
            CCString *collectible = new CCString();
            *collectible = *properties->valueForKey("Collectable");
            if (collectible && (collectible->compare("True") == 0)) {
                _meta->removeTileAt(tileCoord);
                _foreground->removeTileAt(tileCoord);
                _numCollected++;
                _hud->numCollectedChanged(_numCollected);
                CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("pickup.caf");
            }
        }
    }
    _player->setPosition(position);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("move.caf");
}

void GameLayer::ccTouchEnded(CCTouch *touch, CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    touchLocation = this->convertToNodeSpace(touchLocation);
    
    CCPoint playerPos = _player->getPosition();
    CCPoint diff = ccpSub(touchLocation, playerPos);
    
    Game::Instance()->handleEvents(&diff);
    
    this->setViewPointCenter(_player->getPosition());
}

CCPoint GameLayer::tileCoordForPosition(CCPoint position)
{
    int x = position.x / _tileMap->getTileSize().width;
    int y = ((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) / _tileMap->getTileSize().height;
    return ccp(x, y);
}

void GameLayer::update (float dt) {
	
    Game::Instance()->getStateMachine()->update();
	
}
