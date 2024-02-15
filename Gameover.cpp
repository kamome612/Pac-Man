#include "Gameover.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

GameoverScene::GameoverScene(GameObject* parent)
	:GameObject(parent,"Gameover"),goPict_(-1)
{
}

void GameoverScene::Initialize()
{
	//画像データのロード
	goPict_ = Image::Load("Picture\\GAMEOVER.jpg");
	assert(goPict_ >= 0);
}

void GameoverScene::Update()
{
	XMFLOAT3 mouse;
	mouse = Input::GetMousePosition();
	if (Input::IsMouseButtonDown(0))
	{
		if (mouse.y >= 430 && mouse.y <= 530) {
			if (mouse.x >= 230 && mouse.x <= 550) {
				SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
				pSceneManager->ChangeScene(SCENE_ID_TITLE);
			}
			else if (mouse.x >= 735 && mouse.x <= 1055) {
				exit(1);
			}
		}
	}
}

void GameoverScene::Draw()
{
	Image::SetTransform(goPict_, transform_);
	Image::Draw(goPict_);
}

void GameoverScene::Release()
{
}
