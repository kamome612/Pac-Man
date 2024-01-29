#include "PlayScene.h"
#include "Stage.h"
#include "Engine/Camera.h"
#include "Player.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	//ステージをInstantiateするよ
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	Camera::SetPosition(XMFLOAT3(6.5, 10, -5));
	Camera::SetTarget(XMFLOAT3(6.5, 0, 5.5));
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
