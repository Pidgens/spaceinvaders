#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


#include "cocos2d.h"
#include "CCEventListenerAcceleration.h"
#include "CCEventAcceleration.h"
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

    void addFirst(float dt);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void row5Move(float dt);
    void row4Move(float dt);
    void row3Move(float dt);
    void row2Move(float dt);
    void row1Move(float dt);

    void fireMissiles(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    // set up Accelerometer
	// virtual void didAccelerate(CCAcceleration* pAccelerationValue);
	void OnAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);

	bool onContactBegan(cocos2d::PhysicsContact &contact);

	void checkForDown(float dt);

private:
	cocos2d::Label *label;
	cocos2d::Sprite *spaceship;	
	cocos2d::Sprite *monster1;
	cocos2d::Sprite *monster2;
	cocos2d::Sprite *monster3;
	cocos2d::Sprite *monster4;
	cocos2d::Sprite *monster5;
	cocos2d::Vector<cocos2d::Sprite*> _m5List;
	cocos2d::Vector<cocos2d::Sprite*> _m4List;
	cocos2d::Vector<cocos2d::Sprite*> _m3List;
	cocos2d::Vector<cocos2d::Sprite*> _m2List;
	cocos2d::Vector<cocos2d::Sprite*> _m1List;

	int _nextShipLaser;
	int score;
	
	int direction5;
	int direction4;
	int direction3;
	int direction2;
	int direction1;
	int f1 = 222;
	int f2 = 222;
	int f3 = 222;
	int f4 = 222;
	int f5 = 222;

	int altFrames5;
	int altFrames4;
	int altFrames3;
	int altFrames2;
	int altFrames1;
	int randVal;
	bool goDown = false;
	bool goReverse = false;

	float _shipPointsPerSecY;

	cocos2d::PhysicsWorld *sceneWorld;
	void SetPhysicsWorld(cocos2d::PhysicsWorld *world) { sceneWorld = world; };
};


#endif // __HELLOWORLD_SCENE_H__
