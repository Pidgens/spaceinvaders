#include "HelloWorldScene.h"

USING_NS_CC;

// collision layer
enum class PhysicsCategory {
    None = 0,
    Monster = (1 << 0),    // 1
    Projectile = (1 << 1), // 2
    All = PhysicsCategory::Monster | PhysicsCategory::Projectile // 3
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

    // game logic for monsters
    this->schedule(schedule_selector(HelloWorld::row1Shoot), 1.5);

    // create monsters
    for (int i=0; i<11; ++i) 
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
    }
    for (int i=0; i<11; ++i)
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
    }

    for (int i=0; i<11; ++i)
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
    }

    for (int i=0; i<11; ++i)
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
    }

    for (int i=0; i<11; ++i)
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

    // position the sprite on the center of the screen
    spaceship->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/8 + origin.y));

    auto ssBody = PhysicsBody::createBox( spaceship->getContentSize(), PhysicsMaterial(0,1,0));
    ssBody->setGravityEnable(false);
    // ssBody->setCategoryBitmask(0x02);
    ssBody->setCollisionBitmask(1);
    spaceship->setPhysicsBody(ssBody);
    // spaceship->getContactTestBitmask(true);

    // add the sprite as a child to this layer
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
    
    // edgeBody->setContactTestBitmask(true);
    
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point( visibleSize.width/2 + origin.x, visibleSize.height / 2 + origin.y));
    edgeBody->setCollisionBitmask(2);
    edgeNode->setPhysicsBody(edgeBody);
    // edgeBody->setCategoryBitmask(0x01);

    // edgeNode->setCollisionBitmask(2);
    // edgeNode->setContactTestBitmask(true);
    this->addChild(edgeNode);

    // collision
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    return true;
}

// for collision
bool HelloWorld::onContactBegan(cocos2d::PhysicsContact &contact) {
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();

    nodeA->removeFromParent();
    nodeB->removeFromParent();
    return true;
}   

void HelloWorld::OnAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event) 
{
    spaceship->setPosition(spaceship->getPosition().x + acc->x * 4, spaceship->getPosition().y);
}


// void HelloWorld::setInvisible(CCNode * node) {
//     node->setVisible(false);
// }

void HelloWorld::row1Shoot(float dt)
{
    
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


    // 7
    auto actionMove = MoveTo::create(2.0f, realDest);
    auto actionRemove = RemoveSelf::create();
    projectile->runAction(Sequence::create(actionMove,actionRemove, nullptr));


    cocos2d::log("touch began");
    return true;
}
