#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


#include "cocos2d.h"
#include "CCEventListenerAcceleration.h"
#include "CCEventAcceleration.h"
#import <list>
// #include ""

// using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    int gameTime = 0;

    virtual bool init();
    
    // setup touchscreen
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    // virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    // virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    // virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);


    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void row1Shoot(float dt);
    void row2Shoot(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    // set up Accelerometer
	// virtual void didAccelerate(CCAcceleration* pAccelerationValue);
	void OnAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);

	bool onContactBegan(cocos2d::PhysicsContact &contact);

private:
	cocos2d::Label *label;
	cocos2d::Sprite *spaceship;	
	cocos2d::Sprite *monster1;
	cocos2d::Sprite *monster2;
	cocos2d::Sprite *monster3;
	cocos2d::Sprite *monster4;
	cocos2d::Sprite *monster5;


	int _nextShipLaser;

	float _shipPointsPerSecY;

	cocos2d::PhysicsWorld *sceneWorld;
	void SetPhysicsWorld(cocos2d::PhysicsWorld *world) { sceneWorld = world; };
};


#endif // __HELLOWORLD_SCENE_H__
