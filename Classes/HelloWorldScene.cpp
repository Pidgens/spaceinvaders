#include "HelloWorldScene.h"

USING_NS_CC;

// collision layer
enum class PhysicsCategory {
    None = 0,
    Monster = (1 << 0),    // 1
    Projectile = (1 << 1), // 2
    All = PhysicsCategory::Monster | PhysicsCategory::Projectile // 3
};

enum class PhysicsCategorySS {
    None = 0,
    Spaceship = (1 << 2),    // 1
    Projectile = (1 << 3), // 2
    All = PhysicsCategorySS::Spaceship | PhysicsCategorySS::Projectile // 3
};


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0,0));
    // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    layer->SetPhysicsWorld( scene->getPhysicsWorld() );

    // add layer as a child to scene
    scene->addChild(layer);


    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
    label = Label::createWithSystemFont("SCORE: ", "fonts/Marker Felt.ttf", 12);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label);


    #define PERROW 11

    // create monsters
    for (int i=0; i<PERROW; ++i) 
    {
        if (i < 11) {
            monster1 = Sprite::create("invaderCframe1.png");
            monster1->setPosition(Vec2(visibleSize.width/10 + origin.x + i*15, visibleSize.height/1.2));
        }
        this->addChild(monster1);

        auto monsterSize = monster1->getContentSize();
        auto physicsBody = PhysicsBody::createBox(Size(monsterSize.width, monsterSize.height),
            PhysicsMaterial(0.1f, 1.0f, 0.0f));
        physicsBody->setDynamic(true);
        physicsBody->setCategoryBitmask((int)PhysicsCategory::Monster);
        physicsBody->setCollisionBitmask((int)PhysicsCategory::None);
        physicsBody->setContactTestBitmask((int)PhysicsCategory::Projectile);
        monster1->setPhysicsBody(physicsBody);

        _m1List.insert(i, monster1);
    }
    for (int i=0; i<PERROW; ++i)
    {

        float height = 1.3;
        monster2 = Sprite::create("invaderAframe1.png");
        monster2->setPosition(Vec2(visibleSize.width/10 + origin.x + i*15, visibleSize.height/height));
        
        this->addChild(monster2);

        auto monsterSize2 = monster2->getContentSize();
        auto physicsBody2 = PhysicsBody::createBox(Size(monsterSize2.width, monsterSize2.height),
            PhysicsMaterial(0.1f, 1.0f, 0.0f));
        physicsBody2->setDynamic(true);
        physicsBody2->setCategoryBitmask((int)PhysicsCategory::Monster);
        physicsBody2->setCollisionBitmask((int)PhysicsCategory::None);
        physicsBody2->setContactTestBitmask((int)PhysicsCategory::Projectile);
        monster2->setPhysicsBody(physicsBody2);

        _m2List.insert(i, monster2);
    }

    for (int i=0; i<PERROW; ++i)
    {
        
        float height = 1.4;
        monster3 = Sprite::create("invaderAframe1.png");
        monster3->setPosition(Vec2(visibleSize.width/10 + origin.x + i*15, visibleSize.height/height));
        
        this->addChild(monster3);

        auto monsterSize = monster3->getContentSize();
        auto physicsBody = PhysicsBody::createBox(Size(monsterSize.width, monsterSize.height),
            PhysicsMaterial(0.1f, 1.0f, 0.0f));
        physicsBody->setDynamic(true);
        physicsBody->setCategoryBitmask((int)PhysicsCategory::Monster);
        physicsBody->setCollisionBitmask((int)PhysicsCategory::None);
        physicsBody->setContactTestBitmask((int)PhysicsCategory::Projectile);
        monster3->setPhysicsBody(physicsBody);

        _m3List.insert(i, monster3);
    }

    for (int i=0; i<PERROW; ++i)
    {
        
        float height = 1.5;
        monster4 = Sprite::create("invaderBframe1.png");
        monster4->setPosition(Vec2(visibleSize.width/10 + origin.x + i*15, visibleSize.height/height));
        
        this->addChild(monster4);

        auto monsterSize = monster4->getContentSize();
        auto physicsBody = PhysicsBody::createBox(Size(monsterSize.width, monsterSize.height),
            PhysicsMaterial(0.1f, 1.0f, 0.0f));
        physicsBody->setDynamic(true);
        physicsBody->setCategoryBitmask((int)PhysicsCategory::Monster);
        physicsBody->setCollisionBitmask((int)PhysicsCategory::None);
        physicsBody->setContactTestBitmask((int)PhysicsCategory::Projectile);
        monster4->setPhysicsBody(physicsBody);

        _m4List.insert(i, monster4);
    }
    // cocos2d::Vector<cocos2d::Sprite*> _m5List(PERROW);
    for (int i=0; i<PERROW; ++i)
    {
        
        float height = 1.6;
        monster5 = Sprite::create("invaderBframe1.png");
        monster5->setPosition(Vec2(visibleSize.width/10 + origin.x + i*15, visibleSize.height/height));
        
        this->addChild(monster5);

        auto monsterSize = monster5->getContentSize();
        auto physicsBody = PhysicsBody::createBox(Size(monsterSize.width, monsterSize.height),
            PhysicsMaterial(0.1f, 1.0f, 0.0f));
        physicsBody->setDynamic(true);
        physicsBody->setCategoryBitmask((int)PhysicsCategory::Monster);
        physicsBody->setCollisionBitmask((int)PhysicsCategory::None);
        physicsBody->setContactTestBitmask((int)PhysicsCategory::Projectile);
        monster5->setPhysicsBody(physicsBody);

        _m5List.insert(i, monster5);
    }


    // create player_shields
    auto shield1 = Sprite::create("player_shield.png");
    shield1->setPosition(Vec2(visibleSize.width/2.8 + origin.x, visibleSize.height/5 + origin.y));
    this->addChild(shield1);
    auto shield2 = Sprite::create("player_shield.png");
    shield2->setPosition(Vec2(visibleSize.width/7 + origin.x, visibleSize.height/5 + origin.y));
    this->addChild(shield2);
    auto shield3 = Sprite::create("player_shield.png");
    shield3->setPosition(Vec2(visibleSize.width/1.7 + origin.x, visibleSize.height/5 + origin.y));
    this->addChild(shield3);
    auto shield4 = Sprite::create("player_shield.png");
    shield4->setPosition(Vec2(visibleSize.width/1.2 + origin.x, visibleSize.height/5 + origin.y));
    this->addChild(shield4);


    // add "HelloWorld" splash screen"
    spaceship = Sprite::create("spaceship.png");
    spaceship->setTag(100);
    // position the sprite on the center of the screen
    spaceship->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/8 + origin.y));

    auto ssBody = PhysicsBody::createBox( spaceship->getContentSize(), PhysicsMaterial(0,1,0));
    ssBody->setGravityEnable(false);
    ssBody->setCollisionBitmask((int) PhysicsCategorySS::None );
    ssBody->setContactTestBitmask( (int) PhysicsCategorySS::Projectile );
    ssBody->setCategoryBitmask( (int) PhysicsCategorySS:: Spaceship );
    spaceship->setPhysicsBody(ssBody);
    this->addChild(spaceship, 1);




    // touch screen listener
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);
   _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

   // Turn on accelerometer
    Device::setAccelerometerEnabled(true);
    auto acc_listener = EventListenerAcceleration::create(CC_CALLBACK_2(HelloWorld::OnAcceleration, this));
    _eventDispatcher->addEventListenerWithSceneGraphPriority(acc_listener, this);


    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);    
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point( visibleSize.width/2 + origin.x, visibleSize.height / 2 + origin.y));
    edgeBody->setCollisionBitmask(2);
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);

    // collision
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);


    // for movement schedule
    this->schedule(schedule_selector(HelloWorld::row5Shoot), 1); 
    this->schedule(schedule_selector(HelloWorld::row4Shoot), 1); 
    this->schedule(schedule_selector(HelloWorld::row3Shoot), 1); 
    this->schedule(schedule_selector(HelloWorld::row2Shoot), 1); 
    this->schedule(schedule_selector(HelloWorld::row1Shoot), 1); 

    // for shooting
    this->schedule(schedule_selector(HelloWorld::row1Fire), 2);


    return true;
}

