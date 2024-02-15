#include "PlayScene.h"
#include "Stage.h"
#include "Engine/Camera.h"
#include "Player.h"
#include "Gauge.h"
#include "Cookie.h"
#include "Engine/SceneManager.h"

namespace {
	const int COOKIE_NUM{ 10 };
}

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
	for (int i = 0; i < COOKIE_NUM; i++) {
		Cookie* pCookie=Instantiate<Cookie>(this);
		pCookie->SetPosition(XMFLOAT3{ (float)(1 * i + 1.5),0.3,2.5 });
	}
	//Instantiate<Cookie>(this);
}

void PlayScene::Update()
{
	if (FindObject("Cookie") == nullptr) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
