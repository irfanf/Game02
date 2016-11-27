#pragma once
#include "cocos2d.h"
#include "Player.h"
#include "GameSystem.h"

class MyCamera : public cocos2d::Camera
{
private:
	cocos2d::Camera* _pCamera;
	Player* _pPlayer;
	GameSystem* _pGameSystem;
	
public:
	static MyCamera* create();
	virtual bool init();
	void update(float dt)override;
	void setCameraTarget(Player* player, GameSystem* gs) { }


};