// for collision
bool HelloWorld::onContactBegan(cocos2d::PhysicsContact &contact) {
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();

    if ( ( nodeA->getTag() == spaceship->getTag() ) || (nodeB->getTag() == spaceship->getTag() ) ) 
    {
        CCLOG("GAME IS OVERRRR");
        Director::getInstance()->end();
        Director::getInstance()->purgeCachedData();
        return true;
    }


    nodeA->removeFromParentAndCleanup(true);
    nodeB->removeFromParentAndCleanup(true);


    CCLOG("COLLISION OCCURED");
    return true;
}   

void HelloWorld::row1Fire(float dt)
{
    randVal = rand()%11;
    int i = 1;
    for ( auto m : _m1List ) 
    {
        if (randVal == i) 
        {
            auto projectile = Sprite::create("enemy_missle.png");
            projectile->setPosition(m->getPosition());
            this->addChild(projectile);

            auto realDest = Vec2(m->getPosition().x, -500);

            auto projectileSize = projectile->getContentSize();
            auto physicsBody = PhysicsBody::createCircle(projectileSize.width/2 );
            physicsBody->setDynamic(true); 
            physicsBody->setCategoryBitmask((int)PhysicsCategorySS::Projectile);
            physicsBody->setCollisionBitmask((int)PhysicsCategorySS::None);
            physicsBody->setContactTestBitmask((int)PhysicsCategorySS::Spaceship);
            projectile->setPhysicsBody(physicsBody);

            auto actionMove = MoveTo::create(2.0f, realDest);
            auto actionRemove = RemoveSelf::create();
            projectile->runAction(Sequence::create(actionMove,actionRemove, nullptr));   
        }
        ++i;
    }
    randVal = rand()%11;
    i = 1;
    for ( auto m : _m2List ) 
    {
        if (randVal == i) 
        {
            auto projectile = Sprite::create("enemy_missle.png");
            projectile->setPosition(m->getPosition());
            this->addChild(projectile);

            auto realDest = Vec2(m->getPosition().x, -500);

            auto projectileSize = projectile->getContentSize();
            auto physicsBody = PhysicsBody::createCircle(projectileSize.width/2 );
            physicsBody->setDynamic(true); 
            physicsBody->setCategoryBitmask((int)PhysicsCategorySS::Projectile);
            physicsBody->setCollisionBitmask((int)PhysicsCategorySS::None);
            physicsBody->setContactTestBitmask((int)PhysicsCategorySS::Spaceship);
            projectile->setPhysicsBody(physicsBody);

            auto actionMove = MoveTo::create(2.0f, realDest);
            auto actionRemove = RemoveSelf::create();
            projectile->runAction(Sequence::create(actionMove,actionRemove, nullptr));   
        }
        ++i;
    }
    randVal = rand()%11;
    i = 1;
    for ( auto m : _m3List ) 
    {
        if (randVal == i) 
        {
            auto projectile = Sprite::create("enemy_missle.png");
            projectile->setPosition(m->getPosition());
            this->addChild(projectile);

            auto realDest = Vec2(m->getPosition().x, -500);

            auto projectileSize = projectile->getContentSize();
            auto physicsBody = PhysicsBody::createCircle(projectileSize.width/2 );
            physicsBody->setDynamic(true); 
            physicsBody->setCategoryBitmask((int)PhysicsCategorySS::Projectile);
            physicsBody->setCollisionBitmask((int)PhysicsCategorySS::None);
            physicsBody->setContactTestBitmask((int)PhysicsCategorySS::Spaceship);
            projectile->setPhysicsBody(physicsBody);

            auto actionMove = MoveTo::create(2.0f, realDest);
            auto actionRemove = RemoveSelf::create();
            projectile->runAction(Sequence::create(actionMove,actionRemove, nullptr));   
        }
        ++i;
    }
    randVal = rand()%11;
    i = 1;
    for ( auto m : _m4List ) 
    {
        if (randVal == i) 
        {
            auto projectile = Sprite::create("enemy_missle.png");
            projectile->setPosition(m->getPosition());
            this->addChild(projectile);

            auto realDest = Vec2(m->getPosition().x, -500);

            auto projectileSize = projectile->getContentSize();
            auto physicsBody = PhysicsBody::createCircle(projectileSize.width/2 );
            physicsBody->setDynamic(true); 
            physicsBody->setCategoryBitmask((int)PhysicsCategorySS::Projectile);
            physicsBody->setCollisionBitmask((int)PhysicsCategorySS::None);
            physicsBody->setContactTestBitmask((int)PhysicsCategorySS::Spaceship);
            projectile->setPhysicsBody(physicsBody);

            auto actionMove = MoveTo::create(2.0f, realDest);
            auto actionRemove = RemoveSelf::create();
            projectile->runAction(Sequence::create(actionMove,actionRemove, nullptr));   
        }
        ++i;
    }
    randVal = rand()%11;
    i = 1;
    for ( auto m : _m5List ) 
    {
        if (randVal == i) 
        {
            auto projectile = Sprite::create("enemy_missle.png");
            projectile->setPosition(m->getPosition());
            this->addChild(projectile);

            auto realDest = Vec2(m->getPosition().x, -500);

            auto projectileSize = projectile->getContentSize();
            auto physicsBody = PhysicsBody::createCircle(projectileSize.width/2 );
            physicsBody->setDynamic(true); 
            physicsBody->setCategoryBitmask((int)PhysicsCategorySS::Projectile);
            physicsBody->setCollisionBitmask((int)PhysicsCategorySS::None);
            physicsBody->setContactTestBitmask((int)PhysicsCategorySS::Spaceship);
            projectile->setPhysicsBody(physicsBody);

            auto actionMove = MoveTo::create(2.0f, realDest);
            auto actionRemove = RemoveSelf::create();
            projectile->runAction(Sequence::create(actionMove,actionRemove, nullptr));   
        }
        ++i;
    }


}

