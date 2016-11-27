#include "MyCamera.h"

USING_NS_CC;

MyCamera* MyCamera::create()
{
	auto camera = new(std::nothrow) MyCamera();
	if (camera && camera->init())
	{
		camera->initDefault();
		camera->autorelease();
		camera->setDepth(0.f);
		return camera;
	}
	CC_SAFE_DELETE(camera);
	return nullptr;

}

bool MyCamera::init()
{
	if (!Camera::init())
	{
		return false;
	}

	this->scheduleUpdate();
	return true;
}

void MyCamera::update(float dt)
{

}
