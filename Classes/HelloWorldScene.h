#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Bullet.h"
#include "Player.h"
#include "GameSystem.h"

static const int MAX_ENEMY = 5;
class HelloWorld : public cocos2d::Layer
{
private:
	void spawnEnemy();
	Bullet* _pPredator[MAX_ENEMY];
	Player* _pPlayer;
	GameSystem* _pGs;
	cocos2d::Camera* _pCamera;


	cocos2d::Size _visibleSize;

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
		
	void update(float dt)override;

	//bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	//void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	// implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