void HelloWorld::row1Shoot(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    int maxEdgeX = visibleSize.width + origin.x;
    int minEdgeX = origin.x;
    if (f1 == 222) {
        direction1 = 1;
        f1 = 999;
    }
    for (auto &m : _m1List)
    {
        if (altFrames1 % 2 == 1)
        {
            m->setTexture("invaderCframe2.png");
        } 
        else 
        {
            m->setTexture("invaderCframe1.png");    
        }
        auto moveTo = MoveTo::create(1, Vec2(m->getPosition().x + 10 * direction1 , m->getPosition().y));
        m->runAction(moveTo);
        int nextPosition = m->getPosition().x + (10 + m->getContentSize().width) * direction1;
        if ( nextPosition > maxEdgeX ) {
            direction1 = -1;
            for ( auto &m : _m1List )
            {
                auto moveDown = MoveTo::create(1, Vec2(m->getPosition().x , m->getPosition().y - 10 ));
                m->runAction(moveDown);   
            }
            _m1List.reverse();
            break;
        } 
        if ( nextPosition < minEdgeX ) {
            direction1 = 1;
            for ( auto &m : _m1List )
            {
                auto moveDown = MoveTo::create(1, Vec2(m->getPosition().x , m->getPosition().y - 5 ));
                m->runAction(moveDown);   
            }
            _m1List.reverse();
            break;
        }
    }
    ++altFrames1;
}

