#include "PlayScene.h"
#include "Stage.h"
#include "Engine/Camera.h"
#include "Player.h"
#include "Gauge.h"
#include "Cookie.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	//ステージをInstantiateするよ
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	Instantiate<Gauge>(this);
	Instantiate<Cookie>(this);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
