#include "TitleScene.h"
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
//-------------------------------------------
USING_NS_CC;
using namespace cocostudio::timeline;
//-------------------------------------------
const float BG_SPEED = 10.0f;
const float TIME_CONVERTER = 60.0f;
const int MAX_OPACITY = 200;
//------------------------------------
//@! �N���X�쐬
//------------------------------------
Scene* TitleScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TitleScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
//------------------------------------
//@! �N���X�̏�����
//------------------------------------
bool TitleScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//��ʃT�C�Y
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//������
	_time = 0;
	_opacity = 0;
	_startOpacity = 0;

	//�^�b�`������ړ�
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//�Q�[���^�C�g��
	_titleName = Sprite::create("titleName.png");
	//_titleName->setAnchorPoint(Vec2::ZERO);
	_titleName->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 50);
	_titleName->setOpacity(_opacity);
	this->addChild(_titleName);

	//�Q�[���X�^�[�g
	_start = Sprite::create("gameStart.png");
	_start->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 150);
	_start->setOpacity(_startOpacity);
	this->addChild(_start);

	//�p�[�e�B�N���G�t�F�N�g
	CCParticleSystemQuad* par = CCParticleSystemQuad::create("title_par.plist");
	par->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(par);

	//�X�V
	this->scheduleUpdate();

	return true;
}
//------------------------------------
//@! �X�V
//@! ����
//------------------------------------
void TitleScene::update(float dt)
{
	//���ԃJ�E���g
	_time++;

	if (_time >= (3.0f * TIME_CONVERTER))
	{
		//�^�C�g���̓���
		if (_opacity <= MAX_OPACITY)_opacity++;
		_titleName->setOpacity(_opacity);
	}

	if (_time >= (4.0f * TIME_CONVERTER))
	{
		//Blink
		_startOpacity += 4.0f;
		_start->setOpacity(_startOpacity);
	}
}

//------------------------------------
//@! �N���b�N������ړ�
//@! �^�b�`�A�C�x���g
//------------------------------------
bool TitleScene::onTouchBegan(Touch* touch, Event* unused_event)
{

	//�ړ���V�[���̍쐬
	auto scene = HelloWorld::createScene();
	auto transition = TransitionTurnOffTiles::create(1.0f, scene);
	Director::getInstance()->replaceScene(transition);

	this->unscheduleAllSelectors();

	return false;
}