void HelloWorld::row2Shoot(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    int maxEdgeX = visibleSize.width + origin.x;
    int minEdgeX = origin.x;
    if (f2 == 222) {
        direction2 = 1;
        f2 = 999;
    }
    for (auto &m : _m2List)
    {
        if (altFrames2 % 2 == 1)
        {
            m->setTexture("invaderAframe2.png");
        } 
        else 
        {
            m->setTexture("invaderAframe1.png");    
        }
        auto moveTo = MoveTo::create(1, Vec2(m->getPosition().x + 10 * direction2 , m->getPosition().y));
        m->runAction(moveTo);
        int nextPosition = m->getPosition().x + (10 + m->getContentSize().width) * direction2;
        if ( nextPosition > maxEdgeX ) {
            direction2 = -1;
            for ( auto &m : _m2List )
            {
                auto moveDown = MoveTo::create(1, Vec2(m->getPosition().x , m->getPosition().y - 5 ));
                m->runAction(moveDown);   
            }
            _m2List.reverse();
            break;
        } 
        if ( nextPosition < minEdgeX ) {
            direction2 = 1;
            for ( auto &m : _m2List )
            {
                auto moveDown = MoveTo::create(1, Vec2(m->getPosition().x , m->getPosition().y - 5 ));
                m->runAction(moveDown);   
            }
            _m2List.reverse();
            break;
        }
    }
    ++altFrames2;
}
void HelloWorld::row3Shoot(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    int maxEdgeX = visibleSize.width + origin.x;
    int minEdgeX = origin.x;
    if (f3 == 222) {
        direction3 = 1;
        f3 = 999;
    }
    for (auto &m : _m3List)
    {
        if (altFrames3 % 2 == 1)
        {
            m->setTexture("invaderAframe2.png");
        } 
        else 
        {
            m->setTexture("invaderAframe1.png");    
        }
        auto moveTo = MoveTo::create(1, Vec2(m->getPosition().x + 10 * direction3 , m->getPosition().y));
        m->runAction(moveTo);
        int nextPosition = m->getPosition().x + (10 + m->getContentSize().width) * direction3;
        if ( nextPosition > maxEdgeX ) {
            direction3 = -1;
            for ( auto &m : _m3List )
            {
                auto moveDown = MoveTo::create(1, Vec2(m->getPosition().x , m->getPosition().y - 5 ));
                m->runAction(moveDown);   
            }
            _m3List.reverse();
            break;
        } 
        if ( nextPosition < minEdgeX ) {
            direction3 = 1;
            for ( auto &m : _m3List )
            {
                auto moveDown = MoveTo::create(1, Vec2(m->getPosition().x , m->getPosition().y - 5 ));
                m->runAction(moveDown);   
            }
            _m3List.reverse();
            break;
        }
    }
    ++altFrames3;
}


void HelloWorld::row4Shoot(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    int maxEdgeX = visibleSize.width + origin.x;
    int minEdgeX = origin.x;
    if (f4 == 222) {
        direction4 = 1;
        f4 = 999;
    }
    for (auto &m : _m4List)
    {
        auto moveTo = MoveTo::create(1, Vec2(m->getPosition().x + 10 * direction4 , m->getPosition().y));
        m->runAction(moveTo);
        if (altFrames4 % 2 == 1)
        {
            m->setTexture("invaderBframe2.png");
        } 
        else 
        {
            m->setTexture("invaderBframe1.png");    
        }
        int nextPosition = m->getPosition().x + (10 + m->getContentSize().width) * direction4;
        if ( nextPosition > maxEdgeX ) {
            direction4 = -1;
            for ( auto &m : _m4List )
            {
                auto moveDown = MoveTo::create(1, Vec2(m->getPosition().x , m->getPosition().y - 5 ));
                m->runAction(moveDown);   
            }

            _m4List.reverse();
            break;
        } 
        if ( nextPosition < minEdgeX ) {
            direction4 = 1;
            for ( auto &m : _m4List )
            {
                auto moveDown = MoveTo::create(1, Vec2(m->getPosition().x , m->getPosition().y - 5 ));
                m->runAction(moveDown);   
            }
            _m4List.reverse();
            break;
        }
    }
    ++altFrames4;
}


void HelloWorld::row5Shoot(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    int maxEdgeX = visibleSize.width + origin.x;
    int minEdgeX = origin.x;
    if (f5 == 222) {
        direction5 = 1;
        f5 = 999;
    }
    for (auto &m5 : _m5List)
    {
        auto moveTo = MoveTo::create(1, Vec2(m5->getPosition().x + 10 * direction5 , m5->getPosition().y));
        m5->runAction(moveTo);
        if (altFrames5 % 2 == 1)
        {
            m5->setTexture("invaderBframe2.png");
        } 
        else 
        {
            m5->setTexture("invaderBframe1.png");    
        }
        int nextPosition = m5->getPosition().x + (10 + m5->getContentSize().width) * direction5;
        if ( nextPosition > maxEdgeX ) {
            direction5 = -1;
            for ( auto &m : _m5List )
            {
                auto moveDown = MoveTo::create(1, Vec2(m->getPosition().x , m->getPosition().y - 5 ));
                m->runAction(moveDown);   
            }
            _m5List.reverse();
            break;
        } 
        if ( nextPosition < minEdgeX ) {
            direction5 = 1;
            for ( auto &m : _m5List )
            {
                auto moveDown = MoveTo::create(1, Vec2(m->getPosition().x , m->getPosition().y - 5 ));
                m->runAction(moveDown);
            }
            _m5List.reverse();
            break;
        }
    }
    ++altFrames5;
}

void HelloWorld::OnAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event) 
{
    int nextPosition = spaceship->getPosition().x + acc->x * 4;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    int maxEdgeX = visibleSize.width + origin.x;
    int minEdgeX = origin.x;
    if ( (nextPosition < maxEdgeX) & (nextPosition > minEdgeX) )
    { 
        spaceship->setPosition(spaceship->getPosition().x + acc->x * 4, spaceship->getPosition().y);
    }
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event) 
{

    // 4
    auto projectile = Sprite::create("player_missle.png");
    projectile->setPosition(spaceship->getPosition());
    this->addChild(projectile);

    // 6
    auto realDest = Vec2(spaceship->getPosition().x, 1000);

    // for collision
    auto projectileSize = projectile->getContentSize();
    auto physicsBody = PhysicsBody::createCircle(projectileSize.width/2 );
    physicsBody->setDynamic(true); 
    physicsBody->setCategoryBitmask((int)PhysicsCategory::Projectile);
    physicsBody->setCollisionBitmask((int)PhysicsCategory::None);
    physicsBody->setContactTestBitmask((int)PhysicsCategory::Monster);
    projectile->setPhysicsBody(physicsBody);


    // remove the projectile
    auto actionMove = MoveTo::create(2.0f, realDest);
    auto actionRemove = RemoveSelf::create();
    projectile->runAction(Sequence::create(actionMove,actionRemove, nullptr));


    cocos2d::log("touch began");
    return true;
}
